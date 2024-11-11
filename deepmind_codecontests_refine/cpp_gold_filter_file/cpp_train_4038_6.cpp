#include<iostream>
#include<vector>
const int INF=1001001001;
using namespace std;
int main(){
  int n,m,x;
  cin>>n>>m>>x;
  int c[n],a[n][m];
  for(int i=0;i<n;i++){
     cin>>c[i];
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  int ans=INF;
  for(int bit;bit<(1<<n);bit++){
    int cost=0;
    vector<int> d(m);
    for(int j=0;j<n;j++){
      if(bit>>j&1){
        cost+=c[j];
        for(int k=0;k<m;k++) d[k]+=a[j][k];
      }
    }
    bool ok=true;
    for(int j=0;j<m;j++) if(d[j]<x) ok=false;
    if(ok) ans=min(ans,cost);
  }
  if(ans==INF) cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}