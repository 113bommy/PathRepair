#include <bits/stdc++.h>
using namespace std;
long long a,n,k;
int d[70][200001],i,j,g;
int main()
{
    cin>>n>>k;
    for(i=0;i<n;++i)
	{
    	cin>>a;
    	d[0][i]=a-1;
    }
    for(i=0;i<=60;++i)
    	for(j=0;j<n;++j)d[i+1][j]=d[i][d[i][j]];
    for(i=0;i<=60;++i)if(k&(1LL<<i))g=d[i][now];
    cout<<g+1;
    return 0;
}