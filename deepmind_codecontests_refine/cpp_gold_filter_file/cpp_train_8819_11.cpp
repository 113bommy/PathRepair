#include <bits/stdc++.h>
using namespace std;
const unsigned long long MOD = 1e9 + 7;
unsigned long long bgmd(unsigned long long a, unsigned long long b) {
  unsigned long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    b /= 2;
  }
  return ans;
}
int main() {
  unsigned long long x, k;
  cin >> x >> k;
  if (x == 0) return cout << "0\n", 0;
  x %= MOD;
  unsigned long long ad = (bgmd(2LL, k) * x) % MOD;
  unsigned long long le = (bgmd(2LL, k)) % MOD;
  cout << (2LL * ad - le + 1 + MOD) % MOD << endl;
  return 0;
}
