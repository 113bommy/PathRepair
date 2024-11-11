#include <bits/stdc++.h>
using namespace std;
long long  w[1001],v[1001],f[107][100007];

#define ll long long
#define F(i,a,b) for(long long i=a;i<=b;i++)

int main()
{
ll n,W,s=0;

cin>>n>>W;
F(i,1,n){   cin>>w[i]>>v[i]; s+=v[i]; }
F(i,1,s)f[0][i]=30000000000;
F(i,1,n)F(j,1,s)
{
   f[i][j]=f[i-1][j];
   if(j>=v[i])f[i][j]=min(f[i][j],f[i-1][j-v[i]]+w[i]);
}
for(i=s;i>=1;i--)
if(f[n][i]<=W){ cout<<i;  break;}
}
