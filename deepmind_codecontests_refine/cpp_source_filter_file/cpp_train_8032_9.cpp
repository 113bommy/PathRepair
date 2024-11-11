#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void solve() {
  int w, h;
  cin >> w >> h;
  int g[w][h];
  int cnt = 0;
  for (int i = 0; i < w; i++) {
    string x;
    cin >> x;
    for (int j = 0; j < h; j++) {
      g[i][j] = x[j];
      if (x[j] == '*') cnt++;
    }
  }
  for (int i = 1; i < w - 1; i++) {
    for (int j = 1; j < h - 1; j++) {
      if (g[i][j] == '*' && g[i - 1][j] == '*' && g[i + 1][j] == '*' &&
          g[i][j - 1] == '*' && g[i][j + 1] == '*') {
        int nc = 0;
        for (int k = i + 1; k < w && g[k][j] == '*'; k++) nc++;
        for (int k = i - 1; k >= 0 && g[k][j] == '*'; k--) nc++;
        for (int k = j + 1; k < h && g[i][k] == '*'; k++) nc++;
        for (int k = i - 1; k >= 0 && g[i][k] == '*'; k--) nc++;
        if (nc + 1 == cnt) {
          cout << "YES" << endl;
          return;
        } else {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "NO" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  for (int i = 1, t = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
