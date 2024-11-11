#include <bits/stdc++.h>
using namespace std;
inline long long modpow(long long base, long long exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp & 1) res = (res % 1000000009 * base % 1000000009) % 1000000009;
    base = (base % 1000000009 * base % 1000000009) % 1000000009;
    exp /= 2;
  }
  return res;
}
int main() {
  long long n, a, b, k;
  scanf("%lld", &n);
  scanf("%lld", &a);
  scanf("%lld", &b);
  scanf("%lld", &k);
  string str;
  cin >> str;
  vector<long long> v;
  for (long long i = 0; i < k; i++) {
    if (str[i] == '+') {
      long long foo = modpow(a, n - i);
      long long bar = modpow(b, i);
      long long ans = (foo * bar) % 1000000009;
      v.push_back(ans);
    } else {
      long long foo = modpow(a, n - i);
      long long bar = modpow(b, i);
      long long ans = (foo * bar) % 1000000009;
      v.push_back(-ans);
    }
  }
  long long foc;
  long long den =
      (modpow(b, k) * modpow(modpow(a, k), 1000000009 - 2)) % 1000000009;
  if (den < 0) den += 1000000009;
  if (den == 1)
    foc = (n + 1) / k;
  else {
    long long num =
        (modpow(a, n + 1) * modpow(modpow(a, n + 1), 1000000009 - 2)) %
        1000000009;
    num = 1 - num;
    den = 1 - den;
    foc = (num * modpow(den, 1000000009 - 2)) % 1000000009;
  }
  for (long long i = 0; i < k; i++) {
    v[i] = (v[i] * foc) % 1000000009;
  }
  long long ans = 0;
  for (long long i = 0; i < k; i++) {
    ans += v[i];
    if (ans >= 1000000009)
      ans -= 1000000009;
    else if (ans < 0)
      ans += 1000000009;
  }
  printf("%lld\n", ans);
}
