#include <bits/stdc++.h>
int first[100010], next[100010], ev[100010], cnt, num[100010];
void add(int u, int v) {
  next[cnt] = first[u];
  ev[cnt] = v;
  first[u] = cnt++;
}
void dfs(int u, int f) {
  for (int i = first[u]; i != -1; i = next[i])
    if (ev[i] != f) {
      num[ev[i]] = num[u] + 1;
      dfs(ev[i], u);
    }
}
int main() {
  int n, a, b;
  scanf("%d", &n);
  memset(first, -1, sizeof(first));
  num[1] = 1;
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &a, &b);
    add(a, b);
    add(b, a);
  }
  dfs(1, -1);
  double ans = 0;
  for (int i = 1; i <= n; i++) ans += 1.0 / num[i];
  printf("%.8lf\n", ans);
  return 0;
}
