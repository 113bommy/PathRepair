#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const long long INF = 1e18;
int n, m;
long long row[MAXN], col[MAXN];
long long dpRow[MAXN], dpCol[MAXN];
inline long long sqr(long long x) { return x * x; }
void init() {
  scanf("%d%d", &n, &m);
  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  for (int i = 1; i <= n; ++i)
    for (int j = 1, c; j <= m; ++j) {
      scanf("%d", &c);
      row[i] += c;
      col[j] += c;
    }
}
int ABS(int x, int y) {
  if (y > x)
    return y - x - 1;
  else
    return x - y;
}
void solve() {
  for (int i = 0; i <= n; ++i) {
    dpRow[i] = 0;
    for (int j = 1; j <= n; ++j) {
      int dif = 4 * ABS(i, j) + 2;
      dpRow[i] += row[j] * sqr(dif);
    }
  }
  for (int i = 0; i <= m; ++i) {
    dpCol[i] = 0;
    for (int j = 1; j <= m; ++j) {
      int dif = 4 * ABS(i, j) + 2;
      dpCol[i] += col[j] * sqr(dif);
    }
  }
  long long ans = INF, ansi, ansj;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j) {
      if (dpRow[i] + dpCol[j] < ans) {
        ans = dpRow[i] + dpCol[j];
        ansi = i;
        ansj = j;
      }
    }
  cout << ans << endl;
  cout << ansi << ' ' << ansj << endl;
}
int main() {
  init();
  solve();
  return 0;
}
