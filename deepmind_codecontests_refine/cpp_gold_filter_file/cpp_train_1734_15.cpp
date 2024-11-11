#include <bits/stdc++.h>
using namespace std;
int a[35][200005];
int min_ans = 20;
int b[35];
int ans[35];
void dfs(int x, int n, int val) {
  if (x >= min_ans) return;
  if (n == 1) {
    min_ans = x;
    memcpy(ans, b, sizeof(ans));
    return;
  }
  int i;
  for (i = 0; i < n; i++) {
    if (a[x][i] % 2 != 0) break;
  }
  if (i == n) {
    for (i = 0; i < n; i++) {
      a[x][i] /= 2;
    }
    dfs(x, n, val + 1);
    return;
  }
  for (i = 0; i < n; i++) {
    if (a[x][i] % 2 != 0) {
      a[x + 1][i] = (a[x][i] + 1) / 2;
    } else {
      a[x + 1][i] = a[x][i] / 2;
    }
  }
  sort(a[x + 1], a[x + 1] + n);
  int newn = unique(a[x + 1], a[x + 1] + n) - a[x + 1];
  b[x] = -(1 << val);
  dfs(x + 1, newn, val + 1);
  for (i = 0; i < n; i++) {
    if (a[x][i] % 2 != 0) {
      a[x + 1][i] = (a[x][i] - 1) / 2;
    } else {
      a[x + 1][i] = a[x][i] / 2;
    }
  }
  sort(a[x + 1], a[x + 1] + n);
  newn = unique(a[x + 1], a[x + 1] + n) - a[x + 1];
  b[x] = (1 << val);
  dfs(x + 1, newn, val + 1);
}
int main() {
  int n;
  scanf("%d", &n);
  int i;
  a[0][0] = 0;
  for (i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    a[0][i] = x;
  }
  sort(a[0], a[0] + n + 1);
  n = unique(a[0], a[0] + n + 1) - a[0];
  dfs(0, n, 0);
  printf("%d\n", min_ans);
  for (i = 0; i < min_ans; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
