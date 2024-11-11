#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, k;
vector<vector<pair<int, int>>> g;
vector<int> c;
int res;
vector<map<int, int>> enemy;
vector<vector<char>> enemies;
map<pair<int, int>, int> pair_to_idx;
void rec(int idx) {
  if (idx == k + 1) {
    ++res;
  } else {
    for (int i = 1; i <= idx; ++i) {
      pair<int, int> we(idx, i);
      bool good = true;
      if (pair_to_idx.count(we)) {
        good = !enemies[pair_to_idx[we]][pair_to_idx[we]];
        for (int j = 1; j < idx; ++j) {
          pair<int, int> them(j, c[j]);
          if (pair_to_idx.count(them) &&
              enemies[pair_to_idx[we]][pair_to_idx[them]]) {
            good = false;
            break;
          }
        }
      }
      if (good) {
        c[idx] = i;
        rec(idx + 1);
        c[idx] = -1;
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n >> m >> k) {
    g.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].emplace_back(w, v);
    }
    enemy.assign(n + 1, map<int, int>());
    for (int i = 1; i <= n; ++i) {
      sort(g[i].begin(), g[i].end());
      int sz = g[i].size();
      for (int j = 0; j < sz; ++j) {
        int to = g[i][j].second;
        pair<int, int> pa = {sz, j + 1};
        int pa_idx = -1;
        if (pair_to_idx.count(pa)) {
          pa_idx = pair_to_idx[pa];
        } else {
          pa_idx = pair_to_idx.size();
          pair_to_idx[pa] = pa_idx;
        }
        enemy[to][pa_idx]++;
      }
    }
    enemies.assign(pair_to_idx.size(), vector<char>(pair_to_idx.size()));
    for (int i = 1; i <= n; ++i) {
      for (auto it = enemy[i].begin(); it != enemy[i].end(); ++it) {
        if (it->second > 1) {
          enemies[it->first][it->first] = true;
        }
        for (auto jt = enemy[i].begin(); jt != enemy[i].end(); ++jt) {
          if (it != jt) {
            enemies[it->first][jt->first] = true;
          }
        }
      }
    }
    c.assign(k + 1, -1);
    res = 0;
    rec(1);
    cout << res << "\n";
  }
}
