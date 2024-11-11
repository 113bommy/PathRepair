#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long mod_pow(long long a, long long b) {
  if (!b) return 1;
  long long c = mod_pow((a * a) % MOD, b / 2);
  return (b % 2 ? a * c : c) % MOD;
}
int n;
string s;
long long k;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s >> k;
  n = s.size();
  long long q = (mod_pow(2, (k * n) % MOD) - 1 + MOD) % MOD;
  long long c = (mod_pow(2, n) - 1 + MOD) % MOD;
  c = mod_pow(c, MOD - 2);
  long long d = (q * c) % MOD;
  long long acc = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0' || s[i] == '5') {
      long long a = mod_pow(2, i);
      acc = (acc + ((a * d) % MOD)) % MOD;
    }
  }
  cout << acc << endl;
  return 0;
}
