#include <bits/stdc++.h>
int main() {
  long long k, d, t;
  scanf("%I64d%I64d%I64d", &k, &d, &t);
  long long period = ((k - 1) / d + 1) * d;
  long long off = period - k;
  long long total = t << 1;
  long long once = k * 2 + off;
  long long time = total / once * period * 2;
  long long left = total % once;
  if (left <= k << 1) {
    time += left;
  } else {
    time += k * 2 + (left - k * 2) * 2;
  }
  printf("%I64d.%I64d\n", time >> 1, 5 * (time & 1));
  return 0;
}
