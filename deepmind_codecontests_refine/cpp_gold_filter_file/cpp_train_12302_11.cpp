#include <bits/stdc++.h>
using namespace std;
long long mod_pow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
    n >>= 1;
  }
  return res;
}
long long n;
long long l[200010], r[200010], p[200010];
long long pfx[200010], sfx[200010];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  for (long long i = (long long)(0); i < (long long)(n); i++) cin >> l[i];
  for (long long i = (long long)(0); i < (long long)(n); i++) cin >> r[i];
  for (long long i = (long long)(0); i < (long long)(n - 1); i++) {
    long long cnt = max(0LL, min(r[i], r[i + 1]) - max(l[i], l[i + 1]) + 1);
    p[i] = cnt *
           mod_pow((r[i] - l[i] + 1) * (r[i + 1] - l[i + 1] + 1) % 1000000007,
                   1000000007 - 2) %
           1000000007;
    p[i] = (1 - p[i] + 1000000007) % 1000000007;
  }
  for (long long i = (long long)(0); i < (long long)(n - 1); i++) {
    pfx[i + 1] = (pfx[i] + p[i]) % 1000000007;
  }
  for (long long i = n - 1; i >= 0; i--) {
    sfx[i] = (sfx[i + 1] + p[i]) % 1000000007;
  }
  long long res = 0;
  for (long long i = (long long)(0); i < (long long)(n - 1); i++) {
    if (i - 1 >= 0) (res += p[i] * pfx[i - 1] % 1000000007) %= 1000000007;
    if (i + 2 < n) (res += p[i] * sfx[i + 2] % 1000000007) %= 1000000007;
    (res += p[i]) %= 1000000007;
    if (i - 1 >= 0) {
      long long cnt1 = max(0LL, min({r[i - 1], r[i], r[i + 1]}) -
                                    max({l[i - 1], l[i], l[i + 1]}) + 1);
      long long cnt2 = max(0LL, min(r[i - 1], r[i]) - max(l[i - 1], l[i]) + 1) *
                       (r[i + 1] - l[i + 1] + 1) % 1000000007;
      long long cnt3 = max(0LL, min(r[i], r[i + 1]) - max(l[i], l[i + 1]) + 1) *
                       (r[i - 1] - l[i - 1] + 1) % 1000000007;
      long long cp =
          (-cnt1 + cnt2 + cnt3) *
          mod_pow(((r[i - 1] - l[i - 1] + 1) * (r[i] - l[i] + 1) % 1000000007) *
                      (r[i + 1] - l[i + 1] + 1) % 1000000007,
                  1000000007 - 2) %
          1000000007;
      cp = (1 - cp + 1000000007) % 1000000007;
      (res += 2 * cp) %= 1000000007;
    }
  }
  for (long long i = (long long)(0); i < (long long)(n - 1); i++)
    (res += p[i] * 2) %= 1000000007;
  res++;
  cout << res % 1000000007 << endl;
  return 0;
}
