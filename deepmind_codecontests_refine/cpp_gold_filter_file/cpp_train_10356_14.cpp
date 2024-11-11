#include <bits/stdc++.h>
using namespace std;
long long n, m;
bool v[12000000];
bool ok(long long k) {
  long long q = (long long)sqrt(double(k));
  if (q * q == k)
    return true;
  else
    return false;
}
long long sq(long long k) { return (long long)sqrt(double(k)); }
int main() {
  while (scanf("%I64d%I64d", &n, &m) == 2) {
    long long ans = 0;
    long long i, j;
    for (i = 1; i <= n; i++) {
      ans += 2 * min(i * i, m);
    }
    for (i = 0; i < 11000000; i++) v[i] = 0;
    for (i = 1; i <= n; i++) {
      long long l, r;
      if (i * i - m < 0)
        l = 0;
      else if (ok(i * i - m)) {
        l = sq(i * i - m);
      } else {
        l = sq(i * i - m) + 1;
      }
      r = sq(i * i - 1);
      for (j = l; j <= r; j++) {
        long long a1, a2;
        a1 = -i + j;
        a2 = -i - j;
        if (v[-a1] == 1)
          ans--;
        else
          v[-a1] = 1;
        if (v[-a2] == 1)
          ans--;
        else
          v[-a2] = 1;
      }
    }
    printf("%I64d\n", ans);
  }
}
