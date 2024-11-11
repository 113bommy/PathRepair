#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
long long a[N];
void solve() {
  long long n, k;
  double t;
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  sort(a, a + n);
  long long ans = a[0] + n - 1;
  for (int i = 0; i < n; i++) {
    if (i) k -= a[i];
    t = k;
    t = t / (n - i);
    t = floor(t);
    long long l = t;
    ans = min(ans, max(0ll, a[0] - l) + n - i - 1);
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  for (scanf("%d", &t); t != 0; t--) solve();
  return 0;
}
