#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 2e5 + 5;
const long long mod = 998244353;
inline long long read() {
  long long ans = 0;
  char ch = getchar(), last = ' ';
  while (!isdigit(ch)) last = ch, ch = getchar();
  while (isdigit(ch)) ans = (ans << 1) + (ans << 3) + ch - '0', ch = getchar();
  if (last == '-') ans = -ans;
  return ans;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void MYFILE() { freopen("random.in", "r", stdin); }
int n;
struct Edge {
  int nxt, to;
} e[maxn << 1];
int head[maxn], ecnt = -1;
inline void addEdge(int x, int y) {
  e[++ecnt] = (Edge){head[x], y};
  head[x] = ecnt;
}
int siz[maxn], tot[maxn];
long long dp[maxn], fac[maxn];
bool vis[maxn];
int cnt = 0;
inline void dfs(int now, int _f) {
  assert(++cnt <= n);
  assert(!vis[now]);
  vis[now] = 1;
  dp[now] = siz[now] = 1;
  for (int i = head[now], v; ~i; i = e[i].nxt) {
    if ((v = e[i].to) == _f) continue;
    ++tot[now];
    dfs(v, now);
    dp[now] = dp[now] * dp[v] % mod;
    siz[now] += siz[v];
  }
  dp[now] = dp[now] * fac[tot[now]] % mod;
  if (now ^ 1) dp[now] = dp[now] * (tot[now] + 1) % mod;
}
int main() {
  memset(head, -1, sizeof(head));
  fac[0] = 1;
  for (int i = 1; i < maxn; ++i) fac[i] = fac[i - 1] * i % mod;
  n = read();
  for (int i = 1; i < n; ++i) {
    int x = read(), y = read();
    addEdge(x, y), addEdge(y, x);
  }
  dfs(1, 0);
  write(dp[1] * n % mod), puts("");
  return 0;
}
