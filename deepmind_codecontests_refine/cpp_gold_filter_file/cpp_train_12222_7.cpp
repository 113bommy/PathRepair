#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int pec = power(a, b / 2), mod = 1000000007;
  if (b % 2 == 1) {
    return (((pec * pec) % mod) * a) % mod;
  } else
    return ((pec * pec) % mod);
}
long long int solve(string s) {
  long long int mod = 1000000007, n = s.size(), fac = 1, ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '5' || s[i] == '0') {
      ans += fac;
      ans %= mod;
    }
    fac *= 2;
    fac %= mod;
  }
  return ans;
}
int main() {
  string s;
  long long int k, n;
  cin >> s >> k;
  n = s.size();
  long long int mod = 1000000007;
  long long int numerator = (power(2, n * k) - 1 + mod) % mod;
  long long int denominator = (power(2, n) - 1 + mod) % mod;
  denominator = power(denominator, mod - 2);
  long long int factor = (numerator * denominator) % mod;
  cout << (factor * solve(s)) % mod;
}
