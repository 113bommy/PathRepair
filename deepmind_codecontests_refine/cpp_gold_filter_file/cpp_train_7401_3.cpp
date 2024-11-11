#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
int n, i, j, k, t;
int a[500002];
long long b[500002];
int main() {
  memset(b, -1, sizeof b);
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[n + i] = a[i];
  }
  if (*max_element(a, a + n) == *min_element(a, a + n)) {
    if (a[0] != 0) return puts("NO") & 0;
    puts("YES");
    for (i = 0; i < n; ++i) printf("%d ", 1);
    return puts("") & 0;
  }
  for (i = 2 * n - 1; i >= n; --i) {
    if (a[i] != 0 && a[i] > a[i - 1]) break;
  }
  k = i;
  b[k] = a[k];
  for (i = 1; i < n; ++i) {
    b[k - i] = a[k - i];
    if (a[k - i - 1] >= b[k - i]) {
      int mul = (a[k - i - 1] - b[k - i] + b[k - i + 1]) / b[k - i + 1];
      b[k - i] += b[k - i + 1] * mul;
    }
  }
  for (i = 0; i < n; ++i) {
    if (b[i] != -1) break;
    b[i] = b[n + i];
  }
  puts("YES");
  for (i = 0; i < n; ++i) printf("%lld ", b[i]);
  puts("");
  return 0;
}
