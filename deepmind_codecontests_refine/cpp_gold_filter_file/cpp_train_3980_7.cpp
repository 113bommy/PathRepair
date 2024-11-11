#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
const int K = 40;
int n, m, k, q;
int c[N][N];
vector<int> g[N * N + K];
void add_edge(int v, int u) {
  g[v].push_back(u);
  g[u].push_back(v);
}
void build_g() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      add_edge(i * m + j, n * m + c[i][j]);
      int dx[4] = {-1, 0, +1, 0};
      int dy[4] = {0, +1, 0, -1};
      for (int t = 0; t < 4; ++t) {
        int ni = i + dx[t];
        int nj = j + dy[t];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
          if (i * m + j > ni * m + nj) {
            add_edge(i * m + j, ni * m + nj);
          }
        }
      }
    }
  }
}
const int INF = 1e9;
int dist[N * N + K];
void bfs(int s, int i) {
  deque<int> d;
  fill(dist, dist + n * m + k, INF);
  dist[s] = 0;
  d.push_back(s);
  while (!d.empty()) {
    int v = d.front();
    d.pop_front();
    for (int u : g[v]) {
      int w = (u < n * m);
      if (dist[u] > dist[v] + w) {
        dist[u] = dist[v] + w;
        if (w == 0) {
          d.push_front(u);
        } else {
          d.push_back(u);
        }
      }
    }
  }
}
const int Q = 1e5;
int qs[Q][4], ans[Q];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c[i][j];
      --c[i][j];
    }
  }
  build_g();
  cin >> q;
  for (int i = 0; i < q; ++i) {
    for (int t = 0; t < 4; ++t) {
      cin >> qs[i][t];
      --qs[i][t];
    }
    ans[i] = abs(qs[i][0] - qs[i][2]) + abs(qs[i][1] - qs[i][3]);
  }
  for (int f = 0; f < k; ++f) {
    bfs(n * m + f, f);
    for (int i = 0; i < q; ++i) {
      ans[i] = min(ans[i], dist[qs[i][0] * m + qs[i][1]] - 1 +
                               dist[qs[i][2] * m + qs[i][3]]);
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
