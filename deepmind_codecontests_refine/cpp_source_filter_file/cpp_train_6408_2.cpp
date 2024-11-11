#include <bits/stdc++.h>
using namespace std;
namespace FGF {
int m, n;
const int N = 2e5 + 5;
int a[N], b[N], f[N];
bool check(int x) {
  f[1] = 0;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1];
    if (f[i - 1] >= b[i] - 1) f[i] = max(f[i], b[i] + x);
    if (f[i - 1] >= b[i] - x - 1) f[i] = max(f[i], b[i]);
    if (i > 2 && f[i - 2] >= b[i] - x - 1) f[i] = max(f[i], b[i - 1] + x);
  }
  if (f[n] >= m - x - 1) return 1;
  if (x < b[2]) return 0;
  f[2] = b[2];
  for (int i = 3; i <= n; i++) {
    f[i] = f[i - 1];
    if (f[i - 1] >= b[i] - 1) f[i] = max(f[i], b[i] + x);
    if (f[i - 1] >= b[i] - x - 1) f[i] = max(f[i], b[i]);
    if (f[i - 2] >= b[i] - x - 1) f[i] = max(f[i], b[i - 1] + x);
  }
  if (f[n] >= b[2] - x + m - 1) return 1;
  return 0;
}
void work() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i + n] = a[i] + m;
  if (n == 1) {
    printf("%d\n", m - 1);
    return;
  }
  int l = 0, r, ans = m - 1, mx = 1;
  for (int i = 2; i <= n; i++)
    if (a[i + 1] - a[i] > a[mx + 1] - a[mx]) mx = i;
  r = a[mx + 1] - a[mx] - 1;
  for (int i = 1; i <= n; i++) b[i] = a[i + mx];
  for (int i = 1, tmp = b[1]; i <= n; i++) b[i] -= tmp;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}
