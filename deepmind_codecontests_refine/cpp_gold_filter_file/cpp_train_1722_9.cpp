#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 50;
int n, k, a[N], b[N];
long long need, ma_po, dif;
bool ok(long long mid) {
  ma_po = k;
  for (int i = 0; i < n; i++) {
    need = mid * a[i];
    if (need > b[i]) {
      dif = need - b[i];
      if (dif > ma_po) return false;
      ma_po -= dif;
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  long long lo = 0, hi = 2e9;
  while (lo < hi) {
    long long mid = (lo + hi + 1) / 2;
    if (ok(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  printf("%lld\n", lo);
  return 0;
}
