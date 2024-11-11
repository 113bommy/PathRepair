#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
long long f[N];
long long num[N];
long long fpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}
int main() {
  num[0] = 0;
  int n;
  for (int i = 1; i < N; i++) {
    int l = num[i - 1] + i;
    num[i] = num[i - 1] + i * (fpow(10, i) - fpow(10, i - 1));
    f[i] = f[i - 1] + (l + num[i]) * (fpow(10, i) - fpow(10, i - 1)) / 2;
    if (f[i] > 1e18) {
      n = i;
      break;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    long long k;
    scanf("%lld", &k);
    int pos = lower_bound(f + 1, f + n + 1, k) - f - 1;
    k -= f[pos];
    if (k == 0)
      puts("9");
    else {
      long long l = fpow(10, pos);
      long long r = fpow(10, pos + 1) - 1;
      long long ans = 0;
      while (l <= r) {
        long long mid = (l + r) >> 1;
        long long s = num[pos] + pos + 1;
        long long cnt = mid - fpow(10, pos) + 1;
        long long t = num[pos] + (pos + 1) * cnt;
        if ((s + t) * cnt / 2 < k) {
          l = mid + 1;
          ans = max(ans, (s + t) * cnt / 2);
        } else
          r = mid - 1;
      }
      k -= ans;
      long long p = 0;
      for (int i = 1; i <= 10; i++) {
        long long now = fpow(10, i) - fpow(10, i - 1);
        now *= i;
        if (k <= now) {
          p = i;
          break;
        } else
          k -= now;
      }
      long long s = fpow(10, p - 1);
      s += k / p - 1;
      k %= p;
      if (k != 0)
        s++;
      else
        k = p;
      int d[15];
      int cnt = 0;
      while (s) {
        d[++cnt] = s % 10;
        s /= 10;
      }
      printf("%d\n", d[cnt - k + 1]);
    }
  }
  return 0;
}
