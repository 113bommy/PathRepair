#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; };
long long ksm(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans % mod;
}
const int maxn = 6e5 + 10;
int n;
struct Edge {
  int to, next;
  long long w;
} e[maxn << 1];
int head[maxn], cnt;
void add(int x, int y, long long id) {
  e[cnt].to = y;
  e[cnt].next = head[x];
  e[cnt].w = id;
  head[x] = cnt++;
}
int siz[maxn];
int L[maxn], R[maxn];
int id[maxn], rnk[maxn];
int son[maxn];
int dis[maxn], dep[maxn];
int ans[maxn];
int dp[1 << 23];
int tim;
void dfs1(int u, int fa) {
  if (~fa) dep[u] = dep[fa] + 1;
  id[u] = ++tim;
  rnk[tim] = u;
  L[u] = tim;
  siz[u] = 1;
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dis[v] = (dis[u] ^ e[i].w);
    dfs1(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
  R[u] = tim;
}
void dfs2(int u, int fa, bool keep) {
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    if (v == son[u]) continue;
    dfs2(v, u, 0);
    ans[u] = max(ans[u], ans[v]);
  }
  if (son[u]) {
    dfs2(son[u], u, 1);
    ans[u] = max(ans[u], ans[son[u]]);
  }
  ans[u] = max(ans[u], dp[dis[u]] - dep[u]);
  for (int i = 0; i <= 21; ++i) {
    if (dp[dis[u] ^ (1 << i)])
      ans[u] = max(ans[u], dp[dis[u] ^ (1 << i)] - dep[u]);
  }
  dp[dis[u]] = max(dp[dis[u]], dep[u]);
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    if (v == son[u]) continue;
    for (int j = L[v]; j <= R[v]; ++j) {
      int now = rnk[j];
      if (dp[dis[now]])
        ans[u] = max(ans[u], dep[now] + dp[dis[now]] - 2 * dep[u]);
      for (int k = 0; k <= 21; ++k) {
        if (dp[dis[now] ^ (1 << k)])
          ans[u] = max(ans[u], dep[now] + dp[dis[now] ^ (1 << k)] - 2 * dep[u]);
      }
    }
    for (int j = L[v]; j <= R[v]; ++j)
      if (dp[dis[rnk[j]]]) dp[dis[rnk[j]]] = max(dp[dis[rnk[j]]], dep[rnk[j]]);
  }
  if (!keep)
    for (int i = L[u]; i <= R[u]; ++i) dp[dis[rnk[i]]] = 0;
  return;
}
int main() {
  read(n);
  memset(head, -1, sizeof(head));
  for (int i = 2; i <= n; ++i) {
    int p;
    char ch;
    read(p);
    ch = getchar();
    add(p, i, 1ll << (ch - 'a'));
  }
  dfs1(1, 0);
  dfs2(1, 0, 1);
  for (int i = 1; i <= n; ++i) {
    if (i - 1) putchar(' ');
    write(ans[i]);
  }
  putchar('\n');
  return 0;
}
