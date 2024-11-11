#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  assert(scanf("%d%d", &n, &s) == 2);
  s--;
  int a[n];
  for (int i = 0; i < n; i++) assert(scanf("%d", &a[i]) == 1);
  int ans_b = 0;
  if (a[s]) {
    ans_b++;
    a[s] = 0;
  }
  sort(a, a + n);
  int was[n], sum[n + 1];
  memset(was, 0, sizeof(was[0]) * n);
  for (int i = 1; i < n; i++) was[a[i]]++;
  sum[0] = 0;
  for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + was[i];
  int ans = n - 1, holes = 0;
  for (int limit = 2; limit <= n; limit++) {
    int res = max(holes, sum[n] - sum[limit] + was[0]);
    ans = min(ans, res);
    holes += !was[limit - 1];
  }
  printf("%d\n", ans + ans_b);
  return 0;
}
