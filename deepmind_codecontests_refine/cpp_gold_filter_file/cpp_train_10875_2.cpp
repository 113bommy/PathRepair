#include <bits/stdc++.h>
using namespace std;
void solveA() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<vector<int>> v(n);
  for (int i = 0; i < int(n); i++) v[i].resize(m);
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(m); j++) {
      int t;
      cin >> t;
      v[i][j] = t;
    }
  int a, b;
  cin >> a;
  cin >> b;
  int res = 1000000000;
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(m); j++) {
      if (i + a <= n && j + b <= m) {
        int cur = 0;
        for (int i1 = 0; i1 < int(a); i1++)
          for (int j1 = 0; j1 < int(b); j1++) {
            cur += v[i + i1][j + j1];
          }
        res = min(cur, res);
      }
    }
  swap(a, b);
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(m); j++) {
      if (i + a <= n && j + b <= m) {
        int cur = 0;
        for (int i1 = 0; i1 < int(a); i1++)
          for (int j1 = 0; j1 < int(b); j1++) {
            cur += v[i + i1][j + j1];
          }
        res = min(cur, res);
      }
    }
  cout << res << endl;
}
int main() { solveA(); }
