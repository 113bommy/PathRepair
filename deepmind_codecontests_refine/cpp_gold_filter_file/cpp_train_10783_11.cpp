#include <bits/stdc++.h>
using namespace std;
long long n, m, l, r;
bool check(long long k) {
  if ((k * (k + 1)) >= (n - m) * 2)
    return 1;
  else
    return 0;
}
int main() {
  scanf("%I64d %I64d", &n, &m);
  if (m >= n) {
    printf("%I64d", n);
    return 0;
  }
  l = 1;
  r = 1e10 + 7;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (!check(l))
    printf("%I64d", r + m);
  else
    printf("%I64d", l + m);
  return 0;
}
