#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, k, p;
int a[maxn], b[maxn << 1];
int main() {
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= k; i++) scanf("%d", &b[i]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + k + 1);
  int ans = 2e9;
  for (int i = 1; i <= k - n + 1; i++) {
    int j = i + n - 1, res = 0;
    for (int id = i; id <= j; id++) {
      res = max(res, abs(a[id - i + 1] - b[id]) + abs(b[id] - p));
    }
    ans = min(ans, res);
  }
  printf("%d\n", ans);
  return 0;
}
