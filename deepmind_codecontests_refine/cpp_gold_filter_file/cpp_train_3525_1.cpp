#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
inline LL gcd(LL a,LL b)
{
	return !b?a:gcd(b,a%b);
}

int main()
{
	int n;
	scanf("%d",&n);
	
	LL a,b,A=1,B=1;
	LL G;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&a,&b);
		if(a>A && b>B) A=a,B=b;
		else
		{
			G=max((A/a)+(A%a?1:0),B/b+(B%b?1:0));
			A=a*G,B=b*G;
		}
	}
	
	printf("%lld\n",A+B);
}