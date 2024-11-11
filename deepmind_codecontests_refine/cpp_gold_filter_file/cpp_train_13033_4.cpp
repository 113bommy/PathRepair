#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
long long x, n;
long long qpow(long long x, long long q) {
  long long ans = 1;
  while (q) {
    if (q & 1) ans = ans * x % Mod;
    q >>= 1;
    x = (x * x) % Mod;
  }
  return ans % Mod;
}
int main() {
  cin >> x >> n;
  vector<long long> a;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      a.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) a.push_back(x);
  long long sum = 1;
  for (long long i = 0; i < a.size(); i++) {
    long long t = 0, q = a[i], p = n;
    while (p) {
      t = (t + p / q);
      p /= q;
    }
    sum = (sum % Mod * qpow(a[i], t)) % Mod;
  }
  cout << sum << endl;
  return 0;
}
