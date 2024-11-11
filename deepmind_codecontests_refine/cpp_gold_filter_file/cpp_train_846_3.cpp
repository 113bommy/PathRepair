#include <bits/stdc++.h>
using namespace std;
long long modpow(long long base, long long exp, long long modulus) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  long long a[n], aa[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> aa[i];
  long long l = 0, r = 0;
  multiset<long long> s;
  vector<long long> v;
  for (long long i = 0; i < n; i++) s.insert(aa[i]);
  for (long long i = 0; i < n; i++) {
    auto it = s.lower_bound(n - a[i]);
    if (it == s.end()) {
      auto itt = s.begin();
      cout << (a[i] + (long long)(*itt) % n) << " ";
      s.erase(itt);
    } else {
      cout << ((a[i] + (*it)) % n) << " ";
      s.erase(it);
    }
  }
  return 0;
}
