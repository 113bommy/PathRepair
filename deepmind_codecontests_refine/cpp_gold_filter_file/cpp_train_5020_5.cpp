#include <bits/stdc++.h>
using namespace std;
int n, m, q, k;
int a[1000005], f[1000005];
long long s[1000005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= (n); ++i) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
  f[n] = n;
  for (int i = n - 1; i >= (1); --i) {
    f[i] = i;
    while (f[i] != n) {
      if ((s[f[i]] - s[i - 1]) * (f[f[i] + 1] - i + 1) >
          (s[f[f[i] + 1]] - s[i - 1]) * (f[i] - i + 1))
        f[i] = f[f[i] + 1];
      else
        break;
    }
  }
  int pos = 1;
  while (pos <= n) {
    double ans = (double)(s[f[pos]] - s[pos - 1]) / (f[pos] - pos + 1);
    for (int i = pos; i <= (f[pos]); ++i) printf("%.15f\n", ans);
    pos = f[pos] + 1;
  }
  return 0;
}
