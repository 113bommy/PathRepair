#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, ans;
int a[34][34], t[34][34], b[20];
int g(int x, int y) { return t[x][y] ? -a[x][y] : a[x][y]; }
int kkk(int x, int y, int b) {
  t[x][y] = b;
  t[x + m][y] = t[x][y] ^ t[m][y];
  t[x][y + m] = t[x][y] ^ t[x][m];
  t[x + m][y + m] = t[x][y + m] ^ t[m][y + m];
  int r = g(x, y) + g(x + m, y) + g(x, y + m) + g(x + m, y + m);
  return r;
}
int kk(int y, int b) {
  t[m][y] = b;
  t[m][y + m] = t[m][y] ^ t[m][m];
  int r = g(m, y) + g(m, y + m);
  for (int i = 1; i < m; i++) {
    r += max(kkk(i, y, 0), kkk(i, y, 1));
  }
  return r;
}
int k() {
  int r = 0;
  for (int i = 1; i <= n; i++) {
    r += g(i, m);
  }
  for (int i = 1; i < m; i++) {
    r += max(kk(i, 0), kk(i, 1));
  }
  return r;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  m = (n + 1) >> 1;
  ans = -inf;
  b[1] = 1;
  for (int i = 2; i <= m + 1; i++) {
    b[i] = b[i - 1] << 1;
  }
  for (int j = 0; j < b[m + 1]; j++) {
    for (int i = 1; i <= m; i++) {
      t[i][m] = ((j & b[i]) == 0 ? 0 : 1);
    }
    for (int i = m + 1; i <= n; i++) {
      t[i][m] = t[i - m][m] ^ t[m][m];
    }
    ans = max(ans, k());
  }
  cout << ans << endl;
  return 0;
}
