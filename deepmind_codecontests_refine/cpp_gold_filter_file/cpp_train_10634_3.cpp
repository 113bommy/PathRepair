#include <bits/stdc++.h>
const int N = 1e7 + 5;
int n, pos[N], ans1, ans2;
long long ans = 1e14;
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    if (pos[x]) {
      if (x < ans) ans1 = pos[x], ans2 = i, ans = x;
    } else
      pos[x] = i;
  }
  for (int i = 1, tmp1, tmp2; i < N; ++i) {
    if (i >= ans) break;
    tmp1 = tmp2 = 0;
    for (int j = i; j < N; j += i) {
      if (!pos[j]) continue;
      if (!tmp1)
        tmp1 = j, tmp2 = pos[j];
      else {
        if (1LL * j / i * tmp1 < ans) {
          ans = 1LL * j / i * tmp1, ans1 = pos[j], ans2 = tmp2;
          break;
        }
      }
    }
  }
  if (ans1 > ans2) ans1 ^= ans2 ^= ans1 ^= ans2;
  printf("%d %d\n", ans1, ans2);
  return 0;
}
