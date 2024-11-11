#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001],ans=1e9,sum;
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
for(int i=1;i<=n-k+1;i++)
{
sum=a[i+k-1]-a[i];
ans=min(sum,ans);
}
cout<<ans<<endl;
return 0;
}