#include<stdio.h>
int main(void)
{
	double h,m;
	int cMA,cHA;
	int cMB,cHB;
	int cMC,cHC;
	int cMD,cHD;
	cMA=0;
	cHA=0;
	cMB=0;
	cHB=0;
	cMC=0;
	cHC=0;
	cMD=0;
	cHD=0;
		while(scanf("%lf %lf",&h,&m)!=EOF){
			if(h>=1.1){
				cHA++;
			}
			else if(0.6<=h){
				cHB++;
			}
			else if(0.2<=h){
				cHC++;
			}
			else{
				cHD++;
			}
			if(m>=1.1){
				cMA++;
			}
			else if(0.6<=m m<1.1){
				cMB++;
			}
			else if(0.2<=m && m<0.6){
				cMC++;
			}
			else if(0.2>m){
				cMD++;
			}
		}
	printf("%d %d\n%d %d\n%d %d\n%d %d\n",cHA,cMA,cHB,cMB,cHC,cMC,cHD,cMD);
	return 0;
}