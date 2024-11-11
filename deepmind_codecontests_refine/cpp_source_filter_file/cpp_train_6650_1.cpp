#include<stdio.h>
int main(void)
{
    int n,m,i,a;
	while(1){
	    scanf("%d %d",&n,&m);
		if(n==0&&m==0) break;
		a=0;
		if(n<m){
		i=n;
		n=m;
		m=i;
		while(1){
		    i=n%m;
			n=m;
			m=i;
			a++;
			if(m==0) break;
		}
		printf("%d %d\n",n,a);
	}
	return 0;
}