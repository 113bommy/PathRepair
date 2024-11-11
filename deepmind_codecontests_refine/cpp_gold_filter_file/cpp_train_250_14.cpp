#include <bits/stdc++.h>
using namespace std;
int n, k, a[256], ans, b[256], c[256];
int check(int l, int r) {
  int sum = 0, m = 0, t = 0;
  for (int i = 1; i <= n; i++)
    if (l <= i && i <= r)
      b[++m] = a[i];
    else
      c[++t] = a[i];
  if (!m || !t) return ans;
  sort(c + 1, c + t + 1);
  sort(b + 1, b + m + 1);
  int j = t;
  for (int i = 1; i <= min(k, m) && j > 0; i++)
    if (c[j] < b[i])
      break;
    else
      b[i] = c[j], j--;
  for (int i = 1; i <= m; i++) sum += b[i];
  return sum;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ans += a[i];
  for (int i = 1; i < n; i++)
    for (int j = i; j <= n; j++) ans = max(ans, check(i, j));
  printf("%d\n", ans);
  return 0;
}
