#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return a > val ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline long long isqrt(long long k) {
  long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
const int maxn = 5010;
int n, m;
vector<pair<int, int> > edge;
vector<int> adj[maxn];
vector<int> iadj[maxn];
int vis[maxn];
vector<int> ver;
int sz[maxn];
int com[maxn];
int f[maxn];
int dmin[maxn];
vector<int> his;
void dfs(int u) {
  vis[u] = 1;
  for (int i = (0); i < (int((adj[u]).size())); i++) {
    int v = adj[u][i];
    if (!vis[v]) {
      dfs(v);
    }
  }
  ver.push_back(u);
}
void idfs(int u, int id) {
  vis[u] = 1, com[u] = id, sz[id]++;
  for (int i = (0); i < (int((iadj[u]).size())); i++) {
    int v = iadj[u][i];
    if (!vis[v]) {
      idfs(v, id);
    }
  }
}
void clear() {
  while (int((his).size())) {
    vis[his.back()] = 0;
    his.pop_back();
  }
}
void dfs2(int u, int anc, int dep = 0) {
  vis[u] = 1, his.push_back(u);
  for (int i = (0); i < (int((adj[u]).size())); i++) {
    int v = adj[u][i];
    if (com[u] == com[v]) {
      if (!vis[v])
        dfs2(v, anc, dep + 1);
      else if (v == anc) {
        chkmin(dmin[com[u]], dep + 1);
      }
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = (0); i < (m); i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge.push_back(make_pair(u, v));
    adj[u].push_back(v);
    iadj[v].push_back(u);
  }
  for (int i = (0); i < (n); i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  fill_n(vis, n, 0);
  int cnt = 0;
  for (int i = (int((ver).size())) - 1; i >= (0); i--) {
    int u = ver[i];
    if (!vis[u]) {
      idfs(u, cnt++);
    }
  }
  for (int i = (0); i < (int((edge).size())); i++) {
    int u = edge[i].first;
    int v = edge[i].second;
    int cu = com[u];
    int cv = com[v];
    if (cu != cv) {
      f[cu] = 1;
    }
  }
  fill_n(dmin, n, INF);
  fill_n(vis, n, 0);
  for (int i = (0); i < (n); i++) {
    clear();
    dfs2(i, i);
  }
  int ans = n;
  for (int i = (0); i < (cnt); i++) {
    if (!f[i] && dmin[i]) {
      ans += 998 * dmin[i] + 1;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
