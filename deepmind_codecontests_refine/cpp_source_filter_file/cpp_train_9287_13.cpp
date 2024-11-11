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
const long double pi = acos(-1);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long double n, d;
    cin >> n >> d;
    if (d <= n)
      cout << "YES" << endl;
    else {
      long long sq = sqrt(n);
      bool ok = 0;
      for (long long i = 1; i < sq + 1; i++) {
        long double x = d / (i + 1);
        if (i + ceil(x) <= n) {
          cout << "YES" << endl;
          ok = 1;
          break;
        }
      }
      if (!ok) cout << "NO" << endl;
    }
  }
  return 0;
}
