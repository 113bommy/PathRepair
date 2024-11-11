#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans=0;
ll x,y;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  ans+=i*(n-i+1);
    for(int i=1;i<n;i++)
    {
       scanf("%lld%lld",&x,&y);
	   if(x>y)  swap(x,y);
	   ans-=u*(n-v+1);  	
	}
	cout<<ans<<endl;
	return 0;
}