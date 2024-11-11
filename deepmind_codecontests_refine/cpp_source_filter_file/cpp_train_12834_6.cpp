#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> edges[maxn];
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      edges[x].push_back(y);
      edges[y].push_back(x);
      ++deg[x];
      ++deg[y];
    }
    for (int i = 1; i <= n; ++i) {
      sort(edges[i].begin(), edges[i].end());
    }
    if (k > 500) {
      cout << "-1" << '\n';
      continue;
    }
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= n; ++i) {
      pq.push({deg[i], i});
    }
    vector<int> ans;
    vector<int> bad(n + 1), vis(n + 1);
    int clique = -1;
    while (!pq.empty()) {
      int d = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      if (vis[u]) continue;
      vis[u] = 1;
      bool good = 1;
      if (d >= k) {
        ans.push_back(u);
        continue;
      }
      if (d == k - 1 && (k * (k - 1)) / 2 <= m) {
        bool good = 1;
        for (int i = 0; i < (int)edges[u].size(); ++i) {
          if (bad[edges[u][i]]) continue;
          int x = edges[u][i];
          for (int j = i + 1; j < (int)edges[u].size(); ++j) {
            int y = edges[x][j];
            if (bad[y]) continue;
            int found = binary_search(edges[x].begin(), edges[x].end(), y);
            if (!found) {
              good = 0;
              break;
            }
          }
          if (!good) {
            break;
          }
        }
        if (good) {
          clique = u;
          break;
        }
      }
      bad[u] = 1;
      for (auto i : edges[u]) {
        --deg[i];
        pq.push({deg[i], i});
      }
    }
    if (clique != -1) {
      cout << "2" << '\n';
      cout << clique << ' ';
      for (auto i : edges[clique]) {
        if (!bad[i]) {
          cout << i << ' ';
        }
      }
      cout << '\n';
    } else if (ans.size() > k) {
      cout << "1 " << ans.size() << '\n';
      for (auto i : ans) {
        cout << i << ' ';
      }
      cout << '\n';
    } else {
      cout << "-1" << '\n';
    }
  }
  return 0;
}
