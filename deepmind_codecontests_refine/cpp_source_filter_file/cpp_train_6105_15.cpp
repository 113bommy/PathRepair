#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 30;
int a[N][N][M];
int head[N], len = 0;
int in[N];
struct Edge {
  int v, c, nx;
} e[N * N];
int dfs(int x, int y, int pre) {
  if (a[x][y][pre] != 0) return a[x][y][pre];
  if (x == y) return a[x][y][pre] = -1;
  if (head[x] == -1) return a[x][y][pre] = -1;
  for (int i = head[x]; ~i; i = e[i].nx) {
    if (e[i].c >= pre) {
      if (dfs(y, e[i].v, e[i].c) == -1) return a[x][y][pre] = 1;
    }
  }
  return a[x][y][pre] = -1;
}
void init() {
  memset(head, -1, sizeof(head));
  len = 0;
}
void addEdge(int u, int v, int c) {
  e[len].v = v;
  e[len].c = c;
  e[len].nx = head[u];
  head[u] = len++;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  init();
  int u, v;
  char c[4];
  for (int i = 0; i < m; i++) {
    scanf("%d%d%s", &u, &v, c);
    addEdge(u, v, c[0] - '0');
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%c", dfs(i, j, 0) == 1 ? 'A' : 'B');
    }
    puts("");
  }
  return 0;
}
