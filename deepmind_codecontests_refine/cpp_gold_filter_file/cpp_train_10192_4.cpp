#include<stdio.h>
int main(void)
{
	int a,b,c,d,e,m,n,ans;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	if(a<=b&&a<=c){
		m=a-25;
	}
	else if(b<=a&&b<=c){
		m=b-25;
	}
	else{
		m=c-25;
	}
	if(d<=e){
		n=d-25;
	}
	else{
		n=e-25;
	}
	ans=m+n;
	printf("%d\n",ans);
	return 0;
}
