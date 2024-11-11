#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
const int MAXQ = 100010;
const double EPS = 1e-10;
const double DINF = 1e30;
const int IINF = ~0U >> 3;
const long long LINF = 1LL << 61;
void debug() { cout << "error_here" << endl; }
char str[MAXN][MAXN];
int a[MAXN][MAXN], b[MAXN][MAXN];
int n, m, k;
void init() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) scanf("%s", str[i]);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][j] = (str[i - 1][j - 1] == '1');
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] && a[i - 1][j] && a[i + 1][j] && a[i][j - 1] && a[i][j + 1])
        b[i][j] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
}
int get_sum(int x, int y, int xx, int yy) {
  return b[xx][yy] - b[xx][y - 1] - b[x - 1][yy] + b[x - 1][y - 1];
}
void solve() {
  long long ans = 0;
  for (int u = 1; u <= n; ++u)
    for (int v = u + 2; v <= n; ++v) {
      for (int i = 1, j = 3; i <= n && j <= n;) {
        if (get_sum(u + 1, i + 1, v - 1, j - 1) >= k)
          ans += m - j + 1, i++;
        else
          j++;
      }
    }
  cout << ans << endl;
}
int main() {
  init();
  solve();
  return 0;
}
