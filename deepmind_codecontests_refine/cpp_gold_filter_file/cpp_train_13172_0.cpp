#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int mod = INF;
const int N = 1e6 + 7;
const int T = 1 << 20;
vector<vector<pair<int, int> > > G(N);
set<int> visited;
int klik[N];
int dfs(int start, int klik_w_typa, int do_jakiego, bool clear_vis = true) {
  if (clear_vis) visited.clear();
  int ret = klik_w_typa;
  visited.insert(start);
  klik[start] = klik_w_typa;
  for (auto& [u, kol] : G[start])
    if (!visited.count(u))
      ret = min(ret + dfs(u, do_jakiego ^ klik[start] ^ kol, do_jakiego, false),
                INF);
    else if (do_jakiego ^ klik[start] ^ klik[u] ^ kol)
      ret = INF;
  return ret;
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    G[a].push_back({b, c == 'R'});
    G[b].push_back({a, c == 'R'});
  }
  vector<int> cost[2];
  vector<int> czy_klikac[2];
  set<int> global;
  for (int i = 1; i <= n; i++) {
    if (!global.count(i)) {
      for (int sign = 0; sign <= 1; sign++) {
        pair<int, int> wyn = {dfs(i, 0, sign), dfs(i, 1, sign)};
        cost[sign].push_back(min(wyn.first, wyn.second));
        czy_klikac[sign].push_back(wyn.first > wyn.second);
      }
      for (auto& u : visited) global.insert(u);
    }
  }
  int best_cost = INF;
  int best_sign = -1;
  for (int sign = 0; sign <= 1; sign++)
    if (accumulate(cost[sign].begin(), cost[sign].end(), 0ll) < best_cost) {
      best_cost = accumulate(cost[sign].begin(), cost[sign].end(), 0ll);
      best_sign = sign;
    }
  if (best_sign == -1) {
    cout << -1 << '\n';
    exit(0);
  }
  global.clear();
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!global.count(i)) {
      dfs(i, czy_klikac[best_sign][cnt++], best_sign);
      for (auto& u : visited) global.insert(u);
    }
  cout << best_cost << '\n';
  for (int i = 1; i <= n; i++)
    if (klik[i]) cout << i << ' ';
  cout << '\n';
}
signed main() {
  int test = 1;
  for (int i = 0; i < test; i++) solve();
}
