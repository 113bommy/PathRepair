#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
double tick() {
  static clock_t oldt;
  clock_t newt = clock();
  double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
  oldt = newt;
  return diff;
}
long long mulmod(long long a, long long b, long long m) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T>
T mod(T a, T b) {
  while (a < 0) a += b;
  return a % b;
}
template <typename T>
T power(T e, T n, T m) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mod(x * p, m);
    p = mod(p * p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T power(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T InverseEuler(T a, T m) {
  return (a == 1 ? 1 : power(a, m - 2, m));
}
template <typename T>
inline T gcd(T a, T b) {
  T c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
long long exEuclid(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long g = exEuclid(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return g;
}
const int MAXN = 1e5 + 5;
int U[MAXN], V[MAXN];
vector<pair<int, int> > g[MAXN];
int subsz[MAXN];
int depth[MAXN];
int pa[17][MAXN];
void dfs_sz(int u = 1, int p = -1, int d = 0) {
  subsz[u] = 1;
  depth[u] = d;
  pa[0][u] = p;
  for (auto node : g[u]) {
    int v = node.first;
    int e = node.second;
    if (v != p) {
      U[e] = u;
      V[e] = v;
      dfs_sz(v, u, d + 1);
      subsz[u] += subsz[v];
    }
  }
}
int LCA(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int dif = depth[u] - depth[v];
  for (int i = 0; i < 17; i++)
    if (dif & (1 << i)) u = pa[i][u];
  if (u == v) return u;
  for (int i = 16; i >= 0; i--) {
    if (pa[i][u] != pa[i][v]) {
      u = pa[i][u];
      v = pa[i][v];
    }
  }
  return pa[0][u];
}
int n, m;
int chainno;
int chainhead[MAXN];
int chainidx[MAXN];
int pos[MAXN];
int ptr;
int st[MAXN * 4];
void upd(int id, int v, int idx = 1, int l = 1, int r = n) {
  if (l == r) {
    st[idx] = v;
    return;
  }
  int m = l + (r - l) / 2;
  if (id <= m)
    upd(id, v, idx << 1, l, m);
  else
    upd(id, v, idx << 1 | 1, m + 1, r);
  st[idx] = st[idx << 1] + st[idx << 1 | 1];
}
void update(int e, int col) { upd(pos[V[e]], col); }
int ask(int ql, int qr, int idx = 1, int l = 1, int r = n) {
  if (ql > r || qr < l) {
    return 0;
  }
  if (ql <= l && r <= qr) {
    return st[idx];
  }
  int m = l + (r - l) / 2;
  int ll = ask(ql, qr, idx << 1, l, m);
  int rr = ask(ql, qr, idx << 1 | 1, m + 1, r);
  return (ll + rr);
}
int query_up(int u, int v) {
  int uchain, vchain = chainidx[v];
  int ans = 0;
  while (1) {
    uchain = chainidx[u];
    if (uchain == vchain) {
      if (pos[u] > pos[v]) ans = ans + ask(pos[v] + 1, pos[u]);
      return ans;
    }
    int head = chainhead[uchain];
    ans = ans + ask(pos[head], pos[u]);
    u = pa[0][head];
  }
}
int query(int u, int v) {
  int lca = LCA(u, v);
  int ans1 = query_up(u, lca);
  int ans2 = query_up(v, lca);
  return (ans1 + ans2);
}
void hld(int u, int p) {
  if (chainhead[chainno] == -1) chainhead[chainno] = u;
  chainidx[u] = chainno;
  pos[u] = ++ptr;
  int heaviest = -1;
  for (auto node : g[u]) {
    int v = node.first;
    if (v == p) continue;
    if (heaviest == -1 || subsz[heaviest] < subsz[v]) {
      heaviest = v;
    }
  }
  if (heaviest != -1) {
    hld(heaviest, u);
  }
  for (auto node : g[u]) {
    int v = node.first;
    if (v != p && v != heaviest) {
      chainno++;
      hld(v, u);
    }
  }
}
int main(int argc, char *argv[]) {
  io();
  cin >> n;
  int x, y;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
  }
  int typ, id;
  cin >> m;
  memset(pa, -1, sizeof(pa));
  memset(chainhead, -1, sizeof(chainhead));
  dfs_sz();
  for (int j = 1; j < 17; j++)
    for (int i = 1; i <= n; i++)
      if (pa[j - 1][i] != -1) pa[j][i] = pa[j - 1][pa[j - 1][i]];
  hld(1, -1);
  while (m--) {
    cin >> typ;
    if (typ == 1) {
      cin >> id;
      update(id, 0);
    } else if (typ == 2) {
      cin >> id;
      update(id, 1);
    } else {
      cin >> x >> y;
      int q = query(x, y);
      if (q == 0) {
        int d = depth[x] + depth[y] - 2 * depth[LCA(x, y)];
        cout << d << '\n';
      } else {
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}
