#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], s[100010], d[100010], q[100010], t, n, j, mi, ans, L,
    R, M;
int main() {
  scanf("%d", &n);
  ans = 1000000000;
  for (int i = (0); i <= (n + 1); i++) scanf("%d", &s[i]);
  for (int i = (1); i <= (n); i++) scanf("%d", &d[i]);
  d[0] = 1000000000;
  d[n + 1] = 1000000000;
  b[n] = n + 1;
  for (int i = (2); i <= (n); i++) {
    j = i - 1;
    while ((s[i] - s[a[j]]) / 2 > d[j]) j = a[j];
    a[i] = j;
  }
  for (int i = (n - 1); i >= (1); i--) {
    j = i + 1;
    while ((s[b[j]] - s[i]) / 2 > d[j]) j = b[j];
    b[i] = j;
  }
  for (int i = (0); i <= (n + 1); i++)
    a[i] = s[a[i]] + d[i] * 2, b[i] = s[b[i]] - d[i] * 2;
  for (int i = (1); i <= (n + 1); i++) {
    if (a[i - 1] > s[i - 1]) {
      while (t && a[q[t]] < a[i - 1]) t--;
      q[++t] = i - 1;
    }
    if (b[i] < s[i]) {
      for (L = 1, R = t, M = (L + R + 1) / 2; L < R; M = (L + R + 1) / 2)
        if (b[i] <= a[q[M]])
          L = M;
        else
          R = M - 1;
      if (s[i] - s[q[M]] < ans) ans = s[i] - s[q[M]];
      for (L = 1, R = t, M = (L + R + 1) / 2; L < R; M = (L + R + 1) / 2)
        if (s[i] <= a[q[M]])
          L = M;
        else
          R = M - 1;
      if (b[i] <= s[q[M]] && (i != n + 1 || q[M] != 0)) {
        printf("0\n");
        return 0;
      }
    }
  }
  printf("%lf\n", 1.0 * ans / 2);
}
