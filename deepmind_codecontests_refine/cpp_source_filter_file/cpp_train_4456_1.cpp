#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int g[15][15];
int main () {
  int n;
  cin >> n;
  rep(i,n)rep(j,n) g[i][j] = -1;
  rep(i,n){
    int a;
    cin >> a;
    rep(j,a){
      int x, y;
      cin >> x >> y;
      x--;
      g[i][x] = y;
    }
  }
  int ans = 0;
  rep(i,1<<n){
    vector<int> d(n);
    rep(j,n) if(i>>j&1){
      d[j] = 1;
    }
    bool ok = true;
    rep(j,n){
      if(d[j]){
        rep(k,n){
          if(g[j][k] == -1) continue;
          if(g[j][k] != d[k]) ok = false;
        }
      }
    }
    if(ok) ans = max(ans, _builtin_popcount(i));
  }
  cout << ans << endl;
}