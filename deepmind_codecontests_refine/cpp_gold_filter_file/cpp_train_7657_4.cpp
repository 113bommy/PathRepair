#include <bits/stdc++.h>
const int max_n = 1000100;
int n;
int color[max_n];
int d[max_n];
std::vector<int> T[max_n];
int ans;
int dfs_one(int v, int u) {
  int m_depth = 0;
  for (int i = 0; i < T[v].size(); ++i) {
    if (T[v][i] != u) {
      int ret = dfs_one(T[v][i], v) + (color[v] != color[T[v][i]]);
      if (ret > m_depth) m_depth = ret;
    }
  }
  return d[v] = m_depth;
}
void dfs_two(int v, int u, int up_depth) {
  int worst = up_depth;
  int first = up_depth;
  int second = 0;
  for (int i = 0; i < T[v].size(); ++i) {
    if (T[v][i] != u) {
      int cost = d[T[v][i]] + (color[v] != color[T[v][i]]);
      if (cost > first) {
        second = first;
        first = cost;
      } else if (cost > second) {
        second = cost;
      }
      worst = std::max(worst, cost);
    }
  }
  ans = std::min(ans, worst);
  for (int i = 0; i < T[v].size(); ++i) {
    if (T[v][i] != u) {
      int cost = d[T[v][i]] + (color[v] != color[T[v][i]]);
      int dp = first;
      if (cost == dp) dp = second;
      dfs_two(T[v][i], v, dp + (color[v] != color[T[v][i]]));
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", color + i);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u;
    --v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs_one(0, 0);
  ans = n;
  dfs_two(0, 0, 0);
  printf("%d\n", ans);
  return 0;
}
