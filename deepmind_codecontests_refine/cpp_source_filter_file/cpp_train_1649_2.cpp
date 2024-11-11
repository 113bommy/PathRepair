#include<iostream>
using namespace std;
int n,s[3][105],x,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=n;j++)
            cin>>x,s[i][j]=s[i][j-1]+x;
    for(int i=1;i<=n;i++)
        ans=max(ans,s[1][i]+s[2][n]-s[2][i-1]);
    cout<<ans<<endl;
    return 0;
