#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
long long num[100], sum[100], de[100];
bool xh[1000010];
long long len(long long x) {
  for (long long i = 62; i >= 1; i--)
    if (x / (1ll << i)) return i + 1;
  return 1;
}
bool cf(long long x, long long y, long long l, long long r, long long len1) {
  long long w = x;
  for (long long i = 2; i <= y; i++) {
    w <<= len(x);
    w += x;
  }
  return w <= r && w >= l;
}
long long calc(long long x) {
  long long l = len(x);
  long long ans = 0, a, b, c;
  for (long long i = 1; i < l; i++) ans += sum[i];
  for (long long k = 1; k <= l / 2; k++)
    if (l % k == 0) {
      long long minn = 1ll << 62, minn2 = 0;
      for (long long i = 1; i <= l / k; i++) {
        long long j = l / k - i + 1;
        if (j > 1)
          minn2 = max(minn2, min(minn, (x >> ((j - 1) * k)) % (1ll << k) - 1));
        minn = min(minn, (x >> ((j - 1) * k)) % (1ll << k));
      }
      minn = max(minn, minn2);
      if (minn < (1ll << (k - 1))) continue;
      ans += minn - (1ll << (k - 1)) + 1;
      if (k & 1ll) {
        c = (1 << (k / 2)) - 1;
      } else {
        a = minn >> (k / 2);
        b = minn % (1ll << (k / 2));
        if (a > b)
          c = a - 1;
        else
          c = a;
      }
      for (long long i = 1; i <= c; i++) {
        long long ll = len(i);
        if (!xh[i])
          for (long long j = 2; j <= k / ll; j++)
            if (cf(i, j, (1ll << (k - 1)), minn, ll)) {
              ans--;
              break;
            }
      }
    }
  return ans;
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  num[1] = 1;
  for (long long i = 2; i <= 32; i++) {
    num[i] = (1ll << i) - (1ll << (i - 1));
    for (long long j = 1; j <= i - 1; j++)
      if (i % j == 0) num[i] -= num[j];
  }
  sum[1] = 0;
  for (long long i = 2; i <= 63; i++)
    for (long long j = 1; j <= i / 2; j++)
      if (i % j == 0) sum[i] += num[j];
  for (long long i = 1; i <= 100000; i++) {
    long long l = len(i);
    long long x = i;
    for (long long j = 2; x <= 100000; j++) {
      x = (x << l) + i;
      if (x <= 100000) xh[x] = true;
    }
  }
  printf("%I64d\n", calc(m) - calc(n - 1));
  return 0;
}
