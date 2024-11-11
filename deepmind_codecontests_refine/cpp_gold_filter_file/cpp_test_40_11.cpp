#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 eng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3e5 + 4;
int n, m, cnt[N];
vector<int> g[N], tree[N];
void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
bool used[N];
int p[N];
void precalc(int u = 1) {
  used[u] = true;
  for (int to : g[u])
    if (!used[to]) {
      tree[u].push_back(to);
      tree[to].push_back(u);
      p[to] = u;
      precalc(to);
    }
}
void calc(int u) {
  while (u) {
    cnt[u] ^= 1;
    u = p[u];
  }
}
vector<pii> que;
vector<int> way;
void dfs(int u, int v, int par = -1) {
  way.push_back(u);
  if (u == v) {
    cout << (int)((way).size()) << "\n";
    for (int x : way) cout << x << " ";
    cout << "\n";
    way.pop_back();
    return;
  }
  for (int to : tree[u])
    if (to != par) {
      dfs(to, v, u);
    }
  way.pop_back();
}
int endsCnt(int u) {
  int cur = cnt[u];
  for (int to : tree[u])
    if (to != p[u]) {
      cur += cnt[to];
    }
  return cur & 1;
}
void solve() {
  read();
  precalc();
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    que.emplace_back(a, b);
    calc(a);
    calc(b);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += cnt[i];
  if (ans != 0) {
    ans = 0;
    for (int u = 1; u <= n; ++u) {
      ans += endsCnt(u);
    }
    cout << "NO\n" << ans / 2;
    return;
  }
  cout << "YES\n";
  for (pii qq : que) {
    dfs(qq.first, qq.second);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0), cin.tie(0);
  int z = 1;
  while (z--) {
    solve();
  }
  return 0;
}
