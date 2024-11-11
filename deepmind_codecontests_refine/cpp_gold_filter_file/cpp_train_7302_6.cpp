#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
long long mod = 998244353;
int n, last_one[N];
long long a[N], mask[N], val = 0;
int count_one(long long x) {
  int ret = 0;
  while (x) {
    if (x & 1) ++ret;
    x >>= 1;
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%lld", &a[i], &mask[i]);
    val += a[i];
    for (int j = 0; j <= 62; ++j) {
      if ((mask[i] >> j) & 1) {
        last_one[i] = j;
        break;
      }
    }
  }
  if (val < 0) {
    for (int i = 1; i <= n; ++i) a[i] *= -1;
  }
  long long s = 0;
  for (int bit = 62; bit >= 0; --bit) {
    long long v[2] = {0, 0};
    for (int i = 1; i <= n; ++i) {
      if (last_one[i] == bit) {
        v[count_one(mask[i] & s) % 2] += a[i];
      }
    }
    if (v[0] > v[1]) {
      s |= (1ll << bit);
    }
  }
  cout << s << endl;
  return 0;
}
