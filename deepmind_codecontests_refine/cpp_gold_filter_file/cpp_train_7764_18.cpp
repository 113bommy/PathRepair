#include <bits/stdc++.h>
using namespace std;
long long n;
long long mi[65];
int q;
char s[110000];
long long now_to_haha(long long x) {
  long long sumh;
  for (int i = 0; i <= 62; i++) {
    if (mi[i] == n + 1) {
      sumh = i;
      break;
    }
  }
  long long h;
  for (int i = 62; i >= 0; i--) {
    if (x % mi[i] == 0) {
      h = i;
      break;
    }
  }
  long long d = (x - mi[h]) / mi[h + 1] + 1;
  h = sumh - h;
  long long ret = mi[h - 1] + (d - 1);
  return ret;
}
int main() {
  mi[0] = 1;
  mi[1] = 2;
  for (int i = 2; i <= 62; i++) mi[i] = mi[i - 1] * 2;
  while (scanf("%I64d %d", &n, &q) != EOF) {
    long long p = (n + 1) / 2;
    while (q--) {
      long long now;
      scanf("%I64d", &now);
      scanf("%s", s);
      int len = strlen(s);
      now = now_to_haha(now);
      for (int i = 0; i < len; i++) {
        if (s[i] == 'U' && now != 1)
          now = now / 2;
        else if (s[i] == 'L' && now < p)
          now = now * 2;
        else if (s[i] == 'R' && now < p)
          now = now * 2 + 1;
      }
      long long nowh;
      for (nowh = 0;; nowh++) {
        if (now >= mi[nowh] && now <= mi[nowh + 1] - 1) break;
      }
      nowh++;
      long long nowd = now - mi[nowh - 1] + 1;
      long long ans = p;
      long long xun = nowh - 1;
      while (xun > 0) {
        ans /= 2;
        xun--;
      }
      long long sumh;
      for (int t = 0;; t++) {
        if ((n + 1) == mi[t]) {
          sumh = t;
          break;
        }
      }
      nowh = sumh - nowh;
      ans += (nowd - 1) * mi[nowh + 1];
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
