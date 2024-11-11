#include <bits/stdc++.h>
using namespace std;
const int HashMod = 1125022017;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int oo = 1e9;
const int nmax = 1e2 + 9;
int n, m;
int a[nmax][nmax];
int h[nmax];
int c[nmax];
int cnt = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  if (n < m) {
    for (int i = 1; i <= n; i++) {
      h[i] = oo;
      for (int j = 1; j <= m; j++) h[i] = min(h[i], a[i][j]);
      for (int j = 1; j <= m; j++) a[i][j] -= h[i];
      cnt += h[i];
    }
    for (int j = 1; j <= m; j++) {
      c[j] = oo;
      for (int i = 1; i <= n; i++) c[j] = min(c[j], a[i][j]);
      for (int i = 1; i <= n; i++) a[i][j] -= c[j];
      cnt += c[j];
    }
  } else {
    for (int j = 1; j <= m; j++) {
      c[j] = oo;
      for (int i = 1; i <= n; i++) c[j] = min(c[j], a[i][j]);
      for (int i = 1; i <= n; i++) a[i][j] -= c[j];
      cnt += c[j];
    }
    for (int i = 1; i <= n; i++) {
      h[i] = oo;
      for (int j = 1; j <= m; j++) h[i] = min(h[i], a[i][j]);
      for (int j = 1; j <= m; j++) a[i][j] -= h[i];
      cnt += h[i];
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j] != 0) {
        cout << -1;
        return 0;
      }
  cout << cnt << endl;
  for (int i = 1; i <= n; i++)
    while (h[i] > 0) {
      cout << "row " << i << "\n";
      h[i] -= 1;
    }
  for (int j = 1; j <= m; j++)
    while (c[j] > 0) {
      cout << "col " << j << "\n";
      c[j] -= 1;
    }
  return 0;
}
