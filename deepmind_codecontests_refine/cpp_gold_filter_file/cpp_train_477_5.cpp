#include <bits/stdc++.h>
using ll = int;
const ll mod = 1e15 + 7;
const ll N = 1e5 + 5;
const int base = 400;
using ull = unsigned long long;
using namespace std;
ll n, m, t, k, T, a[N], dp[N], lab[N], u, v, b[N], d[N], tong, cnt, q, fe[N],
    f[N][20], g[N][20], h[N], P[N][20];
ll ans;
vector<ll> adj[N];
vector<pair<ll, ll> > kq;
void add(ll id, ll val) {
  for (; id <= n; id += id & -id) fe[id] += val;
}
ll get(ll id) {
  ll total = 0;
  for (; id > 0; id -= id & -id) total += fe[id];
  return total;
}
ll sum(ll l, ll r) { return get(r) - get(l - 1); }
void hop(ll u, ll v) {
  lab[u] += lab[v];
  lab[v] = u;
}
ll findp(ll u) { return lab[u] < 0 ? u : lab[u] = findp(lab[u]); }
pair<ll, ll> p[N];
ll dis(pair<ll, ll> x, pair<ll, ll> y) {
  return (x.first - y.first) * (x.first - y.first) +
         (x.second - y.second) * (x.second - y.second);
}
ll getmn(ll l, ll r) {
  ll total = mod;
  for (int i = l; i < r; i++) {
    for (int j = i + 1; j <= r; j++) total = min(total, dis(p[i], p[j]));
  }
  ans = min(ans, total);
  return total;
}
void findmn(vector<pair<ll, ll> > pi) {
  sort(pi.begin(), pi.end());
  for (int i = 0; i < pi.size(); i++) {
    for (int j = i + 1; j < pi.size(); j++) {
      if ((p[i].first - p[j].first) * (pi[i].first - pi[j].first) > ans) break;
      ans = min(ans, dis(pi[i], pi[j]));
    }
  }
}
ll cal(ll l, ll r) {
  if (r - l <= 3) return getmn(l, r);
  ll mid = (l + r) / 2;
  ll total = min(cal(l, mid), cal(mid, r));
  kq.clear();
  for (int i = l; i <= r; i++) {
    if ((p[i].first - p[mid].first) * (p[i].first - p[mid].first) <= ans)
      kq.push_back({p[i].second, p[i].first});
  }
  findmn(kq);
  total = min(total, ans);
  return total;
}
void sol() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> P[i][0] >> t;
    P[i][0] = max(P[i][0], (ll)0);
    if (P[i][0]) h[i] = h[P[i][0]] + 1;
    if (t == 0)
      f[i][0] = 1;
    else if (t == 1)
      g[i][0] = 1;
  }
  for (int j = 1; j <= 18; j++) {
    for (int i = 1; i <= n; i++) {
      P[i][j] = P[P[i][j - 1]][j - 1];
      f[i][j] = f[i][j - 1] & f[P[i][j - 1]][j - 1];
      g[i][j] = g[i][j - 1] & g[P[i][j - 1]][j - 1];
    }
  }
  cin >> m;
  while (m-- > 0) {
    cin >> q >> u >> v;
    int x = 1, y = 1, z = 1, ui = u, vi = v;
    for (int i = 18; i >= 0; i--) {
      if (h[v] >= h[u] + (1 << i)) {
        x &= f[v][i];
        y &= g[v][i];
        v = P[v][i];
      }
    }
    for (int i = 18; i >= 0; i--) {
      if (h[u] >= h[v] + (1 << i)) {
        z &= f[u][i];
        u = P[u][i];
      }
    }
    if (u != v) {
      for (int i = 18; i >= 0; i--) {
        if (P[u][i] != 0 && P[u][i] != P[v][i]) {
          x &= f[v][i];
          y &= g[v][i];
          z &= f[u][i];
          u = P[u][i];
          v = P[v][i];
        }
      }
      x &= f[v][0];
      y &= g[v][0];
      z &= f[u][0];
      u = P[u][0];
      v = P[v][0];
    }
    if (q == 1) {
      if (ui != vi && ui == u && x)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    } else {
      if (u != vi && z && y)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
}
int main() {
  if (fopen("pieaters"
            ".inp",
            "r")) {
    freopen(
        "pieaters"
        ".inp",
        "r", stdin);
    freopen(
        "pieaters"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ntest;
  ntest = 1;
  while (ntest-- > 0) sol();
}
