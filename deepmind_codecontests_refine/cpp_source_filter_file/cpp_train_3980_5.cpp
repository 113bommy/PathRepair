#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  while (cin >> n >> m >> k) {
    vector<vector<int>> a(n, vector<int>(m));
    int max_color = k - 1;
    for (auto &vec : a) {
      for (auto &e : vec) {
        cin >> e;
        --e;
      }
    }
    vector<vector<vector<int>>> color_dist(
        max_color + 1, vector<vector<int>>(n, vector<int>(m, -1)));
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    vector<vector<pair<int, int>>> components(max_color + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        components[a[i][j]].emplace_back(i, j);
      }
    }
    auto component_bfs = [&](int color) {
      queue<pair<int, int>> que;
      for (auto p : components[color]) {
        que.push(p);
        color_dist[color][p.first][p.second] = 0;
      }
      vector<char> color_filled(max_color + 1);
      queue<pair<int, int>> reminder;
      while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        while (!reminder.empty() &&
               reminder.front().first == 1 + color_dist[color][i][j]) {
          auto [v, c] = reminder.front();
          reminder.pop();
          for (auto [ii, jj] : components[c]) {
            if (color_dist[color][ii][jj] == -1) {
              color_dist[color][ii][jj] = color_dist[color][i][j] + 1;
              que.emplace(ii, jj);
            }
          }
        }
        for (int z = 0; z < 4; ++z) {
          int ii = i + di[z];
          int jj = j + dj[z];
          if (0 <= ii && ii < n && 0 <= jj && jj < m &&
              color_dist[color][ii][jj] == -1) {
            color_dist[color][ii][jj] = color_dist[color][i][j] + 1;
            que.emplace(ii, jj);
            if (!color_filled[a[ii][jj]]) {
              color_filled[a[ii][jj]] = true;
              reminder.emplace(color_dist[color][ii][jj] + 1, a[ii][jj]);
            }
          }
        }
      }
    };
    for (int i = 0; i <= max_color; ++i) {
      component_bfs(i);
    }
    vector<vector<char>> cell_used(n, vector<char>(m));
    auto cell_bfs = [&](int r1, int c1, int r2, int c2) {
      vector<tuple<int, int, int>> que({{0, r1, c1}});
      int res = 10 * max_color;
      for (int i = 0; i <= max_color; ++i) {
        int cur = color_dist[i][r1][c1] + 1 + color_dist[i][r2][c2];
        res = min(res, cur);
      }
      vector<int> color_used(max_color + 1, -1);
      color_used[a[r1][c1]] = true;
      int queidx = 0;
      while (queidx < que.size()) {
        auto [d, i, j] = que[queidx++];
        if (i == r2 && j == c2) {
          res = min(res, d);
          break;
        }
        if (res <= d) break;
        for (int z = 0; z < 4; ++z) {
          int ii = i + di[z];
          int jj = j + dj[z];
          if (0 <= ii && ii < n && 0 <= jj && jj < m) {
            if (!cell_used[ii][jj] &&
                (color_used[a[ii][jj]] == -1 || color_used[a[ii][jj]] == d)) {
              cell_used[ii][jj] = true;
              color_used[a[ii][jj]] = d;
              que.emplace_back(d + 1, ii, jj);
            }
          }
        }
      }
      for (auto [d, i, j] : que) {
        cell_used[i][j] = false;
      }
      return res;
    };
    int q;
    cin >> q;
    while (q--) {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      --r1, --c1, --r2, --c2;
      cout << cell_bfs(r1, c1, r2, c2) << "\n";
    }
    break;
  }
}
