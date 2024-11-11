#include <bits/stdc++.h>
int main() {
  long n;
  long long t = 0, out = 0;
  scanf("%ld", &n);
  long a[n];
  for (long i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
    t += a[i];
  }
  t /= n;
  for (long i = 0; i < n; i++)
    if (a[i] < t) {
      a[i + 1] -= (t - a[i]);
      out += t - a[i];
    } else {
      a[i + 1] += (a[i] - t);
      out += (a[i] - t);
    }
  printf("%lld", out);
}
