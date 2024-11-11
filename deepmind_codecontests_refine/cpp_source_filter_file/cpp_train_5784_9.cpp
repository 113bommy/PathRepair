#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 1e2;
void stndrtn() {}
const bool flag = 0;
struct edge {
  ll u, v, w;
};
const int N = 1e3 + 10;
const int M = 3e4 + 10;
vector<pii> adj[N];
int s, t, p[N], eid[N];
bool dltd[M], br[M], was[N];
void fnpth(int first = s) {
  if (first == t) {
    return;
  }
  was[first] = 1;
  for (pii u : adj[first]) {
    int to, id;
    tie(to, id) = u;
    if (!was[to] && !dltd[id]) {
      eid[to] = id;
      p[to] = first;
      fnpth(to);
    }
  }
}
void fpth() {
  memset(was, 0, sizeof(was));
  p[t] = -1;
  fnpth();
}
int tin[N], fup[N], tmr;
void dfs(int first = s, int pr = -1) {
  tin[first] = fup[first] = ++tmr;
  was[first] = 1;
  for (pii u : adj[first]) {
    int to, id;
    tie(to, id) = u;
    if (to == pr || dltd[id]) {
      continue;
    }
    if (!was[to]) {
      dfs(to, first);
      fup[first] = min(fup[first], fup[to]);
      if (fup[to] > tin[first]) {
        br[id] = 1;
      }
    } else {
      fup[first] = min(fup[first], tin[to]);
    }
  }
}
void fbr() {
  tmr = 0;
  memset(was, 0, sizeof(was));
  memset(br, 0, sizeof(br));
  dfs();
}
vector<int> fnd_pth() {
  fpth();
  if (p[t] == -1) {
    return {};
  }
  vector<int> pth;
  int cur = t;
  while (cur != s) {
    pth.push_back(eid[cur]);
    cur = p[cur];
  }
  return pth;
}
void ma1n() {
  int n, m;
  cin >> n >> m >> s >> t;
  s--, t--;
  vector<edge> e(m);
  for (int i = 0; i < m; ++i) {
    edge& first = e[i];
    cin >> first.u >> first.v >> first.w;
    first.u--, first.v--;
    adj[first.u].push_back({first.v, i});
    adj[first.v].push_back({first.u, i});
  }
  vector<int> pth = fnd_pth();
  if (pth.empty()) {
    cout << "0\n0", exit(0);
  }
  ll ans = (1ll << 60ll);
  vector<int> vans;
  fbr();
  for (int i : pth) {
    if (br[i] && e[i].w < ans) {
      ans = e[i].w;
      vans = {i};
    }
  }
  for (int j : pth) {
    dltd[j] = 1;
    auto nwpth = fnd_pth();
    if (nwpth.empty()) {
      dltd[j] = 0;
      continue;
    }
    for (int i : nwpth) {
      br[i] = 0;
    }
    fbr();
    for (int i : nwpth) {
      if (br[i] && e[i].w + e[j].w < ans) {
        ans = e[i].w + e[j].w;
        vans = {i, j};
      }
    }
    dltd[j] = 0;
  }
  if (ans == (1ll << 60ll)) {
    cout << "-1\n";
  } else {
    cout << ans << "\n";
    cout << (int)vans.size() << "\n";
    for (int first : vans) {
      cout << first + 1 << " ";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr), stndrtn();
  int ts = 1;
  if (flag) {
    cin >> ts;
  }
  while (ts--) {
    ma1n();
  }
  return 0;
}
