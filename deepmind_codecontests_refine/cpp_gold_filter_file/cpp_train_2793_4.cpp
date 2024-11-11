#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const long long N=100005;
long long n,a[N],l=2,r=2;
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(long long i=n;i>=1;i--)
	{
		l=(l+a[i]-1)/a[i]*a[i],r=(r/a[i]+1)*a[i]-1;
		//cout<<l<<" "<<r<<endl;
	}
	if(l>r)
		puts("-1");
	else
		printf("%lld %lld\n",l,r);
	return 0;
}