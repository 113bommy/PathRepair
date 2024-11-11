#include <bits/stdc++.h>
using namespace std;
const long long inf = 9.2e18;
const int maxn = 1e5 + 70;
const int INF = 2.1e9;
const int maxm = 1e6 + 70;
const int MOD = 1e9 + 7;
const double eps = 1e-7;
const double PI = acos(-1.0);
int n, m, k, q;
int rt, dfs_clock;
vector<int> G[maxn];
int sz[maxn], pre[maxn], l[maxn], f[maxn][20];
void dfs(int u, int fa) {
  if (u == rt) {
    dfs_clock = 0;
    l[u] = 0;
  } else {
    l[u] = l[fa] + 1;
  }
  sz[u] = 1;
  pre[u] = ++dfs_clock;
  f[u][0] = fa;
  for (int i = 1; (1 << i) <= l[u]; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (int i = 0; i < G[u].size(); i++) {
    if (G[u][i] != fa) {
      dfs(G[u][i], u);
      sz[u] += sz[G[u][i]];
    }
  }
}
int lca(int u, int v) {
  if (l[u] < l[v]) swap(u, v);
  int k = 0;
  while ((1 << (k + 1)) <= l[u] - l[v]) k++;
  while (l[u] > l[v]) {
    while ((1 << k) > l[u] - l[v]) k--;
    u = f[u][k];
  }
  if (u == v) return v;
  k = 0;
  while ((1 << (k + 1)) <= l[v]) k++;
  while (k >= 0) {
    while ((1 << k) > l[u]) k--;
    if (f[u][k] != f[v][k]) {
      u = f[u][k];
      v = f[v][k];
    } else
      k--;
  }
  return f[u][0];
}
int a[maxn];
long long sumv[4 * maxn], addv[4 * maxn];
void maintain(int o, int L, int R) {
  int lc = o * 2, rc = o * 2 + 1;
  sumv[o] = 0;
  if (R > L) {
    sumv[o] = sumv[lc] + sumv[rc];
  }
  sumv[o] += addv[o] * (R - L + 1);
}
int ql, qr, qv;
void update(int o, int L, int R) {
  int lc = o * 2, rc = o * 2 + 1;
  if (ql <= L && qr >= R) {
    addv[o] += qv;
  } else {
    int M = L + (R - L) / 2;
    if (ql <= M) update(lc, L, M);
    if (qr > M) update(rc, M + 1, R);
  }
  maintain(o, L, R);
}
long long _sum;
void query(int o, int L, int R, int add) {
  if (ql <= L && qr >= R) {
    _sum += sumv[o] + add * (R - L + 1);
  } else {
    int M = L + (R - L) / 2;
    int lc = o * 2, rc = o * 2 + 1;
    if (ql <= M) query(lc, L, M, add + addv[o]);
    if (qr > M) query(rc, M + 1, R, add + addv[o]);
  }
}
void check(int o, int L, int R) {
  cout << o << ' ' << L << ' ' << R << ':' << addv[o] << ' ' << sumv[o] << endl;
  if (L != R) {
    int M = L + (R - L) / 2;
    check(o * 2, L, M);
    check(o * 2 + 1, M + 1, R);
  }
}
int main() {
  while (cin >> n >> q) {
    memset(sumv, 0, sizeof(sumv));
    memset(addv, 0, sizeof(addv));
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    rt = 1;
    dfs(rt, 0);
    for (int i = 1; i <= n; i++) {
      ql = qr = pre[i];
      qv = a[i];
      update(1, 1, n);
    }
    while (q--) {
      int d;
      cin >> d;
      if (d == 1) {
        cin >> rt;
      } else if (d == 2) {
        int u, v;
        cin >> u >> v >> qv;
        int anc = lca(u, v);
        int t = lca(u, rt);
        if (l[t] > l[anc]) anc = t;
        t = lca(v, rt);
        if (l[t] > l[anc]) anc = t;
        if (anc == rt) {
          ql = 1, qr = n;
          update(1, 1, n);
        } else if (pre[rt] < pre[anc] || pre[rt] >= pre[anc] + sz[anc]) {
          ql = pre[anc], qr = pre[anc] + sz[anc] - 1;
          update(1, 1, n);
        } else {
          int w = rt;
          int k = 0;
          while (l[rt] - (1 << k) > l[anc]) k++;
          while (k >= 0) {
            if (l[f[w][k]] > l[anc]) w = f[w][k];
            k--;
          }
          ql = 1, qr = n;
          update(1, 1, n);
          ql = pre[w], qr = pre[w] + sz[w] - 1, qv = -qv;
          update(1, 1, n);
        }
      } else if (d == 3) {
        int anc;
        cin >> anc;
        long long ans;
        _sum = 0;
        if (anc == rt) {
          ql = 1, qr = n;
          query(1, 1, n, 0);
          ans = _sum;
        } else if (pre[rt] < pre[anc] || pre[rt] >= pre[anc] + sz[anc]) {
          ql = pre[anc], qr = pre[anc] + sz[anc] - 1;
          query(1, 1, n, 0);
          ans = _sum;
        } else {
          int w = rt;
          int k = 0;
          while (l[rt] - (1 << k) > l[anc]) k++;
          while (k >= 0) {
            if (l[f[w][k]] > l[anc]) w = f[w][k];
            k--;
          }
          ql = 1, qr = n;
          query(1, 1, n, 0);
          ans = _sum;
          _sum = 0;
          ql = pre[w], qr = pre[w] + sz[w] - 1;
          query(1, 1, n, 0);
          ans -= _sum;
        }
        cout << ans << endl;
      }
    }
  }
  return 0;
}
