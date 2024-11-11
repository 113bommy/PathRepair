#include <bits/stdc++.h>
int n, m, arr[200010][2];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
  int i, j, s;
  scanf("%d%d", &n, &m);
  s = n - 1;
  if (m < n - 1) {
    printf("Impossible\n");
    return 0;
  }
  for (i = 1; i <= n - 1; ++i) arr[i][0] = 1, arr[i][1] = i + 1;
  for (i = 2; i < n; ++i) {
    for (j = i + 1; j <= n; ++j) {
      if (gcd(i, j) - 1) continue;
      ++s;
      arr[s][0] = i;
      arr[s][1] = j;
      if (s >= m) break;
    }
    if (j <= n) break;
  }
  if (s < m) {
    printf("Impossible\n");
    return 0;
  }
  printf("Possible\n");
  for (i = 1; i <= m; ++i) printf("%d %d\n", arr[i][0], arr[i][1]);
}
