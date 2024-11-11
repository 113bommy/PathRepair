#include <bits/stdc++.h>
using namespace std;
const long long M = 250, N = (1 << 15), JYY = 1e9 + 7;
long long n, Ans = 1;
long long read() {
  long long x = 0, y = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') y = ch == '-' ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * y;
}
long long tot, top, cnt = 0, a[M], in[M], id[M], val[M], st[M], sz[N], dp[M][N],
                    C[M][M];
bool vis[M];
void Add(long long &x, long long y) { x = (x + y) % JYY; }
void dfs(long long u, long long rt) {
  id[u] = rt, tot++;
  if (in[u] == 0) st[top++] = u, vis[u] = 1;
  for (long long i = 1; i <= n; i++)
    if (!id[i] && (a[u] % a[i] == 0 || a[i] % a[u] == 0)) dfs(i, rt);
}
void solve() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read(), in[i] = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++)
      if (i != j && a[i] % a[j] == 0) in[i]++;
  for (long long i = 1; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (long long j = 1; j < i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % JYY;
  }
  for (long long l = 1; l <= n; l++) {
    if (id[l]) continue;
    top = 0, tot = 0;
    dfs(l, l);
    if (tot - top <= 1) continue;
    long long lim = (1 << top);
    for (long long i = 1; i <= n; i++) {
      if (id[i] != l || vis[i]) continue;
      val[i] = 0;
      for (long long j = 0; j < top; j++)
        if (a[i] % a[st[j]] == 0) val[i] |= (1 << j);
    }
    for (long long i = 0; i < lim; i++) {
      sz[i] = 0;
      for (long long j = 1; j <= n; j++)
        if (id[j] == l && !vis[j] && (i & val[j]) == val[j]) sz[i]++;
    }
    for (long long i = 1; i <= n; i++) {
      if (i <= tot - top)
        for (long long j = 0; j < lim; j++) dp[i][j] = 0;
      if (id[i] == l && !vis[i]) dp[1][val[i]]++;
    }
    for (long long i = 1; i < tot - top; i++)
      for (long long S = 0; S < lim; S++) {
        if (!dp[i][S]) continue;
        if (sz[S] > i) Add(dp[i + 1][S], dp[i][S] * (sz[S] - i) % JYY);
        for (long long j = 1; j <= n; j++) {
          if (id[j] != l || vis[j] || (S & val[j]) == val[j] || !(S & val[j]))
            continue;
          Add(dp[i + 1][S | val[j]], dp[i][S]);
        }
      }
    long long res = 0;
    tot = tot - top;
    for (long long i = 0; i < lim; i++) Add(res, dp[tot][i]);
    Ans = Ans * res % JYY * C[cnt + tot - 1][tot - 1] % JYY;
    cnt += tot - 1;
  }
  printf("%lld\n", Ans);
}
signed main() { solve(); }
