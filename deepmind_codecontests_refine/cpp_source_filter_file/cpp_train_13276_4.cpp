#include <bits/stdc++.h>
struct edge {
  int to, next;
} e[100001];
int n, m, h[100001], cnt, book[100001], ans, k;
void add(int u, int v) {
  e[++cnt].next = h[u];
  e[cnt].to = v;
  h[u] = cnt;
}
void dfs(int x, int fa) {
  if (book[x]) k = 0;
  book[x]++;
  if (!k) return;
  for (int l = h[x]; l; l = e[l].next) {
    int v = e[l].to;
    if (v == fa) continue;
    dfs(v, x);
  }
  book[x]++;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }
  for (int i = 1; i <= n; i++)
    if (!book[i]) {
      k = 1;
      dfs(i, 0);
      ans += i;
    }
  printf("%d", ans);
  return 0;
}
