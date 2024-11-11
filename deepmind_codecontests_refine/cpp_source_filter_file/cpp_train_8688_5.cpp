#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200 + 10;
const int INF = 2e9;
int h, t, r, n, m, hi[MAXN][MAXN];
pair<int, int> a[MAXN], b[MAXN];
vector<pair<int, int>> g[MAXN][MAXN];
bool visited[MAXN][MAXN], en[MAXN][MAXN];
void bfs(pair<int, int> st) {
  memset(hi, -1, sizeof hi);
  queue<pair<int, int>> q;
  q.push(st);
  hi[st.first][st.second] = 0;
  while (!q.empty()) {
    pair<int, int> v = q.front();
    for (auto u : g[v.first][v.second]) {
      if (hi[u.first][u.second] == -1) {
        hi[u.first][u.second] = hi[v.first][v.second] + 1;
        q.push(u);
      }
    }
    q.pop();
  }
}
void dfs(pair<int, int> v) {
  visited[v.first][v.second] = true;
  hi[v.first][v.second] = 0;
  for (auto u : g[v.first][v.second]) {
    if (!visited[u.first][u.second]) {
      dfs(u);
    } else if (!en[u.first][u.second]) {
      cout << "Draw";
      exit(0);
    }
    hi[v.first][v.second] =
        max(hi[v.first][v.second], hi[u.first][u.second] + 1);
  }
  en[v.first][v.second] = true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> h >> t >> r >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  for (int i = 0; i <= r; i++) {
    for (int j = 0; i + j <= r; j++) {
      for (int k = 1; k <= n; k++) {
        if (i - k < 0) continue;
        if (i - k + a[k].first > 200 || j + a[k].second > 200) {
          g[i][j].push_back({200, 200});
        } else {
          g[i][j].push_back({i - k + a[k].first, j + a[k].second});
        }
      }
      for (int k = 1; k <= m; k++) {
        if (j - k < 0) continue;
        if (i + a[k].first > 200 || j - k + a[k].second > 200) {
          g[i][j].push_back({200, 200});
        } else {
          g[i][j].push_back({i + a[k].first, j - k + a[k].second});
        }
      }
    }
  }
  bfs({h, t});
  if (hi[0][0] != -1) {
    cout << "Ivan" << '\n';
    cout << hi[0][0];
    return 0;
  }
  dfs({h, t});
  cout << "Zmey" << '\n';
  cout << hi[h][t];
  return 0;
}
