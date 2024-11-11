#include <bits/stdc++.h>
int N, max, last, pass, ret;
char seen[200 + 1];
int dist[200 + 1];
int d[200 + 1];
int h[200 + 1];
char adj[200 + 1][200 + 1];
int MAX(int X, int Y) { return X > Y ? X : Y; }
void search(int u) {
  int v;
  for (v = 1; v <= N; v++) {
    if (v != pass && adj[u][v] && dist[v] == 0) {
      dist[v] = dist[u] + 1;
      search(v);
    }
  }
  if (dist[u] > max) {
    max = dist[u];
    last = u;
  }
  dist[u] = 0;
}
int verify(int u) {
  if (u == 1) {
    return 1;
  }
  pass = u;
  max = 0;
  dist[1] = 1;
  search(1);
  max = 0;
  dist[last] = 1;
  search(last);
  return max;
}
void dfs(int u) {
  int v, max0 = 0, max1 = 0;
  d[u] = 1;
  for (v = 1; v <= N; v++) {
    if (adj[u][v] && seen[v] == 0) {
      seen[v] = 1;
      dfs(v);
      if (h[v] > max0) {
        max1 = max0;
        max0 = h[v];
      } else if (h[v] > max1) {
        max1 = h[v];
      }
      d[u] = MAX(d[u], d[v]);
    }
  }
  h[u] = max0 + 1;
  d[u] = MAX(d[u], max0 + max1 + 1);
  ret = MAX(ret, (d[u] - 1) * (verify(u) - 1));
}
int main(void) {
  int i, u, v;
  FILE *f = 1 ? stdin : fopen("1.in", "r");
  fscanf(f, "%d", &N);
  for (i = 1; i < N; i++) {
    fscanf(f, "%d %d", &u, &v);
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  fclose(f);
  seen[1] = 1;
  dfs(1);
  fprintf(stdout, "%d\n", ret);
  fclose(stdout);
  return 0;
}
