#include<bits/stc++.h>
using namespace std;
#define ll long long
int main()
{
ll n;cin>>n;ll a[n];ll ans = 0;
for(int i = 0;i<n;i++){cin>>a[i];ll cnt = 0;while(a[i]%2==0){a[i]/=2;cnt++;}ans+=cnt;}
cout<<ans;
return 0;
}