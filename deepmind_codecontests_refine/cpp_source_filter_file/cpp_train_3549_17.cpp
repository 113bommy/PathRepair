#include <bits/stdc++.h>
using namespace std;
int n, m, a[201010], b[201010];
bool ok(long double fuel) {
  long double peso = (long double)m + fuel, need;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      if (peso <= m) return false;
      need = peso / a[i];
      peso -= need;
    } else if (i == n) {
      if (peso <= m) return false;
      need = peso / b[i];
      peso -= need;
    } else {
      if (peso <= m) return false;
      need = peso / b[i];
      peso -= need;
      if (peso <= m) return false;
      need = peso / a[i];
      peso -= need;
    }
  }
  if (peso <= m) return false;
  need = peso / a[n];
  peso -= need;
  if (peso <= m) return false;
  need = peso / b[1];
  peso -= need;
  if (peso < m) return false;
  return true;
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  long double lo = 0, hi = 1e10, mid, ans = 1e10;
  for (int i = 0; i < 150; i++) {
    mid = (lo + hi) / 2.0;
    if (ok(mid)) {
      ans = min(ans, mid);
      hi = mid;
    } else
      lo = mid;
  }
  if (ans > 1e9)
    printf("-1\n");
  else
    cout << fixed << setprecision(10) << ans << "\n";
  return 0;
}
