#include <bits/stdc++.h>
using namespace std;
const int N = 600 + 10;
int n, vist[N];
int dis[N][N];
deque<int> path;
vector<vector<pair<int, int>>> v, v2;
int get_path(int start, int end, int val) {
  if (start == end) {
    path.push_front(start);
    return 2e9;
  }
  if (vist[start]) return 0;
  vist[start] = 1;
  for (int i = 0; i <= 2 * n + 1; i++) {
    if (v[start][i].first != 0 && v[start][i].second <= val) {
      int res = get_path(i, end, val);
      if (res != 0) {
        res = min(res, v[start][i].first);
        path.push_front(start);
        return res;
      }
    }
  }
  return 0;
}
int max_flow(int val, int start = 0, int end = 2 * n + 1) {
  int mxflow = 0;
  while (1) {
    memset(vist, 0, sizeof vist);
    path.clear();
    int newflow = get_path(start, end, val);
    if (newflow == 0) return mxflow;
    mxflow += newflow;
    for (int i = 0; i < path.size() - 1; i++) {
      v[path[i]][path[i + 1]].first -= newflow;
      v[path[i + 1]][path[i]].first += newflow;
    }
  }
}
void floyed() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m, t, k;
  cin >> n >> m >> t >> k;
  v2.resize(2 * n + 2, vector<pair<int, int>>(2 * n + 2, {0, 0}));
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    v2[0][x].first++;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dis[i][j] = ((i == j) ? 0 : 1e9);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    dis[u][v] = min(dis[u][v], c);
    dis[v][u] = min(dis[v][u], c);
  }
  floyed();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      v2[i][j + n].second = dis[i][j];
      v2[i][j + n].first = 500;
    }
    v2[i + n][2 * n + 1].first = 1;
  }
  int low = 0, high = 1731311;
  int ans = -1;
  while (low <= high) {
    v = v2;
    int mid = (low + high) / 2;
    if (max_flow(mid) >= k) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  cout << ans << "\n";
  return 0;
}
