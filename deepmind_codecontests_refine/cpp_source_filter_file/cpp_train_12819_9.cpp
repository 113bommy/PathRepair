#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;
bool arr[MAX][MAX];
bool vis[MAX][MAX]{false};
vector<pair<int, int>> adj[MAX][MAX];
int main() {
  int r1, c1;
  int r2, c2;
  int n;
  cin >> n;
  cin >> r1 >> c1 >> r2 >> c2;
  --r1, --c1, --r2, --c2;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) arr[i][j] = s[j] - '0';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!arr[i][j]) {
        if (i - 1 >= 0 && !arr[i - 1][j]) {
          adj[i][j].push_back({i - 1, j});
        }
        if (i + 1 < n && !arr[i + 1][j]) {
          adj[i][j].push_back({i + 1, j});
        }
        if (j - 1 >= 0 && !arr[i][j - 1]) {
          adj[i][j].push_back({i, j - 1});
        }
        if (j + 1 < n && !arr[i][j + 1]) {
          adj[i][j].push_back({i, j + 1});
        }
      }
    }
  }
  stack<pair<int, int>> sta;
  sta.push({r1, c1});
  vis[r1][c1] = true;
  vector<pair<int, int>> a;
  while (!sta.empty()) {
    pair<int, int> cur = sta.top();
    a.push_back({cur.first, cur.second});
    if (cur.first == r2 && cur.second == c2) return puts("NO");
    sta.pop();
    for (pair<int, int> node : adj[cur.first][cur.second]) {
      if (!vis[node.first][node.second]) {
        vis[node.first][node.second] = true;
        sta.push({node.first, node.second});
      }
    }
  }
  sta.push({r2, c2});
  vis[r2][c2] = true;
  vector<pair<int, int>> b;
  while (!sta.empty()) {
    pair<int, int> cur = sta.top();
    b.push_back({cur.first, cur.second});
    sta.pop();
    for (pair<int, int> node : adj[cur.first][cur.second]) {
      if (!vis[node.first][node.second]) {
        vis[node.first][node.second] = true;
        sta.push({node.first, node.second});
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      ans = min(ans,
                (a[i].first - b[j].first) * (a[i].first - b[j].first) +
                    (a[i].second - b[j].second) * (a[i].second - b[j].second));
    }
  }
  cout << ans << endl;
  return 0;
}
