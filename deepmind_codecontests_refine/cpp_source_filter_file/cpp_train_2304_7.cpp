#include <bits/stdc++.h>
using namespace std;
long long read() {
  char c = getchar();
  long long flag = 1, ans = 0;
  while (c < '0' || c > '9') {
    if (c == '-') flag = -flag;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans * flag;
}
const long long INF = 1e18;
const long long mod = 1e9 + 7;
const int MAXN = 100010, MAXK = 205;
long long S[MAXK][MAXK], head[MAXN], dp[MAXN][MAXK], siz[MAXN], f[MAXN],
    ans[MAXK], fac[MAXK];
long long n, k, cnt;
long long add(long long a, long long b) {
  return (a + b >= mod) ? (a + b - mod) : (a + b);
}
long long sub(long long a, long long b) {
  return (a < b) ? (a + mod - b) : (a - b);
}
long long mul(long long a, long long b) { return a * b % mod; }
struct Edge {
  long long to;
  long long nxt;
} e[MAXN << 1];
void AddEdge(long long from, long long to) {
  e[++cnt].to = to;
  e[cnt].nxt = head[from];
  head[from] = cnt;
}
void init() {
  S[0][0] = 1, fac[0] = 1;
  for (long long i = 1; i <= k; ++i)
    for (long long j = 1; j <= i; ++j)
      S[i][j] = add(mul(j, S[i - 1][j]), S[i - 1][j - 1]);
  for (long long i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
}
void dfs(long long u, long long fa) {
  siz[u] = 1, dp[u][0] = 2;
  for (long long i = head[u]; i; i = e[i].nxt) {
    long long v = e[i].to;
    if (v == fa) continue;
    dfs(v, u);
    for (long long j = 0; j <= k; ++j) f[j] = 0;
    for (long long j = 0; j <= min(k, siz[u]); ++j)
      for (long long l = 0; l <= min(k - j, siz[v]); ++l)
        f[l + j] = add(f[l + j], mul(dp[u][j], dp[v][l]));
    for (long long j = 0; j <= k; ++j)
      dp[u][j] = f[j], ans[j] = sub(ans[j], dp[v][j]);
    siz[u] += siz[v];
  }
  for (long long i = 0; i <= k; ++i) ans[i] = add(ans[i], dp[u][i]);
  for (long long i = k; i; --i) dp[u][i] = add(dp[u][i], dp[u][i - 1]);
  dp[u][1] = sub(dp[u][1], 1);
}
int main() {
  n = read(), k = read();
  for (long long i = 1; i < n; ++i) {
    long long u = read(), v = read();
    AddEdge(u, v), AddEdge(v, u);
  }
  init();
  dfs(1, 0);
  long long sum = 0;
  for (long long i = 0; i <= k; ++i)
    sum = add(sum, mul(mul(S[k][i], fac[i]), ans[i]));
  printf("%lld\n", sum);
  return 0;
}
