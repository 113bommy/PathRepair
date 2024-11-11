#include <bits/stdc++.h>
using namespace std;
vector<int> G[10100];
int n, match[10100], dist[10100];
bool bfs() {
  int i, u, v, len;
  queue<int> Q;
  for (i = 1; i <= n; i++) {
    if (match[i] == 0) {
      dist[i] = 0;
      Q.push(i);
    } else
      dist[i] = (1 << 28);
  }
  dist[0] = (1 << 28);
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    if (u != 0) {
      len = G[u].size();
      for (i = 0; i < len; i++) {
        v = G[u][i];
        if (dist[match[v]] == (1 << 28)) {
          dist[match[v]] = dist[u] + 1;
          Q.push(match[v]);
        }
      }
    }
  }
  return (dist[0] != (1 << 28));
}
bool dfs(int u) {
  int i, v, len;
  if (u != 0) {
    len = G[u].size();
    for (i = 0; i < len; i++) {
      v = G[u][i];
      if (dist[match[v]] == dist[u] + 1) {
        if (dfs(match[v])) {
          match[v] = u;
          match[u] = v;
          return true;
        }
      }
    }
    dist[u] = (1 << 28);
    return false;
  }
  return true;
}
int hopcroft_karp() {
  int matching = 0, i;
  memset(match, 0, sizeof(match));
  while (bfs())
    for (i = 1; i <= n; i++)
      if (match[i] == 0 && dfs(i)) matching++;
  return matching;
}
int xxx[10100 / 2][2];
int main() {
  int tt;
  scanf("%d %d", &n, &tt);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &xxx[i][0]);
    xxx[i][1] = xxx[i][0];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (xxx[i][0] != xxx[j][1]) {
        G[i + 1].push_back(n + j + 1);
      }
    }
  }
  printf("%d\n", hopcroft_karp());
  for (int i = 0; i < n; ++i) {
    if (match[i] != 0)
      printf("%d %d\n", xxx[i][0], xxx[match[i] - n - 1][1]);
    else
      printf("%d %d\n", xxx[i][0], xxx[i][0]);
  }
  return 0;
}
