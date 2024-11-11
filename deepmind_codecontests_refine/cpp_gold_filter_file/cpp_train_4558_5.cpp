#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans=0;
ll x,y;
int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)  ans+=i*(n-i+1);
    for(int i=1;i<n;i++)
    {
       scanf("%lld%lld",&x,&y);
	   if(x>y)  swap(x,y);
	   ans-=x*(n-y+1);  	
	}
	cout<<ans<<endl;
	return 0;
}