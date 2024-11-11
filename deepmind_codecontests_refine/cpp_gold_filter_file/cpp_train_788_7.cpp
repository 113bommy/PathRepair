#include <bits/stdc++.h>
using namespace std;
const long long MX = 2e5 + 100, mod = 1e9 + 7, del = 10909;
const long double pi = 3.14159265359;
long long n, mode = 1, fac1[MX], fac2[MX];
vector<long long> a1, a2;
long long bp(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long nesf = bp(a, b / 2);
  nesf = (nesf * nesf) % mod;
  if (b & 1) nesf = (nesf * a) % mod;
  return nesf;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long N = n;
  fac1[1] = fac2[1] = fac1[0] = fac2[0] = 1;
  for (long long i = 2; i < MX; i++) {
    fac1[i] = fac1[i - 1] * i % mod;
    fac2[i] = fac2[i - 1] * bp(i, mod - 2) % mod;
  }
  for (long long i = 0; i < n; i++) {
    long long v;
    cin >> v;
    a1.push_back(v);
  }
  if (N == 1) return cout << a1[0], 0;
  while ((n % 2 != 0 || mode != 1) && n > 1) {
    for (long long i = 0; i < n - 1; i++) {
      a2.push_back(a1[i] + mode * a1[i + 1]);
      mode *= -1;
    }
    n--;
    a1 = a2;
    a2.clear();
  }
  long long ans1 = 0, ans2 = 0;
  long long k = n / 2 - 1;
  for (long long i = 0; 2 * i < n; i++) {
    ans1 += fac1[k] * fac2[i] % mod * fac2[k - i] % mod * a1[2 * i] % mod;
    ans2 += fac1[k] * fac2[i] % mod * fac2[k - i] % mod * a1[2 * i + 1] % mod;
  }
  if ((N * (N - 1) / 2) & 1)
    ans1 += ans2, ans1 %= mod;
  else
    ans1 -= ans2, ans1 %= mod;
  cout << (ans1 + mod) % mod;
}
