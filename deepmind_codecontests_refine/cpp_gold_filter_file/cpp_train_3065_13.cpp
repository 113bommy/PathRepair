#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int INF = 1e8 + 7;
const int MOD = 1e9 + 7;
const long long LINF = 1e17 + 7;
const double Pi = acos(-1.);
const double EPS = 1e-8;
vector<int> b[N];
int n, m, s, e, a[N], f[N][301];
int calc(int pos, int val) {
  int nxt = upper_bound(b[val].begin(), b[val].end(), pos) - b[val].begin();
  return nxt == ((int)(b[val].size())) ? INF : b[val][nxt];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &e);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    b[x].push_back(i);
  }
  int MJ = s / e;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= MJ; ++j) f[i][j] = INF;
  f[0][0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= min(i, MJ); ++j)
      if (f[i][j] < m) {
        f[i + 1][j] = min(f[i + 1][j], f[i][j]);
        f[i + 1][j + 1] = min(f[i + 1][j + 1], calc(f[i][j], a[i + 1]));
      }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= min(i, MJ); ++j)
      if (i + f[i][j] + j * e <= s) {
        ans = max(ans, j);
      }
  printf("%d\n", ans);
  return 0;
}
