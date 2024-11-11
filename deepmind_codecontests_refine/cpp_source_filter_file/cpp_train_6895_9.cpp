#include <bits/stdc++.h>
using namespace std;
int n, q;
long long u, v, d;
long long ft[101], rft[101];
std::vector<long long> primes, powe;
long long power(long long b, long long p) {
  long long res = 1, a = b;
  for (; p; p >>= 1) {
    if (p & 1) res = res * a % 998244353;
    a = a * a % 998244353;
  }
  return res;
}
void build() {
  for (long long i = 2; i * i <= d; ++i) {
    if (d % i == 0) {
      primes.push_back(i);
      while (d % i == 0) d /= i;
    }
  }
  if (d > 1) primes.push_back(d);
  powe.resize(primes.size());
  ft[0] = ft[1] = 1;
  for (int i = 2; i <= 100; ++i) ft[i] = ft[i - 1] * i % 998244353;
  rft[100] = power(ft[100], 998244353 - 2);
  for (int i = 99; i > 0; --i) rft[i] = rft[i + 1] * (i + 1) % 998244353;
}
void quer() {
  cin >> u >> v;
  for (int i = 0; i < primes.size(); ++i) {
    powe[i] = 0;
    int k = primes[i];
    while (u % k == 0) {
      u /= k;
      ++powe[i];
    }
    while (v % k == 0) {
      v /= k;
      --powe[i];
    }
  }
  std::sort(powe.begin(), powe.end());
  long long ans = 1;
  int c = 0;
  for (int i = 0; i < primes.size() && powe[i] < 0; ++i) {
    c += -powe[i];
    ans = ans * rft[-powe[i]] % 998244353;
  }
  ans = ans * ft[c] % 998244353;
  c = 0;
  for (int i = primes.size() - 1; i >= 0 && powe[i] > 0; --i) {
    c += powe[i];
    ans = ans * rft[powe[i]] % 998244353;
  }
  ans = ans * ft[c] % 998244353;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> d >> q;
  build();
  for (int i = 0; i < q; ++i) quer();
  return 0;
}
