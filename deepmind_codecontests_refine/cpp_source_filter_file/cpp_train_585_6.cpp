#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, d, t;
  cin >> k >> d >> t;
  t *= 2;
  long long l = 0, r = t;
  d = (k + d - 1) / d * d;
  while (l < r) {
    long long m = (l + r) / 2;
    long long cur = m / d * k * 2 + m / d * (d - k);
    if (m % d <= k) {
      cur += (m % d) * 2;
    } else {
      cur += k * 2 + (m % d) - k;
    }
    if (cur < t) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  long long res = l / d * k * 2 + l / d * (d - k);
  if (res % d <= k) {
    res += (l % d) * 2;
  } else {
    res += k * 2 + (l % d) - k;
  }
  if (res - 1 >= t) {
    cout << l - 1 << '.' << '5' << endl;
  } else {
    cout << l << endl;
  }
}
