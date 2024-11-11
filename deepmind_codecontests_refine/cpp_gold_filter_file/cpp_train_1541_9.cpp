#include<cstdio>
int main(){
	int a,b,c,d;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		if(a+b+c<=21)
		printf("win\n");
		else
		printf("bust\n");
	}
}