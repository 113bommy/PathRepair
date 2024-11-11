#include <bits/stdc++.h>
int N, head[101], next[199], to[199], id[199], E, q[101], fa[101], fe[101];
double O[101];
int main() {
  scanf("%d", &N);
  for (int i = 1, u, v; i < N; i++) {
    scanf("%d%d", &u, &v);
    next[++E] = head[u], to[E] = v, id[E] = i, head[u] = E;
    next[++E] = head[v], to[E] = u, id[E] = i, head[v] = E;
  }
  q[1] = 1;
  int H = 0, T = 1;
  while (H < T)
    for (int u = q[++H], e = head[u]; e; e = next[e])
      if (to[e] != fa[u]) {
        fa[q[++T] = to[e]] = u;
        fe[to[e]] = id[e];
      }
  for (int i = 1; i <= N; i++) {
    int u = q[i];
    double w = O[u] > 1 ? O[u] - 1 : O[u] + 1;
    int branch = 0;
    for (int e = head[u]; e; e = next[e]) branch++;
    for (int e = head[u]; e; e = next[e])
      if (to[e] != fa[u]) {
        if ((w += 2.0 / branch) >= 2) w -= 2;
        O[to[e]] = w;
      }
  }
  printf("%d\n", N - 1);
  for (int i = 2; i <= N; i++)
    printf("1 %d %d %d %.10lf\n", fe[i], O[i] > 1 ? fa[i] : i,
           O[i] > 1 ? i : fa[i], O[i] > 1 ? O[i] - 1 : O[i]);
  return 0;
}
