#include <cstdio>
using namespace std;

int main()
{
	long long int n,m;

	scanf("%lld%lld",&n,&m);
	if(n==1 || m==1)
	{
		printf("1");
		return 0:
	}

	printf("%lld",(n*m+1)/2);
}