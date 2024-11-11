#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const int inf = 1 << 30;
int m, n, q;
int a[N + 1];
int main() {
  scanf("%d", &m);
  int mn = inf;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &q);
    mn = min(mn, q);
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = n; i >= 1; i -= (mn + 2)) {
    for (int j = i; j >= i - mn + 1 && j >= 1; j--) {
      ans += a[i];
    }
  }
  printf("%d", ans);
  return 0;
}
