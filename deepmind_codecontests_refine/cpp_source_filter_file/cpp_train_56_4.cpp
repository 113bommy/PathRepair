#include <bits/stdc++.h>
using namespace std;
int n, m, r, c;
char a[405][405], b[405][405];
bitset<405> ans[405], G[26][405], aux[405];
inline void Shift() {
  for (int i = 0; i < 26; ++i)
    for (int j = 0; j < n; ++j) {
      int b = G[i][j][0];
      G[i][j] >>= 1;
      G[i][j][m - 1] = b;
    }
}
int main() {
  int i, j, x, y;
  cin >> n >> m;
  for (i = 0; i < n; ++i) cin >> a[i];
  cin >> r >> c;
  for (i = 0; i < r; ++i) cin >> b[i];
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) {
      G[a[i][j] - 'a'][i][j] = 1;
      ans[i][j] = 1;
    }
  for (y = 0; y <= 1; ++y) {
    for (x = 0; x < r; ++x) {
      if (b[x][y] == '?') continue;
      int val = b[x][y] - 'a';
      for (i = 0; i < n; ++i) ans[i] = (ans[i] & G[val][(i + x) % n]);
    }
    Shift();
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) cout << ans[i][j];
    cout << "\n";
  }
  return 0;
}
