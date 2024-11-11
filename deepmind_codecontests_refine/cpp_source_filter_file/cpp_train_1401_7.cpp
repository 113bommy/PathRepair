#include <bits/stdc++.h>
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
int a[6005];
bool check(int x) {
  for (register int i = 2; i * i <= x; ++i)
    if (!(x % i)) return 0;
  return 1;
}
int main() {
  int n;
  scanf("%d", &n);
  int sum = n * (n + 1) / 2;
  for (register int i = 1; i <= n; ++i) a[i] = 1;
  if (check(sum)) {
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    return 0;
  }
  if ((sum & 1) && (!check(sum - 2))) a[3] = 3, sum -= 3;
  for (register int i = 2; i < n; ++i) {
    if (check(i) && check(sum - i)) {
      a[i] = 2;
      for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
      return 0;
    }
  }
}
