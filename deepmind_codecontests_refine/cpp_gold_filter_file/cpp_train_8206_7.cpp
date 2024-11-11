#include<bits/stdc++.h>
using namespace std;
long long a[200010],ans[200010],sum,n,x,y;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i],sum+=a[i];
    x=a[0];
    y=sum-a[0];
    ans[0]=abs(x-y);
    for(int i=1;i<n-1;i++)
        x+=a[i],y-=a[i],ans[i]=abs(x-y);
    sort(ans,ans+n-1);
    cout<<ans[0]<<endl;
    return 0;
}