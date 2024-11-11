#include <bits/stdc++.h>
int ans[200000][3];
int a[200000], b[200000];
int n, m, x, y;
int main() {
  int top = 0;
  scanf("%d %d %d %d", &n, &m, &x, &y);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int j = 1; j <= m; j++) scanf("%d", &b[j]);
  int now = 1;
  for (int i = 1; i <= n; i++) {
    if (now > m) break;
    if (b[now] >= a[i] - x && b[now] <= a[i] + y) {
      top++;
      ans[top][0] = now;
      ans[top][1] = i;
      now++;
      continue;
    } else if (b[now] < a[i] - x) {
      while (b[now] < a[i] - x && now <= m) now++;
      if (now > m) break;
      if (b[now] >= a[i] - x && b[now] <= a[i] + y) {
        top++;
        ans[top][0] = now;
        ans[top][1] = i;
        now++;
        continue;
      }
    }
  }
  printf("%d\n", top);
  for (int i = 1; i <= top; i++) {
    printf("%d %d\n", ans[i][1], ans[i][0]);
  }
}
