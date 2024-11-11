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
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = 2 * acos(0);
const int maxn = 210;
int n, m, q;
int x[maxn][maxn];
int a[10], b[10];
char s[1000010];
vector<int> adj[maxn * maxn];
vector<int> radj[maxn * maxn];
int d[maxn * maxn];
int e[maxn * maxn];
bool vis[maxn];
vector<int> vs, t;
int bms;
int get(int i, int j) { return i * m + j; }
void dfs(int u) {
  vis[u] = 1;
  for (int i = (0); i < (int((adj[u]).size())); i++) {
    int v = adj[u][i];
    if (!vis[v]) dfs(v);
  }
  vs.push_back(u);
}
void rdfs(int u) {
  vis[u] = 1;
  t.push_back(u);
  bms |= (1 << d[u]);
  for (int i = (0); i < (int((radj[u]).size())); i++) {
    int v = radj[u][i];
    if (!vis[v]) rdfs(v);
  }
}
bool work(int u, char* s, vector<int> cnt, int bitmask) {
  if (e[u]) {
    if ((e[u] & bitmask) == bitmask) return 1;
    return 0;
  }
  int k = s[0] - '0';
  if (d[u] == k) {
    s++;
    if (!(--cnt[k])) bitmask ^= (1 << k);
  }
  if (s[0] == 0) return 1;
  for (int i = (0); i < (int((adj[u]).size())); i++) {
    int v = adj[u][i];
    if (work(v, s, cnt, bitmask)) return 1;
  }
  return 0;
}
void solve() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = (0); i < (n); i++) {
    scanf("%s", s);
    for (int j = (0); j < (m); j++) d[get(i, j)] = x[i][j] = s[j] - '0';
  }
  for (int i = (0); i < (10); i++) scanf("%d%d", a + i, b + i);
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++) {
      int k = x[i][j];
      if (!a[k] && !b[k])
        e[get(i, j)] = 1 << k;
      else if (i + a[k] >= 0 && i + a[k] < n && j + b[k] >= 0 && j + b[k] < m) {
        adj[get(i, j)].push_back(get(i + a[k], j + b[k]));
        radj[get(i + a[k], j + b[k])].push_back(get(i, j));
      }
    }
  for (int i = (0); i < (n * m); i++)
    if (!vis[i]) dfs(i);
  memset(vis, 0, sizeof(vis));
  for (int i = (int((vs).size())) - 1; i >= (0); i--) {
    int u = vs[i];
    if (!vis[u]) {
      bms = 0;
      rdfs(u);
      if (int((t).size()) == 1) {
        t.clear();
        continue;
      }
      while (int((t).size())) {
        e[t.back()] = bms;
        t.pop_back();
      }
    }
  }
  for (int i = (0); i < (n * m); i++)
    if (!int((adj[i]).size())) e[i] = (1 << d[i]);
  while (q--) {
    scanf("%s", s);
    vector<int> cnt(10, 0);
    int bitmask = 0, len = strlen(s);
    for (int i = (0); i < (len); i++) {
      cnt[s[i] - '0']++;
      bitmask |= (1 << (s[i] - '0'));
    }
    bool flag = 0;
    for (int i = (0); i < (n * m); i++)
      if ((!int((radj[i]).size()) || e[i]) && work(i, s, cnt, bitmask)) {
        printf("YES\n");
        flag = 1;
        break;
      }
    if (!flag) printf("NO\n");
  }
}
int main() {
  solve();
  return 0;
}
