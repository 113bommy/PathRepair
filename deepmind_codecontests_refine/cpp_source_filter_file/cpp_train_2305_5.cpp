#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9 + 7;
const long long INFF = (long long)1e18;
const int mod = 998244353;
const int MXN = (int)1e6 + 7;
int a[MXN], c[MXN], cnt[MXN];
int num[MXN];
int siz[MXN], gp[MXN];
int fd(int v) { return gp[v] == v ? v : gp[v] = fd(gp[v]); }
void uni(int u, int v) {
  u = fd(u);
  v = fd(v);
  if (u == v) return;
  if (siz[u] > siz[v]) swap(u, v);
  gp[u] = v;
  siz[v] += siz[u];
}
vector<int> edge[MXN], edge2[MXN];
void bye() {
  puts("0");
  exit(0);
}
void pre(int u, int pa) {
  if (a[u]) {
    c[u] = a[u];
    cnt[u] = 1;
  }
  for (int v : edge2[u]) {
    if (v == pa) continue;
    pre(v, u);
    if (c[v]) {
      if (c[u] && c[v] != c[u]) {
        bye();
      } else {
        cnt[u] += cnt[v];
        c[u] = c[v];
        uni(u, v);
      }
    }
  }
  if (a[u] && cnt[u] == num[a[u]]) {
    c[u] = 0;
  }
}
long long mypow(long long v, long long t = mod - 2) {
  long long res = 1;
  while (t) {
    if (t & 1) res = res * v % mod;
    t >>= 1;
    v = v * v % mod;
  }
  return res;
}
long long dp[MXN][2];
void dfs(int u, int pa) {
  long long val = 1;
  for (int v : edge[u]) {
    if (v == pa) continue;
    dfs(v, u);
    val = val * dp[v][0] % mod;
  }
  if (a[u]) {
    dp[u][0] = dp[u][1] = val;
  } else {
    dp[u][0] = val;
    for (int v : edge[u]) {
      if (v == pa) continue;
      long long val2 = (val * mypow(dp[v][0]) % mod) * dp[v][1] % mod;
      dp[u][1] = (dp[u][1] + val2) % mod;
    }
    dp[u][0] = (dp[u][0] + dp[u][1]) % mod;
  }
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    num[a[i]]++;
    siz[i] = 1, gp[i] = i;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge2[u].push_back(v);
    edge2[v].push_back(u);
  }
  pre(1, 0);
  for (int i = 1; i <= n; i++) {
    int p = fd(i);
    a[p] |= a[i];
    for (int v : edge2[i]) {
      if (fd(v) == p) continue;
      edge[p].push_back(fd(v));
    }
  }
  dfs(fd(1), 0);
  printf("%lld\n", dp[fd(1)][1]);
  return 0;
}
