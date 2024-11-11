#include<stdio.h>
int main(){
int s[9000],n,m,t,f,i;
while(scanf("%d%d",&n,&m),i=0,t=f=1,n)
	while(++i<=n+m)
		if(scanf("%d",&s[i]),i>n)if(t+=s[t+=s[i]],t>=n&f==1)
			printf("%d\n",i-n,f=0);
	
}