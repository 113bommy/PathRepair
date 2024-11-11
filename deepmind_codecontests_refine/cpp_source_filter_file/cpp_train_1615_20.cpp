#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const double eps = 1e-6;
using namespace std;
bool eq(const double &a, const double &b) { return fabs(a - b) < eps; }
bool ls(const double &a, const double &b) { return a + eps < b; }
bool le(const double &a, const double &b) { return eq(a, b) || ls(a, b); }
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); };
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long kpow(long long a, long long b) {
  long long res = 1;
  a %= mod;
  if (b < 0) return 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int d[maxn];
int sum = 0;
bool is[maxn];
vector<int> G[maxn];
void dfs(int u, int p, int deep) {
  d[u] = deep;
  for (int i = 0; i < (G[u].size()); ++i) {
    int v = G[u][i];
    if (v == p) continue;
    dfs(v, u, deep + 1);
  }
}
void ddfs(int u, int p, int deep) {
  d[u] = deep;
  for (int i = 0; i < (G[u].size()); ++i) {
    int v = G[u][i];
    if (v == p) continue;
    ddfs(v, u, deep + 1);
    if (is[v]) sum += 2;
    is[u] |= is[v];
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < (n); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  memset(is, false, sizeof(is));
  int x;
  for (int i = 0; i < (m); ++i) scanf("%d", &x), is[x] = true;
  dfs(x, x, 0);
  int s, t, mx = -1;
  for (int i = n; i >= (1); --i)
    if (is[i])
      if (mx < d[i]) mx = d[i], s = i;
  ddfs(s, s, 0);
  mx = -1;
  for (int i = n; i >= (1); --i)
    if (is[i])
      if (mx < d[i]) mx = d[i], t = i;
  printf("%d\n%d\n", s < t ? s : t, sum - mx);
  return 0;
}
