#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10;
const int N = 5e2 + 10;
struct Edge {
  int v;
  int nex;
} edge[M];
int head[N], tol;
int n, m;
void init() {
  tol = 0;
  memset(head, -1, sizeof(head));
}
void add(int u, int v) {
  edge[tol].v = v;
  edge[tol].nex = head[u];
  head[u] = tol++;
}
bool flag;
int col[N];
void DFS(int u) {
  if (!flag) return;
  for (int i = head[u]; ~i; i = edge[i].nex) {
    int v = edge[i].v;
    if (col[v] == -1) {
      col[v] = 1 - col[u];
      DFS(v);
    } else {
      if (col[v] == col[u]) {
        flag = false;
        return;
      }
    }
  }
}
bool vis[N];
int ma[N][N];
int main() {
  int u, v;
  scanf("%d%d", &n, &m);
  memset(ma, 0, sizeof(ma));
  while (m--) {
    scanf("%d%d", &u, &v);
    ma[u][v] = ma[v][u] = 1;
  }
  init();
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (!ma[i][j]) {
        vis[i] = vis[j] = true;
        add(i, j);
      }
    }
  }
  flag = true;
  memset(col, -1, sizeof(col));
  for (int i = 1; i <= n; i++) {
    if (col[i] != -1 || !vis[i]) continue;
    col[i] = 1;
    DFS(i);
    if (!flag) {
      puts("No");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (ma[i][j]) {
        if ((col[i] == 1 && col[j] == 0) || (col[i] == 0 && col[j] == 1)) {
          puts("No");
          return 0;
        }
      }
    }
  }
  puts("Yes");
  for (int i = 1; i <= n; i++) {
    if (col[i] == 1)
      printf("a");
    else if (!col[i])
      printf("c");
    else
      printf("b");
  }
  return 0;
}
