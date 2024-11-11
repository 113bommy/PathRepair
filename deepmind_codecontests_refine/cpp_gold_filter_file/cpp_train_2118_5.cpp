#include <bits/stdc++.h>
int cnt[111], ans, b, d, pr[111], v[111];
int main() {
  scanf("%d%d", &b, &d);
  int k = b;
  for (int i = 2; k > 1; i++) {
    if (k % i) continue;
    while (k % i == 0) cnt[i]++, k /= i;
  }
  bool flag = true;
  k = d;
  for (int i = 2; k > 1; i++) {
    if (k % i) continue;
    int x = 1;
    while (k % i == 0) pr[i]++, k /= i, x *= i;
    v[x] = -i;
    if (cnt[i] == 0) {
      flag = false;
      continue;
    }
    int p = (pr[i] - 1) / cnt[i] + 1;
    if (p > ans) ans = p;
  }
  if (flag)
    printf("2-type\n%d\n", ans);
  else {
    if (b % d == 1)
      printf("3-type\n");
    else if ((b + 1) % d == 0)
      printf("11-type\n");
    else {
      flag = true;
      for (int i = 2; i <= d; i++) {
        if (v[i] >= 0 || cnt[-v[i]] || b % i == 1 || (b + 1) % i == 0) continue;
        flag = false;
        break;
      }
      if (flag)
        printf("6-type\n");
      else
        printf("7-type\n");
    }
  }
}
