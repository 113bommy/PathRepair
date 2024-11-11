#include<cstdio>
int main()
{
	long long int a,b,i,ss=10000,s;
	scanf("%lld%lld",&a,&b);
	 if(b/2019>a/2019)
	printf("0\n");
	else
	{
	for(i=a;i<b;i++)
	for(j=i+1;j<b;j++)
	{
		s=(i*j)%2019;
		if(s<ss)
		ss=s;
	}
	printf("%lld",ss);
}
}