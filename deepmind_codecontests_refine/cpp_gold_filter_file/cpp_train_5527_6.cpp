#include <bits/stdc++.h>
using namespace std;
int n, m, x = 0, a[200000], all[200000], light[200000];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  all[n] = m - a[n];
  if (n % 2 == 0) x = 1, light[n] = m - a[n];
  for (int i = n - 1; i >= 0; --i) {
    all[i] += all[i + 1] + a[i + 1] - a[i];
    x ^= 1;
    if (x)
      light[i] = light[i + 1] + a[i + 1] - a[i];
    else
      light[i] = light[i + 1];
  }
  int ans = light[0], maxx = 0;
  for (int i = 0; i <= n; ++i) maxx = max(maxx, all[i] - 2 * light[i] - 1);
  return printf("%d", ans + maxx), 0;
}
