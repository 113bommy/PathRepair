#include <bits/stdc++.h>
int n;
long long s;
inline void solve() {
  scanf("%lld%d", &s, &n);
  long long cur;
  for (int i = n; i > 1; --i) {
    cur = pow(10, (int)log10(s - i));
    s -= cur;
    printf("%lld ", cur);
  }
  printf("%lld\n", s);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
