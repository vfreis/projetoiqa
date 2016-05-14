#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/****************************************************************************
*OX  - Oxigênio Dissolvido													*
*CF  - Coliformes Fecais													*
*ph  - Potencial Hidrogeniônico												*
*dbo - Demanda Bioquimica de Oxigênio (DBO = 5,20)							*
*nt  - Nitrogênio Total														*
*ft  - Fosforo Total														*	
*st  -																		*
*dt  -																		*
*    - Temperatura															*
*****************************************************************************
*sg - soma geral das variavels acima (verificar utilidade)				    *
*produtorio - fatorial de cada elemento (verificar utilidade)				*
*****************************************************************************/

int main(void)
{
    int ox, cf, ph, dbo, ft, nt, tu, dt, st, sg, produtorio;

    //Ponteiro indicando a variavel que vai abrir o arquivo txt
    FILE *iqa;

    //Abertura do arquivo txt o "r" representa reading, indicando que irá somente ler o arquivo
    iqa = fopen("iqa.txt", "r");

    //Leitura do arquivo txt
    fscanf(iqa,"%d %d %d %d %d %d %d %d %d", &ox, &cf, &ph, &dbo, &ft, &nt, &tu, &dt, &st);

    //Fechamento do arquivo txt
    fclose(iqa);		

    system("pause");
    return 0;
}

/************************************************
*											   	*
*			Começo das funções 					*
*												*
************************************************/

//provisorio
int cf=1;

int q1 (int cf) //Coliformes fecais
{
	double a = 98.03, b = -36.45, c = 3.138, d = 0.06776;

	q1 = a + (b * (log(cf))) + (c * pow((log10(cf)), 2)) + (d * pow((log10(cf)), 3));
}
int q2 (int ph) //Potencial Hidrogeniônico
{
	double a = 0.05421, b = 1.23, c = - 0.09873, q2 = 0.0;

	q2 = a * pow(ph, ((b * ph) - (c * pow(ph,2)))) + 5.231;
}
int q3 (int dbo) //Demanda Bioquimica de Oxigenio
{
	double a = 102.6, b = -0.01101, q3;

	q3 = a * exp (b* dbo);
}
int q4 (int nt) //Nitrogenio Total
{
	double a = 98.96, b = -0.2232, c = -0.006457, q4;

	q4 = a * pow(nt, (b + (c * nt)));
}
int q5 (int ft) //Fosforo Total
{
	double a = 213.7, b = -1.680, c = 0.3325, q5;

	q5 = a * exp(b * pow(cf, c));
}
int q6 (int dt)
{
	double a = 0.0003869, b = 0.1815, c = 0.01081, q6;

	q6 = 1 / (a * pow(dt + b, 2)+c);
}
int q7 (int tu)
{
	double a = 97.34, b = -0.0139, c = -0.04917, q7;

	q7 = a * exp ((b * tu)+ (c * sqrt(tu)));
}
int q8 (int st)
{
	double a = 80.26, b = -0.00107, c = 0.03009, d = -0.1185, q8;

	q8 = (a * exp((b * st) + (c * sqrt(st)))) + (d * st);
}
int q9 (int ox) //função da oxigênio dissolvido
{
	double a = 100.8, b = -106.0, c = -3745.0, q9;

	q9 = a * exp (pow((ox + b), 2)/ c);
}