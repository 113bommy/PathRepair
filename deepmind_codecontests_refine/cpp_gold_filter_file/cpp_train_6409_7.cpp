#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, x, s;
  scanf("%I64d %I64d %I64d %I64d %I64d", &n, &m, &k, &x, &s);
  vector<long long> a(m + 1), b(m + 1), c(k + 1), d(k + 1);
  a[0] = x;
  b[0] = 0;
  c[0] = 0;
  d[0] = 0;
  for (long long i = 0; i < m; i++) scanf("%I64d", &a[i + 1]);
  for (long long i = 0; i < m; i++) scanf("%I64d", &b[i + 1]);
  for (long long i = 0; i < k; i++) scanf("%I64d", &c[i + 1]);
  for (long long i = 0; i < k; i++) scanf("%I64d", &d[i + 1]);
  long long min_t = 5e18;
  for (long long i = 0; i <= m; i++) {
    long long max_s = s - b[i] + 1;
    long long ind = lower_bound(d.begin(), d.end(), max_s) - d.begin();
    if (ind == 0) {
      if (b[i] <= s) min_t = min(min_t, n * a[i]);
    } else {
      ind--;
      long long cost0 = min(n, c[ind]);
      long long aux_n = n - cost0;
      long long res = aux_n * a[i];
      min_t = min(min_t, res);
    }
  }
  min_t = min(min_t, x * n);
  cout << min_t << endl;
  return 0;
}
