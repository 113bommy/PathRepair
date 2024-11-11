#include <bits/stdc++.h>
using namespace std;
long long ans, n, k, a, b, u, u1, v, jc[200010], jd[200010];
long long qpow(long long A, long long B) {
  long long C = 1;
  while (B) {
    if (B & 1) C = C * A % 998244353;
    A = A * A % 998244353, B >>= 1;
  }
  return C;
}
void init() {
  jc[0] = jd[0] = 1;
  cin >> n >> k >> u, u1 = u;
  for (long long i = 1; i <= 200010 - 5; i++) {
    jc[i] = jc[i - 1] * i % 998244353;
    jd[i] = qpow(jc[i], 998244353 - 2);
  }
}
long long C(long long A, long long B) {
  return jc[A] * jd[B] % 998244353 * jd[A - B] % 998244353;
}
long long calc(long long x) {
  return (x & 1) ? qpow(2, x - 1)
                 : (qpow(2, x - 1) - C(x, x / 2) * 499122177 % 998244353 +
                    998244353) %
                       998244353;
}
signed main() {
  init();
  for (long long i = 1; i < n; i++) {
    cin >> v;
    if (v == u) a++;
    u = v;
  }
  if (v == u1) a++;
  b = n - a;
  for (long long i = 1; i <= b; i++) {
    ans = (ans +
           C(b, b - i) * qpow(k - 2, b - i) % 998244353 * calc(i) % 998244353) %
          998244353;
  }
  ans = ans * qpow(k, a) % 998244353;
  cout << ans;
  return 0;
}
