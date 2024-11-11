#include <bits/stdc++.h>
using namespace std;
long long int mypow(long long int base, long long int power,
                    long long int mod) {
  long long int prod = 1;
  if (power == 0) return 1;
  if (mod > 0) {
    while (power / 2 > 0) {
      if (power % 2) prod = (prod * base) % mod;
      power /= 2;
      base = (base * base) % mod;
    }
    if (power % 2) prod = (prod * base) % mod;
    if (prod < 0) prod += mod;
  } else {
    while (power / 2 > 0) {
      if (power % 2) prod = (prod * base);
      power /= 2;
      base = (base * base);
    }
    if (power % 2) prod = (prod * base);
  }
  return prod;
}
bool prime_test_miller(long long int p) {
  if (p < 2) return false;
  if (p != 2 && p % 2 == 0) return false;
  if (p < 12) {
    if (p == 2 || p == 3 || p == 5 || p == 7 || p == 11)
      return true;
    else
      return false;
  }
  long long int s = p - 1;
  while (s % 2 == 0) s /= 2;
  long long int a, tmp, seed[5] = {2, 3, 5, 7, 11};
  for (int i = 0; i < 5; i++) {
    a = seed[i];
    tmp = s;
    long long int mod = mypow(a, tmp, p);
    while (tmp != p - 1 && mod != 1 && mod != p - 1) {
      mod = mypow(mod, 2, p);
      tmp *= 2;
    }
    if (mod != p - 1 && tmp % 2 == 0) return false;
  }
  return true;
}
int main() {
  int t, cnd, cnu;
  long long int n, d, num, den;
  cin >> t;
  while (t--) {
    cin >> n;
    d = n;
    n++;
    while (!prime_test_miller(n)) n++;
    cnu = n;
    n = d;
    while (!prime_test_miller(n)) n--;
    cnd = n;
    num = cnu - 2;
    den = 2 * cnu;
    if (cnu != d + 1) {
      num = cnd * num;
      den = den * cnd;
      num -= (cnu - 1 - d) * 2;
    }
    cout << num << "/" << den << endl;
  }
}
