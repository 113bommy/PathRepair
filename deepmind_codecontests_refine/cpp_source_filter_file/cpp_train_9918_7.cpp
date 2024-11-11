#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;
int a[N], n, x;
int c[N][2];
int ans[N], sum;
int h[N], tot;
struct edge {
  int y, next;
} g[N * 2];
void dfs(int x, int kd) {
  if (kd) sum = (sum + x) % (2 * n);
  ans[x] = kd;
  for (int i = h[x]; i; i = g[i].next)
    if (ans[g[i].y] == -1) dfs(g[i].y, kd ^ 1);
}
void adp(int x, int y) {
  g[++tot].y = y;
  g[tot].next = h[x];
  h[x] = tot;
  g[++tot].y = x;
  g[tot].next = h[y];
  h[y] = tot;
}
int main() {
  scanf("%d", &n);
  if (n & 1) {
    printf("Second\n");
    fflush(stdout);
    for (int i = 1; i <= 2 * n; i++) {
      scanf("%d", &x);
      c[x][++c[x][0]] = i;
    }
    for (int i = 1; i <= n; i++) adp(i, i + n);
    for (int i = 1; i <= n; i++) adp(c[i][1], c[i][2]);
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n * 2; i++)
      if (ans[i] == -1) dfs(i, 1);
    if (sum) {
      for (int i = 1; i <= 2 * n; i++) ans[i] ^= 1;
    }
    for (int i = 1; i <= n * 2; i++)
      if (ans[i] == 1) printf("%d ", i);
    printf("\n");
  } else {
    printf("First\n");
    for (int i = 1; i <= n; i++) printf("%d ", i);
    for (int i = 1; i <= n; i++) printf("%d ", i);
  }
}
