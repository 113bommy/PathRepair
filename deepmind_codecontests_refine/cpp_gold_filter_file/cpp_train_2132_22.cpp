#include <bits/stdc++.h>
using namespace std;
const int MAXV = 210;
const int MAXE = 300000;
int n, h, a[MAXV], lv[MAXV], parent[MAXV], t[MAXV];
int graph[MAXV][MAXV], used[MAXV][MAXV];
bool prime[MAXE];
int S = MAXV - 1, T = MAXV - 2;
vector<vector<int> > cycles;
void init() {
  memset(graph, 0, sizeof graph);
  memset(used, 0, sizeof used);
  for (int i = 2; i < MAXE; i++)
    for (int j = i + i; j < MAXE; j += i) prime[j] = true;
}
bool bfs() {
  queue<int> qu;
  qu.push(S);
  t[S] = 1;
  parent[S] = -1;
  while (!qu.empty()) {
    int v = qu.front();
    qu.pop();
    for (int i = 0; i < MAXV; i++) {
      if (!t[i] && graph[v][i] != 0) {
        t[i] = t[v] + 1;
        parent[i] = v;
        qu.push(i);
      }
    }
  }
  return t[T] != 0;
}
void get_path_from(int u) {
  t[u] = 1;
  cycles.back().push_back(u);
  for (int i = 0; i < n; i++)
    if (!t[i]) {
      if (graph[u][i] != used[u][i]) get_path_from(i);
    }
}
void solve() {
  if (2 * h != n) {
    printf("Impossible\n");
    return;
  }
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) continue;
      if (!prime[a[i] + a[j]]) {
        if (a[i] & 1) {
          graph[i][j] = used[i][j] = 1;
        } else {
          graph[j][i] = used[j][i] = 1;
        }
      }
    }
  }
  int mf = 0, flow, x;
  while (true) {
    memset(t, 0, sizeof(t));
    if (!bfs()) break;
    flow = INT_MAX;
    x = T;
    while (x != S) {
      flow = min(flow, graph[parent[x]][x]);
      x = parent[x];
    }
    x = T;
    while (x != S) {
      graph[parent[x]][x] -= flow;
      graph[x][parent[x]] += flow;
      x = parent[x];
    }
    mf += flow;
  }
  if (mf != 2 * h) {
    printf("Impossible\n");
    return;
  }
  memset(t, 0, sizeof(t));
  for (i = 0; i < n; i++)
    if (!t[i]) {
      cycles.push_back(vector<int>());
      get_path_from(i);
    }
  printf("%d\n", (int)cycles.size());
  for (i = 0; i < (int)cycles.size(); i++) {
    printf("%d ", (int)cycles[i].size());
    for (j = 0; j < (int)cycles[i].size(); j++) {
      if (j) printf(" ");
      printf("%d", 1 + cycles[i][j]);
    }
    printf("\n");
  }
}
int main() {
  init();
  scanf("%d", &n);
  h = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] & 1) {
      graph[S][i] = 2;
      h++;
    } else {
      graph[i][T] = 2;
    }
  }
  solve();
  return 0;
}
