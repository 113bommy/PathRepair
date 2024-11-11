#include <bits/stdc++.h>
using namespace std;
int a[10005];
int s[10005];
int main() {
  int i;
  int n, k;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + 1 + n);
  for (i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  double nl, nr;
  double x;
  double ans = 0;
  for (i = 0; i < n; i++) {
    nl = i;
    nr = n - nl;
    assert(nr > 0);
    x = ((s[n] - s[i]) * nl - (s[i]) * nr) / (nl + nr * (1 - k / 100.f));
    if (a[i] <= (s[n] - s[i] - x) / nr) {
      if (ans < (s[n] - s[i] - x) / nr) {
        if (a[i + 1] >= (s[n] - s[i] - x) / nr) ans = (s[n] - s[i] - x) / nr;
      }
    }
  }
  printf("%f\n", ans);
  return 0;
}
