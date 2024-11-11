#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, v;
  scanf("%d%d%d", &n, &m, &v);
  if (((n - 2) * (n - 1)) / 2 < m || m < n - 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (i == v) continue;
    printf("%d %d\n", v, i);
  }
  m -= (n - 1);
  for (int i = 1; i <= n; i++) {
    if (i == v) continue;
    for (int j = 1; j < i; j++) {
      if (j == v) continue;
      if (m <= 0) return 0;
      if (i != j) printf("%d %d\n", i, j);
      m--;
    }
  }
  return 0;
}
