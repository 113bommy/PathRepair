#include <bits/stdc++.h>
using namespace std;
const int MAX_INT = 1 << 30;
const int maxn = 1e6 + 10;
int p[maxn], ans;
void getprime() {
  for (int i = 1; i <= 1e6; i++) p[i] = 1;
  p[1] = 0;
  for (int i = 2; i * i <= 1e6; i++) {
    if (!p[i]) continue;
    for (int j = i * i; j <= 1e6; j += i) p[j] = 0;
  }
}
int main() {
  int x2, xx2;
  scanf("%d", &x2);
  getprime();
  int i = 2;
  xx2 = x2;
  ans = MAX_INT;
  while (i * i <= x2) {
    if (x2 % i == 0) {
      int t = xx2 / i;
      for (int x1 = (t - 1) * i + 1; x1 <= xx2; x1++) {
        if (p[x1]) continue;
        int ii = 2, xx1 = x1;
        while (ii * ii <= xx1) {
          if (xx1 % ii == 0) {
            int tt = x1 / ii;
            ans = min(ans, (tt - 1) * ii + 1);
            while (xx1 % ii == 0) xx1 /= ii;
          }
          ii++;
        }
        if (xx1 > 1) ans = min(ans, (x1 / xx1 - 1) * xx1 + 1);
      }
      while (x2 % i == 0) x2 /= i;
    }
    i++;
  }
  if (x2 > 1) {
    int t = xx2 / x2;
    for (int x1 = (t - 1) * x2 + 1; x1 <= xx2; x1++) {
      if (p[x1]) continue;
      int ii = 2, xx1 = x1;
      while (ii * ii <= xx1) {
        if (xx1 % ii == 0) {
          int tt = x1 / ii;
          ans = min(ans, (tt - 1) * ii + 1);
          while (xx1 % ii == 0) xx1 /= ii;
        }
        ii++;
      }
      if (xx1 > 1) ans = min(ans, (x1 / xx1 - 1) * xx1 + 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
