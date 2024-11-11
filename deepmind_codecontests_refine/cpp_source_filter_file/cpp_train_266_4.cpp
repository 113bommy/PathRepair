#include <bits/stdc++.h>
const int INF = 1000000666;
int n, k, l;
std::vector<std::vector<int> > g;
int dist[20][20];
int distance[10005];
void bfs(int start) {
  for (int i = 0; i < (10005); ++i) distance[i] = INF;
  distance[start] = 0;
  std::queue<int> que;
  que.push(start);
  while ((int)(que).size()) {
    int v = que.front();
    que.pop();
    for (auto &ch : g[v]) {
      if (distance[ch] == INF) {
        distance[ch] = distance[v] + 1;
        que.push(ch);
      }
    }
  }
}
long long dp[1 << 20];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> k >> l;
  std::vector<bool> need(n + 1);
  for (int i = 0; i < (k); ++i) {
    int a;
    std::cin >> a;
    need[a] = true;
  }
  std::vector<int> mv;
  for (int i = 0; i < (l); ++i) {
    int a;
    std::cin >> a;
    mv.push_back(a);
  }
  need.push_back(false);
  std::vector<int> A(n + 2);
  std::vector<int> bad;
  for (int i = (1); i < (n + 2); ++i) {
    if (need[i] != need[i - 1]) A[i] = 1, bad.push_back(i);
  }
  g.resize(n + 2);
  for (auto &jump : mv) {
    for (int j = 0; j < (n + 2); ++j) {
      if (j + jump > n + 1) break;
      g[j].push_back(j + jump);
      g[j + jump].push_back(j);
    }
  }
  assert((int)(bad).size() <= 20);
  for (int i = 0; i < ((int)(bad).size()); ++i) {
    bfs(bad[i]);
    for (int j = (i + 1); j < ((int)(bad).size()); ++j)
      dist[i][j] = dist[j][i] = distance[bad[j]];
  }
  for (int i = 0; i < (1 << (int)(bad).size()); ++i) dp[i] = INF;
  dp[0] = 0;
  for (int mask = (1); mask < (1 << (int)(bad).size()); ++mask)
    if (__builtin_popcount(mask) % 2 == 0) {
      int fs = -1;
      for (int i = 0; i < ((int)(bad).size()); ++i) {
        if (mask & (1 << i)) {
          fs = i;
          break;
        }
      }
      for (int i = 0; i < ((int)(bad).size()); ++i)
        if ((mask & (1 << i)) && fs != i) {
          dp[mask] =
              std::min(dp[mask ^ (1 << fs) ^ (1 << i)] + dist[fs][i], dp[mask]);
        }
    }
  std::cout << (dp[(1 << (int)(bad).size()) - 1] >= INF
                    ? -1
                    : dp[(1 << (int)(bad).size()) - 1])
            << "\n";
  return 0;
}
