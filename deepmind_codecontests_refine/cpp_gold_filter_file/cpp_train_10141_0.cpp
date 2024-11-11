#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
vector<int> g1[2000010];
int dist[2000010], n, m, p, a, b;
int pair_g1[2000010], pair_g2[2000010];
queue<int> fila;
bool bfs() {
  for (int i = 1; i <= n; i++) {
    if (pair_g1[i] == 0) {
      dist[i] = 0;
      fila.push(i);
    } else
      dist[i] = INF;
  }
  dist[0] = INF;
  while (!fila.empty()) {
    int v = fila.front();
    fila.pop();
    for (int i = 0; i < g1[v].size(); i++) {
      int u = g1[v][i];
      if (dist[pair_g2[u]] == INF) {
        dist[pair_g2[u]] = dist[v] + 1;
        fila.push(pair_g2[u]);
      }
    }
  }
  return (dist[0] != INF);
}
bool dfs(int v) {
  if (v) {
    for (int i = 0; i < g1[v].size(); i++) {
      int u = g1[v][i];
      if (dist[pair_g2[u]] == dist[v] + 1) {
        if (dfs(pair_g2[u])) {
          pair_g2[u] = v;
          pair_g1[v] = u;
          return true;
        }
      }
    }
    dist[v] = INF;
    return false;
  }
  return true;
}
int hopcroft_karp() {
  for (int i = 1; i <= n; i++) {
    pair_g1[i] = 0;
    pair_g2[i] = 0;
  }
  int matching = 0;
  while (bfs()) {
    for (int i = 1; i <= n; i++) {
      if (pair_g1[i] == 0)
        if (dfs(i)) matching++;
    }
  }
  return matching;
}
char linha[2000010];
int main(void) {
  scanf("%s", linha);
  n = strlen(linha);
  m = n;
  for (int i = 0; i < n; i++) {
    if (linha[i] == '0') {
      g1[i + 1].push_back((i + 1) % n + 1 + n);
    } else {
      g1[(i + 1) % n + 1].push_back(i + 1 + n);
    }
  }
  printf("%d\n", n - hopcroft_karp());
  return 0;
}
