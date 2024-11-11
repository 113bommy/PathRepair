#include <bits/stdc++.h>
using namespace std;
long long exp(long long base, long long exp, long long mod);
int main() {
  long long years = 0, alt = 1;
  cin >> years;
  alt = exp(2, years, 1000000007);
  cout << ((alt * (alt + 1) / 2) % 1000000007) << endl;
  return 0;
}
long long exp(long long b, long long exp, long long mod) {
  if (exp == 0) {
    return 1;
  }
  long long base = b, r = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      r = (r * base) % mod;
    }
    base = (base * base) % mod;
    exp >>= 1;
  }
  return r % mod;
}
