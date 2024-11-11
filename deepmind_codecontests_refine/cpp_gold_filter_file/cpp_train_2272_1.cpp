#include <bits/stdc++.h>
#define int long long
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main(){
  int n,c,ans=1e9;
  cin>>n>>c;
  int a[n][n],d[c][c];
  int s[3][c];
 
  r(i,3)r(j,c)s[i][j]=0;
 
  r(i,c)r(j,c)cin>>d[i][j];
  r(i,n)r(j,n)cin>>a[i][j],a[i][j]--;
 
  r(i,n)r(j,n)s[(i+j)%3][a[i][j]]++;
  r(i,c)r(j,c)if(i!=j)r(k,c)if(i!=k&&j!=k){
    int sum=0;
    r(l,c){
      sum+=d[l][i]*s[0][l];
      sum+=d[l][j]*s[1][l];
      sum+=d[l][k]*s[2][l];
    }
    ans=min(ans,sum);
  }
  cout<<ans<<endl;
}