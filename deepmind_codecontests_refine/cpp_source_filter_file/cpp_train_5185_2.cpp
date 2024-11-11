#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
int main(){
  int n, d; cin >> n >> d;
  int x[n][d];
  rep(i, n) rep(j, d) cin >> x[i][j];
  int ans = 0;
  double g = 0;
  rep(i,n-1){
    for(int j=i+1; j＜n; j++){
      g = 0;
      rep(k,d){
        g += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      }
      g = sqrt(g);
      rep(i, sqrt(16000)+1) if(g == i) ans++;
    }
  }
  cout << ans << endl;
}