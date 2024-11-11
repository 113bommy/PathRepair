#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)  for(int i=0;i<(n);i++)

int main(){
int n,m,x;
cin >> n >> m >> x;

int a[15],cost;
int inf = 1100000000;
int ans = inf;

int v[15][15];

rep(i,n){
  rep(j,m+1) cin >> v[i][j];
}


rep(bit,1<<n){
  int cost =0;
  vector<int> d(m);
  rep(i,n){
    if(bit&1<<i){
      cost +=v[i][0];
      rep(j,m) d[j]+=v[i][j+1];
    }
  }
  bool ok = true;
  rep(i,m){
    if(d[i]<x) ok = false;
  }
  if(ok) ans = min(cost,ans);
 

}

if(ans == inf) cout << -1 <<endl;
else cout << ans << endl;
return 0;
}