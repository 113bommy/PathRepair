#include <iostream>
#include <cstdio>
using namespace std;
int n,a[200005];
ll ans;
int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		if (i==1 && a[i]) return (int)puts("-1")*0;
		else if (a[i]==a[i-1]+1) ans++;
		else if (a[i]<a[i-1]+1) ans+=a[i];
		else if (a[i]>a[i-1]+1) return (int)puts("-1")*0;
	}
	cout<<ans<<endl;
}