#include <bits/stdc++.h>
using namespace std;
long long a[200010], b[200010];
int main() {
  long long i, j, k, l, n, m, g, d;
  scanf("%lld %lld", &n, &d);
  for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (i = 1; i <= n; i++) scanf("%lld", &b[i]);
  long long cmp = b[1] + a[d], ans = 0, in = d - 1;
  for (i = d - 1; i <= n && in > 0; i++) {
    if (b[i] + a[in] <= cmp) {
      ans++;
      in--;
    }
  }
  cout << d - ans << endl;
  return 0;
}
