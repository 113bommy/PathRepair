#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N], b[N];
int main() {
  long long n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  int la = 1, lb = 1;
  if (k >= n || k >= m) {
    return 0 * printf("-1\n");
  }
  long long max1 = 0;
  for (int i = 1; i <= min(k + 1, n); i++) {
    int re = i - 1;
    int pos = lower_bound(b + 1, b + m + 1, a[i] + ta) - b;
    if (pos > m) {
      return 0 * printf("-1\n");
    }
    int pi = k - re;
    if (pos + pi > m) {
      return 0 * printf("-1\n");
    }
    max1 = max(max1, b[pi + pos] + tb);
  }
  printf("%lld\n", max1);
}
