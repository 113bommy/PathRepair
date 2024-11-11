#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a) {
  unsigned long long res = 0;
  unsigned long long div = 2;
  while (div <= a) {
    res += a / div;
    if (a - div < div) {
      break;
    }
    div *= 2;
  }
  return res;
}
const unsigned long long mod = 1000003ULL;
unordered_map<unsigned long long, unsigned long long> dp;
unsigned long long mod2exp(unsigned long long p) {
  if (dp.find(p) != dp.end()) {
    return dp[p];
  }
  return dp[p] = (mod2exp(p / 2) * mod2exp(p / 2 + p % 2)) % mod;
}
bool bigger(unsigned long long k, unsigned long long n) {
  unsigned long long curr = 1;
  while (n > 0) {
    if (k - curr < curr) {
      return false;
    }
    curr *= 2;
    n--;
  }
  return k > curr;
}
int main() {
  unsigned long long n, k;
  cin >> n >> k;
  if (bigger(k, n)) {
    cout << 1 << " " << 1;
    return 0;
  }
  dp[0] = 1;
  dp[1] = 2;
  unsigned long long g = gcd(k - 1);
  unsigned long long b = mod2exp(
      ((n % (mod - 1)) * ((k - 1) % (mod - 1)) - (g % (mod - 1)) + (mod - 1)) %
      (mod - 1));
  unsigned long long a = 1;
  if (k - 1 >= mod) {
    a = 0;
  } else {
    int erased = 0;
    for (unsigned long long i = k - 1; i >= 1; --i) {
      int twos = 0;
      for (int p = i; p % 2 == 0; p /= 2, twos++)
        ;
      int rm = 0;
      if (erased < g && twos > 0) {
        rm = min(twos, (int)g - erased);
        erased += rm;
      }
      a *= (mod2exp(n - rm) - (i / mod2exp(rm)) + mod) % mod;
      a %= mod;
    }
  }
  a = (b - a + mod) % mod;
  cout << a << " " << b;
  return 0;
}
