#include<iostream>
#include<cstdio>
using namespace std;
long long n,maxn,ans,x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ans+=max(maxn-x,0);
        maxn=max(maxn,x);
    }
    cout<<ans;
    return 0;
}