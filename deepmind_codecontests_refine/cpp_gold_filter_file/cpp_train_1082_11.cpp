#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100000];
long long b[100000];
bool f(long long cost) {
  long long curr = 0;
  for (long long i = 0; i < n && curr < m; i++) {
    long long cl = 0, cr = 0;
    while (curr < m) {
      if (b[curr] < a[i])
        cl = max(cl, a[i] - b[curr]);
      else
        cr = max(cr, b[curr] - a[i]);
      if (min(2 * cl + cr, 2 * cr + cl) > cost) break;
      curr++;
    }
  }
  if (curr == m) return true;
  return false;
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (long long i = 0; i < n; i++) scanf("%I64d", &a[i]);
  for (long long i = 0; i < m; i++) scanf("%I64d", &b[i]);
  long long l = 0, r = 20000000000LL, ans;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (f(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%I64d\n", ans);
  return 0;
}
