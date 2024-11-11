#include "cstdio"
int i,j,n,m,ss,sss;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			char c=getchar();
			if(c=='#')ss++;
		}
	}
	if(ss!=n+m-1)printf("Impossible\n");
	else printf("Possible\n");
	returnn 0;
}