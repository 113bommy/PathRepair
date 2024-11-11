#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
long long a[1 << 20], r[30], s[30];
int n, m, l;
int main() {
  scanf("%d", &n);
  l = 1 << n;
  for (int i = 0; i < (1 << n); ++i) scanf("%d", &a[i]);
  int step = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = step; j < l; j += 2 * step) {
      sort(a + j - step, a + j);
      for (int k = j; k < step + j; ++k) {
        r[i] += (a + j) - upper_bound(a + j - step, a + j, a[k]);
        s[i] += lower_bound(a + j - step, a + j, a[k]) - (a + j - step);
      }
    }
    step = step << 1;
  }
  long long res = 0;
  scanf("%d", &m);
  for (int i = 1; i <= n; ++i) res += r[i], r[i] = s[i] - r[i];
  for (int i = 0; i < m; ++i) {
    int q;
    scanf("%d", &q);
    for (int j = q; j >= 1; --j) res += r[j], r[j] = -r[j];
    printf("%I64D\n", res);
  }
  return 0;
}
