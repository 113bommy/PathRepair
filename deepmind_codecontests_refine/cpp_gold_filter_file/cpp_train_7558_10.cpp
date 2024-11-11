#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd;
const long long maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
const long long base = 500;
long long cntnw = 0;
long long f[maxn];
long long l[maxn];
long long b[maxn];
long long t[maxn];
long long pos[2 * maxn];
long long n;
map<long long, long long> mp;
int anc[maxn][18];
long long dep[maxn];
vector<long long> adj[maxn];
void dfs(long long u, long long par) {
  anc[u][0] = par;
  for (int i = 1; i < 18; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  cntnw++;
  f[u] = cntnw;
  pos[cntnw] = u;
  for (auto to : adj[u]) {
    if (to == par) continue;
    dep[to] = dep[u] + 1;
    dfs(to, u);
  }
  cntnw++;
  l[u] = cntnw;
  pos[cntnw] = u;
}
long long lca(long long x, long long y) {
  if (dep[x] < dep[y]) swap(x, y);
  long long kc = dep[x] - dep[y];
  for (int i = 17; i >= 0; i--)
    if (kc & (1ll << i)) x = anc[x][i];
  if (x == y) return x;
  for (int i = 17; i >= 0; i--) {
    if (anc[x][i] != anc[y][i]) {
      x = anc[x][i];
      y = anc[y][i];
    }
  }
  return anc[x][0];
}
bool dd[maxn];
long long ans = 0;
long long cnt_nw[maxn][2];
void add(long long x) {
  ans += cnt_nw[t[x]][1 - b[x]];
  cnt_nw[t[x]][b[x]]++;
}
void ers(long long x) {
  ans -= cnt_nw[t[x]][1 - b[x]];
  cnt_nw[t[x]][b[x]]--;
}
void dosth(long long x) {
  long long h = x;
  x = pos[x];
  if (dd[x])
    ers(x);
  else
    add(x);
  dd[x] = 1 - dd[x];
}
bool cmp(pair<pair<long long, long long>, pair<long long, long long>> a1,
         pair<pair<long long, long long>, pair<long long, long long>> b1) {
  pair<long long, long long> a = a1.first;
  pair<long long, long long> b = b1.first;
  if ((a.first / base) == (b.first / base)) return a.second < b.second;
  return (a.first / base) < (b.first / base);
}
long long res[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    if (mp.count(t[i]))
      t[i] = mp[t[i]];
    else {
      long long p = mp.size() + 1;
      mp[t[i]] = p;
      t[i] = p;
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0);
  long long q;
  cin >> q;
  vector<pair<pair<long long, long long>, pair<long long, long long>>> vt;
  for (int i = 1; i <= q; i++) {
    long long u, v;
    cin >> u >> v;
    if (dep[u] > dep[v]) swap(u, v);
    if (lca(u, v) == u) {
      vt.push_back(make_pair(make_pair(f[u], f[v]), make_pair(i, -1)));
    } else {
      if (l[u] > f[v]) swap(u, v);
      vt.push_back(
          make_pair(make_pair(l[u], f[v]), make_pair(i, f[lca(u, v)])));
    }
  }
  sort(vt.begin(), vt.end(), cmp);
  long long lnw = 1;
  long long rnw = 0;
  for (auto p : vt) {
    long long l = p.first.first;
    long long r = p.first.second;
    while (l < lnw) {
      lnw--;
      dosth(lnw);
    }
    while (r > rnw) {
      rnw++;
      dosth(rnw);
    }
    while (l > lnw) {
      dosth(lnw);
      lnw++;
    }
    while (r < rnw) {
      dosth(rnw);
      rnw--;
    }
    long long pos = p.second.second;
    if (pos != -1) dosth(pos);
    res[p.second.first] = ans;
    if (pos != -1) dosth(pos);
  }
  for (int i = 1; i <= q; i++) {
    cout << res[i] << "\n";
  }
}
