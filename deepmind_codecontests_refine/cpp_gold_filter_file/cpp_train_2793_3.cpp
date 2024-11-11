#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100005;
long long a[MAXN];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",a+i);
	long long mn=2,mx=2;
	for(int i=n;i>0;--i){
		mn=(mn-1)/a[i]*a[i]+a[i];
		mx=mx/a[i]*a[i]+a[i]-1;
		if(mn>mx){
			puts("-1");
			return 0;
		}
	}
	cout<<mn<<" "<<mx<<endl;
	return 0;
}
