#include <bits/stdc++.h>
using namespace std;
const int N = 100003;
int n, s1, s2, a[N], l, r, M, L, R, ans;
bool check(int x) {
  L = a[n] - x, R = a[n] + x;
  for (int i = n - 1; i >= 1; i--) {
    if (L <= a[i] && a[i] <= R) {
      L = a[i] - x, R = a[i] + x;
    } else {
      L = max(L, a[i] - x), R = min(R, a[i] + x);
    }
  }
  return (L <= s1 && s1 <= R) || (L <= s2 && s2 <= R);
}
int main() {
  scanf("%d%d%d", &n, &s1, &s2);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  l = s1 - s2 > 0 ? s1 - s2 : s2 - s1, ans = r = 1e9;
  while (l <= r) {
    if (check(M = l + r >> 1))
      ans = M, r = M - 1;
    else
      l = M + 1;
  }
  printf("%d\n", ans);
  return 0;
}
