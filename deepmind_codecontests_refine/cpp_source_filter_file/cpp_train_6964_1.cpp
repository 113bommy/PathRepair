include<stdio.h>
#include<algorithm>
using namespace std;
int a[3000],b[3000],c[3001][3001];
int main(void)
{
	int n,s,t,i,j,m;
	scanf("%d %d %d",&m,&s,&t);
	for(i=0;i<m;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	for(i=0;i<=m;i++){
		for(j=0;j<=s;j++){
			c[i][j]=0;
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<=s;j++){
			if(j+b[i]<=s&&c[i+1][j+b[i]]<a[i]+c[i][j]&&(j+b[i]<=t||j>=t)){
				c[i+1][j+b[i]]=a[i]+c[i][j];
			}
			if(c[i+1][j]<c[i][j]){
				c[i+1][j]=c[i][j];
			}
		}
	}
/*	for(i=0;i<=m;i++){
		for(j=0;j<=s;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
*/	n=0;
	for(i=0;i<=s;i++){
		if(n<c[m][i]){
			n=c[m][i];
		}
	}
	printf("%d\n",n);
	return 0;
}