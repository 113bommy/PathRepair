#include <bits/stdc++.h>
using namespace std;
const int K = 1009, N = 12;
const int INF = 1e9;
int k, standard_dist;
char table[K][N][N];
int dist[K][K];
bool used[K];
int parent[K], far[K];
vector<int> order;
void calc_distances() {
  int n, m, w;
  cin >> n >> m >> k >> w;
  standard_dist = n * m;
  for (int t = 1; t <= k; ++t) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> table[t][i][j];
      }
    }
  }
  for (int t1 = 1; t1 <= k; ++t1) {
    for (int t2 = t1 + 1; t2 <= k; ++t2) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (table[t1][i][j] != table[t2][i][j]) dist[t1][t2]++;
        }
      }
      dist[t1][t2] = min(dist[t1][t2] * w, n * m);
      dist[t2][t1] = dist[t1][t2];
    }
  }
}
void dijkstra() {
  far[1] = standard_dist;
  parent[1] = 0;
  for (int i = 2; i <= k; ++i) {
    far[i] = INF;
    parent[i] = 0;
  }
  for (int it = 1; it <= k; ++it) {
    int v = -1;
    for (int j = 1; j <= k; ++j) {
      if (!used[j] && (v == -1 || far[j] < far[v])) v = j;
    }
    used[v] = true;
    order.push_back(v);
    for (int i = 1; i <= k; ++i) {
      if (!used[i] && far[i] > dist[v][i]) {
        far[i] = dist[v][i];
        parent[i] = v;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  calc_distances();
  dijkstra();
  int ans = 0;
  for (int i = 1; i <= k; ++i) ans += far[i];
  cout << ans << '\n';
  for (int to : order) {
    cout << to << ' ';
    if (far[to] == standard_dist)
      cout << 0;
    else
      cout << parent[to];
    cout << '\n';
  }
  return 0;
}
