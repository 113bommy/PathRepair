#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  long double sum = 0, ans = 0;
  for (long long i = n - 1; i >= 0; i--) {
    sum += a[i + 1];
    if (i <= m) {
      long double tmp = sum + min(m - i, (n - i) * k);
      ans = max(ans, tmp / (n - i));
    }
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
