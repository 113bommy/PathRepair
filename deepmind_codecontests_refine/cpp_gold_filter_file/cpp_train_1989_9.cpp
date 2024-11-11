#include <bits/stdc++.h>
using namespace std;
int n, a[1000005], m, M, N, sum;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), M = max(a[i], M);
  for (int i = 1; i <= n; ++i) sum += M - a[i];
  if (m <= sum)
    printf("%d %d\n", M, M + m);
  else
    printf("%d %d\n", (m - sum + n - 1) / n + M, M + m);
  return 0;
}
