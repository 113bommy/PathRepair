#include <bits/stdc++.h>
using namespace std;
int n, k, a[1005], f[1005], las = 0;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  f[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i] - (i - 1) * k <= 0) continue;
    f[i] = 1;
    for (int j = 1; j < i; ++j)
      if ((a[i] - a[j]) % k == 0 && (a[i] - a[j]) / k == (i - j))
        f[i] = max(f[j] + 1, f[i]);
    if (f[i] > f[las]) las = i;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int t = a[las] + (i - las) * k;
    if (t != a[i]) ++cnt;
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= n; ++i) {
    int t = a[las] + (i - las) * k;
    if (t < a[i])
      printf("- %d %d\n", i, a[i] - t);
    else if (t > a[i])
      printf("+ %d %d\n", i, t - a[i]);
  }
  return 0;
}
