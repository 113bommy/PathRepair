#include <bits/stdc++.h>
using namespace std;
long long mul(long long x, int per, int k) {
  long long ret = 0;
  while (k--) ret <<= (long long)per, ret += x;
  return ret;
}
long long get(long long x) {
  if (x <= 1LL) return 0;
  int len = 0;
  for (long long y = x; y;) ++len, y >>= 1;
  long long sum = 0;
  for (int per = 1; per <= len - 1; per++)
    for (int k = 2; k <= len; k++)
      if (k * per <= len) {
        long long l = 0, r = (1LL << per) - 1, t = 0;
        while (l <= r) {
          long long m = (l + r) >> 1;
          if (mul(m, per, k) <= x)
            t = m, l = m + 1;
          else
            r = m - 1;
        }
        long long Add = t - get(t), tmp = (1LL << (per - 1)) - 1;
        if (per > 1) {
          if (t <= tmp) continue;
          Add += get(tmp) - tmp;
        }
        sum += Add;
      }
  return sum;
}
int main() {
  long long l, r;
  cin >> l >> r;
  cout << get(r) - get(l - 1) << endl;
}
