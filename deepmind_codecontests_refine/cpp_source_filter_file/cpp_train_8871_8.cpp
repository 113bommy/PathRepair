#include <bits/stdc++.h>
int graph[3000][3000], size[3000] = {0}, dist[3000] = {1234567},
                       visit[3000] = {0}, tra[10000] = {0}, pre[3000] = {0},
                       prev1[3000] = {0};
int r = 0, t = 0;
int n;
int flag = 0;
void dfs(int b, int prev) {
  int i, r = 0;
  visit[b] = 1;
  for (i = 0; i < size[b]; i++) {
    if (visit[graph[b][i]] == 0) {
      prev1[graph[b][i]] = b;
      dfs(graph[b][i], b);
    } else if (visit[graph[b][i]] > 0 && graph[b][i] != prev && flag == 0) {
      pre[t++] = graph[b][i];
      pre[t++] = b;
      int ans = b;
      flag = 1;
      while (prev1[ans] != graph[b][i]) {
        pre[t++] = prev1[ans];
        ans = prev1[ans];
      }
      return;
    }
  }
  return;
}
void dfs1(int b) {
  int i, r = 0;
  for (i = 0; i < size[b]; i++) {
    if (dist[graph[b][i]] > dist[b] + 1) {
      dist[graph[b][i]] = dist[b] + 1;
      dfs1(graph[b][i]);
    }
  }
}
int main() {
  scanf("%d", &n);
  int i, j, k;
  int in = -1;
  for (i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    graph[a][size[a]++] = b;
    graph[b][size[b]++] = a;
  }
  for (i = 1; i <= n; i++) {
    dist[i] = 1234567;
  }
  int flag1 = 0;
  for (i = 1; i <= n; i++) {
    if (size[i] == 1) {
      in = i;
      dfs(in, -1);
      flag1 = 1;
      break;
    }
  }
  if (flag == 0) {
    for (i = 1; i <= n; i++) {
      printf("0 ");
    }
    return 0;
  }
  for (i = 0; i < t; i++) {
    dist[pre[i]] = 0;
  }
  for (i = 0; i < t; i++) {
    dfs1(pre[i]);
  }
  for (i = 1; i <= n; i++) {
    printf("%d ", dist[i]);
  }
  return 0;
}
