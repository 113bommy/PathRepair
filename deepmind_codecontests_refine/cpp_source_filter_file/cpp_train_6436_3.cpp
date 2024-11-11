#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,m,a,b,c,e=-10000000000000000;
  cin>>n>>m;
  vector<vector<ll>> v(8,vector<ll>(n));
  int d[8][3]={{1,1,1},{1,1,-1},{1,-1,1},{-1,1,1},{1,-1,-1},{-1,1,-1},{-1,-1,1},{-1,-1,-1}};
  for(int i=0;i<n;i++){
    cin>>a>>b>>c;
    for(int j=0;j<8;j++){
      v[j][i]=a*d[j][0]+b*d[j][1]+c*d[j][2];
    }
  }
  for(int i=0;i<8;i++){
    sort(v[i].begin(),v[i].end(),greater());
    ll f=0;
    for(int j=0;j<m;j++){
      f+=v[i][j];
    }
    e=max(e,f);
  }
  cout<<e;
}