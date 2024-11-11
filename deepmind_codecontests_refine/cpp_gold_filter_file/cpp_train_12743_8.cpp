#include <bits/stdc++.h>
int list[4020];
int Abs(int x) { return x > 0 ? x : -x; }
int main() {
  int n;
  scanf("%d", &n);
  int size = 0;
  int cnt = 0;
  for (int i = 1; i <= 2 * n; i++) {
    char buf[110];
    scanf("%s", buf);
    for (int j = 0; buf[j]; j++) {
      if (buf[j] == '.') {
        int t = (buf[j + 1] - '0') * 100 + (buf[j + 2] - '0') * 10 +
                (buf[j + 3] - '0');
        if (t != 0)
          list[++size] = t;
        else
          cnt++;
        break;
      }
    }
  }
  int sum = 0;
  for (int i = 1; i <= size; i++) {
    sum -= list[i];
  }
  int ans = 0x7fffffff;
  if (cnt >= n) ans = Abs(sum);
  int k = 2 * n - cnt;
  for (int j = 1; j <= k; j++) {
    sum += 1000;
    if (j + cnt >= n && j <= n) {
      int tmp = Abs(sum);
      if (tmp < ans) ans = tmp;
    }
  }
  printf("%.3lf\n", ans / 1000.0);
  return 0;
}
