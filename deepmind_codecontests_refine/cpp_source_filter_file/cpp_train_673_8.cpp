#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int maxn = 100010;
const int mod = 1000000007;
const int maxe = 20;
int n;
vector<pair<int, int> > adj[maxn];
int price[maxn];
int sum[2][maxn];
int ntra[2][maxn];
long long ans;
int vis[maxn];
int lev[maxn];
int p[maxe][maxn];
int tin[maxn];
int tou[maxn];
int tms;
void dfs1(int u) {
  tin[u] = tms++;
  vis[u] = 1;
  for (int i = (1); i < (maxe); i++) p[i][u] = p[i - 1][p[i - 1][u]];
  for (int i = (0); i < (int((adj[u]).size())); i++) {
    int v = adj[u][i].first;
    if (!vis[v]) {
      p[0][v] = u;
      lev[v] = lev[u] + 1;
      dfs1(v);
    }
  }
  tou[u] = tms++;
}
void dfs2(int u) {
  vis[u] = 1;
  ntra[0][u] = sum[0][u];
  ntra[1][u] = sum[1][u];
  for (int i = (0); i < (int((adj[u]).size())); i++) {
    int v = adj[u][i].first;
    if (!vis[v]) {
      price[v] = adj[u][i].second;
      dfs2(v);
      ntra[0][u] += sum[0][v];
      ntra[1][u] += sum[1][v];
    }
  }
}
int lca(int u, int v) {
  if (lev[u] < lev[v]) swap(u, v);
  if (tin[v] <= tin[u] && tou[v] >= tou[u]) return v;
  for (int i = (maxe)-1; i >= (0); i--)
    if (lev[u] - (1 << i) >= lev[v]) u = p[i][u];
  for (int i = (maxe)-1; i >= (0); i--)
    if (p[i][u] != p[i][v]) {
      u = p[i][u];
      v = p[i][v];
    }
  return p[0][u];
}
long long ex(long long n, long long k) {
  if (k < 0) return 0;
  if (k == 0) return 1;
  if (k & 1) return n * ex(n, k - 1) % mod;
  long long t = ex(n, k >> 1);
  return t * t % mod;
}
void solve() {
  memset(sum, 0, sizeof(sum));
  memset(ntra, 0, sizeof(ntra));
  memset(vis, 0, sizeof(vis));
  memset(lev, 0, sizeof(lev));
  memset(p, -1, sizeof(p));
  memset(tin, 0, sizeof(tin));
  memset(tou, 0, sizeof(tou));
  tms = 0;
  scanf("%d", &n);
  for (int i = (0); i < (n - 1); i++) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    x--;
    y--;
    adj[x].push_back(make_pair(y, w));
    adj[y].push_back(make_pair(x, -w));
  }
  dfs1(0);
  int k;
  scanf("%d", &k);
  int prev = 0;
  for (int i = (0); i < (k); i++) {
    int s;
    scanf("%d", &s);
    s--;
    int a = lca(prev, s);
    sum[0][a]--;
    sum[0][prev]++;
    sum[1][a]--;
    sum[1][s]++;
    prev = s;
  }
  memset(vis, 0, sizeof(vis));
  dfs2(0);
  long long ans = 0;
  for (int i = (1); i < (n); i++) {
    if (price[i] == 1)
      ans = (ans + ex(2, ntra[0][i]) - 1) % mod;
    else if (price[i] == -1)
      ans = (ans + ex(2, ntra[1][i]) - 1) % mod;
  }
  printf("%I64d", ans);
}
int main() {
  solve();
  return 0;
}
