#include <bits/stdc++.h>
using namespace std;
int n, k, x;
long long ans;
int cnt[10005], f[20005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    cnt[x]++;
  }
  for (int i = 0; i <= 20000; ++i) {
    for (int j = 0; j < 15; ++j)
      if ((1 << j) & i) f[i]++;
  }
  for (int i = 0; i <= 10000; ++i) {
    if (k == 0) ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
    for (int j = i + 1; j <= 10000; ++j)
      if (f[i ^ j] == k) ans += 1LL * cnt[i] * cnt[j];
  }
  printf("%I64d\n", ans);
  return 0;
}
