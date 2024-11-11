#include<bits/stdc++.h>
using namespace std;
int n;
long long f[87];
int main()
{
    cin>>n;
    f[0]=2;
    f[1]=1;
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    cout<<f[n];
}