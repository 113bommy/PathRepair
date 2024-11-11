#include <bits/stdc++.h>
using namespace std;
const int N = 4010;
int n, m, a[N], rt, tot, L[N], siz[N], R[N], ls[N], rs[N];
long long val[N], dp[N][N];
inline void build(int &p, int l, int r) {
  if (l > r) return;
  p = ++tot;
  int pos = l;
  for (int i = l; i <= r; ++i)
    if (a[i] < a[pos]) pos = i;
  val[p] = a[pos];
  build(ls[p], l, pos - 1);
  build(rs[p], pos + 1, r);
  dp[p][0] = 0;
  dp[p][1] = m * val[p] - val[p];
  siz[p] = 1;
  for (int i = siz[p]; i >= 0; --i)
    for (int j = 0; j <= siz[ls[p]]; ++j)
      dp[p][i + j] =
          max(dp[p][i + j], dp[p][i] + dp[ls[p]][j] - 2ll * i * j * val[p]);
  siz[p] += siz[ls[p]];
  for (int i = siz[p]; i >= 0; --i)
    for (int j = 0; j <= siz[rs[p]]; ++j)
      dp[p][i + j] =
          max(dp[p][i + j], dp[p][i] + dp[rs[p]][j] - 2ll * i * j * val[p]);
  siz[p] += siz[rs[p]];
}
int main() {
  memset(dp, -0x3f, sizeof(dp));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  build(rt, 1, n);
  printf("%d\n", dp[1][m]);
  return 0;
}
