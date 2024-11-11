#include <bits/stdc++.h>
using namespace std;
long long c[1005][1005];
int n, m, k;
void init() {
  memset(c, 0, sizeof(c));
  int i, j;
  for (i = 0; i <= 1000; i++) {
    c[i][0] = 1;
    for (j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 100000007;
    }
  }
}
int main() {
  int i, j, k;
  init();
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    long long ans = 0;
    if (2 * k <= n - 1 && 2 * k <= m - 1) {
      ans = (c[n - 1][2 * k] * c[m - 1][2 * k]) % 100000007;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
