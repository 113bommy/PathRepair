#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, a[N], p[N << 1], f[N << 1];
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < 2 * n; i++) p[i] = -1, f[i] = n + 1;
  f[0] = f[1] = -n;
  for (int i = 1; i <= n - 1; i++)
    for (int x = 0; x <= 1; x++)
      for (int y = 0; y <= 1; y++) {
        int v[2] = {f[i * 2 - 2 + y], a[i - 1] * (2 * y - 1)};
        for (int j = 0; j <= 1; j++)
          if (v[j] <= a[i] * (2 * x - 1) && v[!j] < f[i * 2 + x])
            f[i * 2 + x] = v[!j], p[i * 2 + x] = i * 2 - 2 + y;
      }
  if (f[2 * n - 1] <= n) {
    puts("YES");
    for (int i = n - 1, x = 2 * n - 1; ~i; i--, x = p[x])
      if (!(x & 1)) a[i] *= -1;
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
  } else {
    puts("NO");
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
