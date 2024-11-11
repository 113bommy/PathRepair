#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[200001],b[200001];
int main()
{
	ll n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	sort(a,a+n,less<int>());
	sort(b,b+n,greater<int>());
	ll y=-1;
	for(int i=0;i<n;i++)
	{
		y=max(a[i]*b[i],y);
	}
	ll x=0;
	ll time=0;
	while(x<y)
	{
		ll m=x+(y-x)/2;
		ll flag=1;
		ll tmpk=0;
		time++;
		for(int i=0;i<n;i++)
		{
			ll res=m/b[i];
			if(res>a[i])continue;
			tmpk+=a[i]-res;
			if(tmpk>k){
			flag=0;
			break;}
		}
		if(flag)y=m;
		else x=m+1;
	}
	cout<<x
	return 0;
}