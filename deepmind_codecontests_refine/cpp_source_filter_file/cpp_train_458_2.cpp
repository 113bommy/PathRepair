#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, x;
  scanf("%d %d %d", &n, &m, &x);
  for (int i = 1; i < x; i++) {
    n -= 2;
    m -= 2;
    if (n < 0 || m < 0) break;
  }
  int ans = 0;
  if (n == 1 && m > 0)
    ans = (m + 1) / 2;
  else if (m == 1 && n > 0)
    ans = (n + 1) / 2;
  else if (n > 0 || m > 0) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      cnt++;
      if (cnt % 2) ans++;
    }
    for (int i = 1; i < n; i++) {
      cnt++;
      if (cnt % 2) ans++;
    }
    for (int i = 1; i < m; i++) {
      cnt++;
      if (cnt % 2) ans++;
    }
    for (int i = 2; i < n; i++) {
      cnt++;
      if (cnt % 2) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
