#include <bits/stdc++.h>
using std::bitset;
const int MAXN = 1010;
bitset<MAXN << 1> f[2];
int n, k, a[MAXN * MAXN];
int main() {
  scanf("%d%d", &k, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] -= k;
  }
  std::sort(a + 1, a + n + 1);
  n = std::unique(a + 1, a + n + 1) - (a + 1);
  f[0][1000] = 1;
  bool cur = 1;
  for (int i = 1; i <= 1000; i++, cur ^= 1) {
    f[cur].reset();
    for (int j = 1; j <= n; j++) {
      if (a[j] > 0)
        f[cur] |= f[cur ^ 1] << a[j];
      else
        f[cur] |= f[cur ^ 1] >> (-a[j]);
    }
    if (f[cur][1000]) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
