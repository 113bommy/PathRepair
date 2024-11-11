#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5 + 6;
vector<pair<long long, long long> > g[MAXN];
long long n, m;
long long a[MAXN];
long long b[MAXN];
struct edge {
  long long u, v, w;
  bool operator<(edge const& other) const {
    if (w != other.w) return w < other.w;
    if (u != other.u) return u < other.u;
    return v < other.v;
  }
};
vector<edge> e;
int par[MAXN];
int sz[MAXN];
int getRoot(int u) {
  if (u == par[u]) return u;
  return par[u] = getRoot(par[u]);
}
void join(int p, int q) {
  if (sz[p] > sz[q]) {
    par[q] = p;
    sz[p] += sz[q];
  } else {
    par[p] = q;
    sz[q] += sz[p];
  }
}
int main() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    int s;
    cin >> s;
    for (int j = 0; j < s; j++) {
      int x;
      cin >> x;
      e.push_back({i, m + x, a[i] + b[x]});
    }
  }
  for (int i = 1; i <= n + m; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  int ans = 0;
  sort(e.rbegin(), e.rend());
  for (int i = 0; i < e.size(); i++) {
    int p = getRoot(e[i].u), q = getRoot(e[i].v);
    if (p != q) {
      join(p, q);
    } else
      ans += e[i].w;
  }
  cout << ans << endl;
  return 0;
}
