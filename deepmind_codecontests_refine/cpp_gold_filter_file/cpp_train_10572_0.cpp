#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 1100;
short f[N][N], a[N][N];
int n, m, q, l, r, mid, a1, b1, a2, b2, ans;
namespace ST_2D {
int LOG[N], P[20], dep1, dep2;
short st[11][11][N][N];
void build(short a[][N]) {
  for (int i = 0; i < 11; i++) P[i] = 1 << i;
  for (int i = 2; i < 1025; i++) LOG[i] = LOG[i >> 1] + 1;
  for (dep1 = 0; (1 << dep1) < n; dep1++)
    ;
  for (dep2 = 0; (1 << dep2) < m; dep2++)
    ;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) st[0][0][i][j] = a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= dep2; j++)
      for (int k = P[j]; k <= m; k++)
        st[0][j][i][k] = max(st[0][j - 1][i][k], st[0][j - 1][i][k - P[j - 1]]);
  for (int i = 1; i <= dep1; i++)
    for (int j = P[i]; j <= n; j++)
      for (int k = 0; k <= dep2; k++)
        for (int l = P[k]; l <= m; l++)
          st[i][k][j][l] =
              max(st[i - 1][k][j - P[i - 1]][l], st[i - 1][k][j][l]);
}
int qry(int x1, int y1, int x2, int y2) {
  int len1 = x2 - x1 + 1, len2 = y2 - y1 + 1, l1, l2, res1, res2;
  l1 = LOG[len1];
  l2 = LOG[len2];
  res1 = max(st[l1][l2][x1 + P[l1] - 1][y1 + P[l2] - 1], st[l1][l2][x2][y2]);
  res2 = max(st[l1][l2][x1 + P[l1] - 1][y2], st[l1][l2][x2][y1 + P[l2] - 1]);
  return max(res1, res2);
}
}  // namespace ST_2D
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n >> m;
  for (int i = (1); i < (n + 1); i++)
    for (int j = (1); j < (m + 1); j++) cin >> a[i][j];
  for (int i = (1); i < (n + 1); i++)
    for (int j = (1); j < (m + 1); j++)
      if (a[i][j] == 0)
        f[i][j] = 0;
      else
        f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
  ST_2D ::build(f);
  cin >> q;
  for (int i = (1); i < (q + 1); i++) {
    cin >> a1 >> b1 >> a2 >> b2;
    l = 0;
    r = min(a2 - a1 + 1, b2 - b1 + 1);
    ans = 0;
    while (l <= r) {
      mid = l + r >> 1;
      if (ST_2D ::qry(a1 + mid - 1, b1 + mid - 1, a2, b2) >= mid) {
        ans = max(ans, mid);
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
