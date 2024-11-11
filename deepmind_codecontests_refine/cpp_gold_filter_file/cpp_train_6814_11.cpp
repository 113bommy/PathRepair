#include <bits/stdc++.h>
using namespace std;
long long a, l, r, s, t, mid, u, v;
long long ten[18], A[18];
long long count(long long t) {
  int i, len = 16;
  long long suf = 0, sum = 0;
  for (i = 16; i >= 0; i--) A[i] = t / ten[i] % 10;
  while (!A[len]) len--;
  for (i = len; i >= 0; i--) {
    sum = sum + A[i] * (ten[i] * i / 10) * 45;
    sum = sum + (suf * A[i] + (A[i] - 1) * A[i] / 2) * ten[i];
    suf += A[i];
  }
  return sum + suf;
}
int main() {
  int i, p;
  for (i = 1, ten[0] = 1; i <= 17; i++) ten[i] = ten[i - 1] * 10;
  scanf("%I64d", &a);
  for (p = 1; p <= 10; p++) {
    s = 0, t = ten[17];
    while (t - s > 1) {
      mid = (s + t) >> 1;
      if (count(mid) >= p * a)
        t = mid;
      else
        s = mid;
    }
    r = t, v = count(r);
    s = 0, t = ten[17];
    while (t - s > 1) {
      mid = (s + t) >> 1;
      if (count(mid) <= v - p * a)
        s = mid;
      else
        t = mid;
    }
    if (count(s) == v - p * a) {
      cout << s + 1 << ' ' << r;
      return 0;
    }
  }
  return 0;
}
