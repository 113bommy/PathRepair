#include <bits/stdc++.h>
using namespace std;
int n, m, v, x;
int a = 1, b = 1;
int main() {
  scanf("%d%d%d", &n, &m, &v);
  if (m < n - 1 || m > (n - 1) * (n - 2) / 2 + 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (i != v) printf("%d %d\n", v, i);
  m -= n - 1;
  if (!m) return 0;
  x = (v == n ? 1 : n);
  for (int i = 1; i <= n; i++) {
    if (i == x || i == v) continue;
    for (int j = 1; j < i; j++) {
      if (j == x || j == v) continue;
      printf("%d %d\n", i, j);
      m--;
      if (!m) return 0;
    }
  }
  return 0;
}
