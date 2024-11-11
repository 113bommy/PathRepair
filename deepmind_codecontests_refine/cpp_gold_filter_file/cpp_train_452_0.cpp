#include <bits/stdc++.h>
using namespace std;
long long a[30] = {0}, b[30];
int main() {
  int n, i, j, k, ct;
  long long ans = 0;
  bool flag;
  scanf("%d", &n);
  b[0] = 1;
  for (i = 1; i < 30; ++i) b[i] = b[i - 1] * 2;
  for (i = 0; i < n; ++i) {
    flag = 0;
    ct = 0;
    scanf("%d", &j);
    while (1) {
      for (k = 0; k < 20; ++k)
        if (b[k] == j) {
          flag = 1;
          break;
        }
      if (flag) break;
      if (j & 1) {
        j /= 2;
        ct++;
      } else
        j /= 2;
    }
    a[ct]++;
  }
  for (i = 0; i < 30; ++i) {
    if (a[i]) ans += a[i] * (a[i] - 1) / 2;
  }
  printf("%I64d\n", ans);
  return 0;
}
