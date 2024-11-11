#include <bits/stdc++.h>
int num[1005], vis[1005];
int main() {
  int n, k, step = 9999, in;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  for (int i = 1; i <= n; i++) {
    int t = i, ans = 0, temp = 1;
    vis[t] = num[t];
    while (t != 1) {
      if (num[t - 1] + k != vis[t]) ans++;
      vis[t - 1] = vis[t] - k;
      if (vis[t - 1] <= 0) {
        temp = 0;
        break;
      }
      t--;
    }
    if (!temp) continue;
    t = i;
    while (t != n) {
      if (vis[t] + k != num[t + 1]) ans++;
      vis[t + 1] = vis[t] + k;
      t++;
    }
    if (ans < step) {
      step = ans;
      in = i;
    }
  }
  printf("%d\n", step);
  int t = in;
  while (t != 1) {
    int ans = num[t - 1] + k - num[t];
    if (ans > 0) printf("- %d %d\n", t - 1, ans);
    if (ans < 0) printf("+ %d %d\n", t - 1, -ans);
    num[t - 1] = num[t] - k;
    t--;
  }
  t = in;
  while (t != n) {
    int ans = num[t] + k - num[t + 1];
    if (ans > 0) printf("+ %d %d\n", t + 1, ans);
    if (ans < 0) printf("- %d %d\n", t + 1, -ans);
    num[t + 1] = num[t] + k;
    t++;
  }
  return 0;
}
