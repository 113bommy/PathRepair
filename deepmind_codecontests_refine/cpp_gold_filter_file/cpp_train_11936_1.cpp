#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
inline long long pow(long long a, long long b) {
  if (b == 1) return a;
  long long tmp = pow(a, b >> 1);
  tmp = (tmp * tmp) % mod * (b & 1 ? a : 1) % mod;
  return tmp;
}
int n, m;
int a[100005];
long long ans = 0, res = 1;
int main() {
  scanf("%d%d", &n, &m);
  long long t1 = pow(m, mod - 2), t2 = pow(2, mod - 2);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    long long tmp;
    scanf("%I64d", &tmp);
    if (tmp == 0 && a[i] == 0) {
      ans = (ans + res * (1 - t1 + mod) % mod * t2 % mod) % mod;
      res = res * t1 % mod;
    } else if (tmp > 0 && a[i] > 0) {
      if (tmp > a[i]) {
        printf("%I64d", ans);
        return 0;
      } else if (tmp < a[i]) {
        printf("%I64d", (ans + res) % mod);
        return 0;
      }
    } else if (a[i] == 0) {
      ans = (ans + res * (m - tmp) % mod * t1 % mod) % mod;
      res = res * t1 % mod;
    } else {
      ans = (ans + res * (a[i] - 1) % mod * t1 % mod) % mod;
      res = res * t1 % mod;
    }
  }
  printf("%I64d", ans);
}
