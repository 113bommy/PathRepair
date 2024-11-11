#include <cstdio>
ing gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main()
{
	int x;scanf("%d",&x);
  	printf("%d",360/gcd(x,360));
  	return 0;
}