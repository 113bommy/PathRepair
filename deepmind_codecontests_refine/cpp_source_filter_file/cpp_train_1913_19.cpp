#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long c;
long long sqr(long long v) { return v * v; }
long long cal2(long long v) { return v * (v + 1) / 2; }
long long cal(long long t) {
  long long res = 2 * t * t + 2 * t + 1;
  t++;
  res -= sqr(max(0ll, t - x));
  res -= sqr(max(0ll, t - (n - x + 1)));
  res -= sqr(max(0ll, t - y));
  res -= sqr(max(0ll, t - (n - y + 1)));
  long long len = t - (n - x + 1);
  if (len > 0) {
    res += cal2(max(0ll, len - x));
    res += cal2(max(0ll, len - (n - x + 1)));
  }
  len = t - x;
  if (len > 0) {
    res += cal2(max(0ll, len - x));
    res += cal2(max(0ll, len - (n - x + 1)));
  }
  return res;
}
int main() {
  cin >> n >> x >> y >> c;
  long long l = 0, r = 20000000000ll, mid, res = 1000000007;
  while (l <= r) {
    mid = (l + r) / 2;
    if (cal(mid) >= c) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << res << endl;
  return 0;
}
