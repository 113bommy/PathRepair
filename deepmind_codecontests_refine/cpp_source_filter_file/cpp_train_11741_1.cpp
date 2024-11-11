#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    int i;
    ll A[n+1];
    for(i=0;i<=n;i++)
    cin>>A[i];
    ll B[n+1];
    ll ans=0;
    B[n]=A[n];
    for(i=n-1;i>=0;i--)
    B[i]=B[i+1]+A[i];
    B[0]=1;
    for(i=1;i<n;i++)
    {
        B[i]=min(B[i],2(*B[i-1]-*A[i-1]));
    }
    for(i=0;i<=n;i++)
    {
        if(B[i]<A[i])
        {
            ans=-1;
            break;
        }
        ans+=B[i];
    }
    cout<<ans<<"\n";
    return 0;
}