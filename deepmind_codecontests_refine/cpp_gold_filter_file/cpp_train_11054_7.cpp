#include <bits/stdc++.h>
using namespace std;
int n, a[400010], cnt[21];
long long inv[21][21], f[(1 << 21) + 1];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    for (int j = 1; j <= 20; ++j) inv[a[i]][j] += cnt[j];
    ++cnt[a[i]];
  }
  for (int i = 1; i < (1 << 20); ++i) f[i] = 1ll << 62;
  for (int i = 0; i < (1 << 20); ++i) {
    vector<int> x;
    for (int j = 1; j <= 20; ++j)
      if (i & (1 << (j - 1))) x.push_back(j);
    for (int j = 1; j <= 20; ++j) {
      if (i & (1 << (j - 1))) continue;
      long long res = 0;
      for (auto k : x) res += inv[k][j];
      f[i | (1 << (j - 1))] = min(f[i | (1 << (j - 1))], f[i] + res);
    }
  }
  printf("%lld\n", f[(1 << 20) - 1]);
}
