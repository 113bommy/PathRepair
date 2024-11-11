#include <bits/stdc++.h>
using namespace std;
long long mod_power(long long n, long long x, long long mod) {
  long long res = 1;
  n = n % mod;
  if (n == 0) {
    return 0;
  }
  while (x > 0) {
    if (x & 1) {
      res = (res * n) % mod;
    }
    x = x >> 1;
    n = (n * n) % mod;
  }
  return res;
}
long long power(long long n, long long x) {
  long long res = 1;
  while (x > 0) {
    if (x & 1) {
      res = res * n;
    }
    x = x >> 1;
    n = n * n;
  }
  return res;
}
long long countDigit(long long n) {
  if (n == 0) return 0;
  return 1 + countDigit(n / 10);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long x;
    cin >> x;
    string w = "";
    long long n = s.size();
    for (long long i = 0; i < n; i++) {
      w += '1';
    }
    for (long long i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (i - x >= 0) {
          w[i - x] = '0';
        }
        if (i + x < n) {
          w[i + x] = '0';
        }
      }
    }
    bool okay = true;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '1') {
        bool check1 = false, check2 = false;
        if (i - x >= 0) {
          if (w[i - x] == '1') {
            check1 = true;
          }
        }
        if (i + x < n) {
          if (w[i + x] == '1') {
            check2 = true;
          }
        }
        if (check1 == true || check2 == true) {
        } else {
          okay = false;
          break;
        }
      }
    }
    if (okay == true) {
      cout << w << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
