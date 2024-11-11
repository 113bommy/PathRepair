#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2e5 + 17;
const int INF = 1e9 + 17;
int n, x, y;
long long sum, sum2;
int a[MaxN];
int main() {
  scanf("%d%d%d", &n, &x, &y);
  if (x > y) swap(x, y);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  for (int i = n; i >= n - x + 1; --i) sum += a[i];
  for (int i = n - x; i >= n - x - y + 1; --i) sum2 += a[i];
  long double ans = sum * 1.0;
  ans = ans / (x * 1.0);
  ans += (sum2 * 1.0) / (y * 1.0);
  printf("%.6f", ans);
  return 0;
}
