#include <bits/stdc++.h>
using namespace std;
template <typename T>
void r1(T &x) {
  x = 0;
  char c(getchar());
  int f(1);
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) x = (x * 10) + (c ^ 48);
  x *= f;
}
const int maxn = 5e5 + 5;
const int maxk = 1e2 + 5;
const int maxp = 1e2 + 5;
const int maxm = maxn << 1;
const int inf = 0x3f3f3f3f;
int n, k, p;
int f[maxn][maxk], g[maxp], a[maxn], g1[maxp];
int sz;
struct Seg {
  int t[maxp << 2];
  int lowbit(int x) { return x & (-x); }
  void add(int pos, int c) {
    for (; pos <= sz; pos += lowbit(pos)) t[p] = max(t[p], c);
  }
  int ask(int pos) {
    int res(0);
    for (; pos; pos -= lowbit(pos)) res = max(res, t[pos]);
    return res;
  }
} T;
int sum[maxn], dp[maxn];
signed main() {
  int i, j;
  r1(n), r1(k), r1(p);
  for (i = 1; i <= n; ++i) r1(a[i]), a[i] %= p;
  if (k * p >= n) {
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (j = 1; j <= k; ++j) {
      for (i = 0; i < p; ++i) g[i] = inf;
      for (i = 1; i <= n; ++i) {
        for (int z = 0; z < p; ++z) g1[(a[i] + z) % p] = g[z];
        for (int z = 0; z < p; ++z) g[z] = g1[z];
        g[a[i]] = min(g[a[i]], f[i - 1][j - 1]);
        for (int z = 0; z < p; ++z) f[i][j] = min(f[i][j], g[z] + z);
      }
    }
    printf("%d\n", f[n][k]);
  } else {
    for (i = 1; i <= n; ++i) sum[i] = (sum[i - 1] + a[i]) % p;
    sz = 1;
    while (sz < p) sz *= 2;
    for (i = 1; i <= n; ++i) {
      dp[i] = T.ask(sum[i] + 1) + 1;
      T.add(sum[i] + 1, dp[i]);
    }
    if (dp[n] >= k)
      printf("%d\n", sum[n]);
    else
      printf("%d\n", sum[n] + p);
  }
  return 0;
}
