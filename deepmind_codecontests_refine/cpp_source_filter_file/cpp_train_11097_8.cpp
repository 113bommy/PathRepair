#include <bits/stdc++.h>
inline int in() {
  int k = 0;
  char ch = getchar();
  bool p = 1;
  while (ch < '-') ch = getchar();
  if (ch == '-') ch = getchar(), p = 0;
  while (ch > '-') k = k * 10 + ch - '0', ch = getchar();
  return p ? k : -k;
}
const int N = 55, YL = 1e9 + 7;
inline int MO(const int &x) { return x >= YL ? x - YL : x; }
inline void add(int &x, int y) {
  if ((x += y) >= YL) x -= YL;
}
inline void dec(int &x, int y) {
  if ((x -= y) < 0) x += YL;
}
int sn[N], sm[N], sk[N], tot, pw[N];
std::pair<int, int> dp[N][2][2][2];
int o[N][2][2][2];
std::pair<int, int> dfs(int d, int a, int b, int c) {
  if (d == -1) return std::make_pair(0, 1);
  if (o[d][a][b][c]) return dp[d][a][b][c];
  o[d][a][b][c] = 1;
  std::pair<int, int> &res = dp[d][a][b][c];
  res = std::make_pair(0, 0);
  int ma = a ? 1 : sn[d], mb = b ? 1 : sm[d], mc = c ? 1 : sk[d], k;
  for (int i = 0; i <= ma; ++i)
    for (int j = 0; j <= mb; ++j)
      if ((k = (i ^ j)) <= mc) {
        std::pair<int, int> ret =
            dfs(d - 1, i < ma || a, j < mb || b, k < mc || c);
        add(res.second, ret.second);
        add(res.first, ret.first);
        if (!k) continue;
        res.first = (1ll * ret.second * pw[d] + res.first) % YL;
      }
  return res;
}
int calc(int n, int m, int k) {
  if (n < 0 || m < 0 || k < 0) return 0;
  memset(o, 0, sizeof o);
  tot = -1;
  while (n || m || k)
    sn[++tot] = n & 1, sm[tot] = m & 1, sk[tot] = k & 1, n >>= 1, m >>= 1,
    k >>= 1;
  return dfs(tot, 0, 0, 0).first + dfs(tot, 0, 0, 0).second;
}
int main() {
  for (int i = pw[0] = 1; i <= 31; ++i) pw[i] = MO(pw[i - 1] << 1);
  for (int t = in(); t; --t) {
    int x1 = in() - 1, y1 = in() - 1, x2 = in() - 1, y2 = in() - 1,
        k = in() - 1, ans = 0;
    add(ans, calc(x2, y2, k));
    add(ans, calc(x1 - 1, y1 - 1, k));
    dec(ans, calc(x2, y1 - 1, k));
    dec(ans, calc(x1 - 1, y2, k));
    printf("%d\n", ans);
  }
  return 0;
}
