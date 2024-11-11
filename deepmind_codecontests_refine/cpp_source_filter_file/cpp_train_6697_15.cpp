#include <bits/stdc++.h>
struct {
  int to, next;
} edge[100100];
int head[50100];
long long dps[50100][550];
int cnt, k;
long long ans;
void add(int a, int b) {
  edge[cnt].to = b;
  edge[cnt].next = head[a];
  head[a] = cnt++;
  edge[cnt].to = a;
  edge[cnt].next = head[b];
  head[b] = cnt++;
}
void dp(int u, int p) {
  int i, j;
  dps[u][0] = 1;
  for (i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == p) continue;
    dp(v, u);
    for (j = 0; j < k; j++) ans += dps[u][j] * dps[v][k - j - 1];
    for (j = 1; j <= k; j++) dps[u][j] += dps[v][j - 1];
  }
}
int main() {
  int i, j, n, a, b;
  scanf("%d %d", &n, &k);
  cnt = 1;
  for (i = 1; i < k; i++) {
    scanf("%d %d", &a, &b);
    add(a, b);
  }
  dp(1, 0);
  printf("%I64d\n", ans);
}
