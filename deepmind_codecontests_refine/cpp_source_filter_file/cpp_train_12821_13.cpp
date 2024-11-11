#include <bits/stdc++.h>
using namespace std;
int n, R[1010], C[1010], reR[1010], reC[1010], cnt = 0;
struct node {
  int x_1, y_1, x_2, y_2;
  node(int xx_1 = 0, int yy_1 = 0, int xx_2 = 0, int yy_2 = 0) {
    x_1 = xx_1, y_1 = yy_1, x_2 = xx_2, y_2 = yy_2;
  }
} ans[4010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &R[i]), reR[R[i]] = i;
  for (int i = 1; i <= n; i++) scanf("%d", &C[i]), reC[C[i]] = i;
  for (int i = 1; i < n; i++) {
    if (R[i] == i && C[i] == i) continue;
    if (reR[i] == n && reC[i] == n) {
      ans[++cnt] = node(i, n, n, i), R[n] = R[i], C[n] = C[i], reR[R[n]] = n,
      reC[C[n]] = n;
      continue;
    }
    if (reR[i] == n) {
      ans[++cnt] = node(i, reC[i], n, i);
      R[n] = R[i], reR[R[n]] = n;
      C[reC[i]] = C[i], reC[C[reC[i]]] = reC[i];
      continue;
    }
    if (reC[i] == n) {
      ans[++cnt] = node(reR[i], i, i, n);
      C[n] = C[i], reC[C[n]] = n;
      R[reR[i]] = R[i], reR[R[reR[i]]] = reR[i];
      continue;
    }
    ans[++cnt] = node(reR[i], i, i, n);
    ans[++cnt] = node(i, reC[i], n, i);
    int r = reR[i], c = reC[i];
    R[r] = R[n], R[n] = R[i];
    C[c] = C[n], C[n] = C[i];
    reR[R[r]] = r, reC[C[r]] = c;
    reR[R[n]] = n, reC[R[n]] = n;
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++)
    printf("%d %d %d %d\n", ans[i].x_1, ans[i].y_1, ans[i].x_2, ans[i].y_2);
}
