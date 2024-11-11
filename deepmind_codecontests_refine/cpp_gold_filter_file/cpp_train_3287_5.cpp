#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long cnt(long long x) {
  long long s = k - x, t = k + x, ret = 0;
  if (s < 1) {
    ret += (x - k + 1 + x) * k / 2;
  } else {
    ret += (x + 1) * x / 2 + s;
  }
  if (t > n) {
    ret += (x - 1 + x - (n - k)) * (n - k) / 2;
  } else {
    ret += (x - 1) * x / 2 + n - t + 1;
  }
  return ret;
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  long long l = 1, r = m + 1;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (cnt(mid) <= m)
      l = mid + 1;
    else
      r = mid;
  }
  l--;
  printf("%I64d", l);
  return 0;
}
