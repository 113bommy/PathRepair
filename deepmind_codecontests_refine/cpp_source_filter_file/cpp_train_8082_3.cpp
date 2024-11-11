#include <bits/stdc++.h>
void solve() {
  long long n, i;
  scanf("%lld", &n);
  long long o = 0, e = 0;
  long long x;
  for (i = 0; i < n; i++) {
    scanf("%lld", &x);
    if (x % 2)
      o++;
    else
      e++;
  }
  if (o < e) {
    printf("%lld", e);
    return;
  }
  long long ans = e;
  o -= e;
  ans += o / 3;
  printf("%lld", ans);
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
