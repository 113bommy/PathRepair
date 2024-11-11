#include <bits/stdc++.h>
using namespace std;
int fast_mod_pow(int x, int y, int mod) {
  int res = 1;
  while (y > 0) {
    if ((y & 1) == 1) {
      res = ((long long)res * x) % mod;
    }
    y >>= 1;
    x = ((long long)x * x) % mod;
  }
  return res;
}
int inverse_mod(int n, int p) { return fast_mod_pow(n, p - 2, p); }
int divide_mod(int a, int b, int mod) {
  return ((long long)a * inverse_mod(b, mod)) % mod;
}
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  int maxi = -1;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    maxi = max(maxi, A[i]);
  }
  int best = 2e9;
  maxi /= 3;
  for (int ones = 0; ones <= 1; ++ones) {
    for (int twos = 0; twos <= 1; ++twos) {
      for (int threes = max(0, maxi - 1); threes <= maxi; ++threes) {
        int k = ones + twos + threes;
        if (k >= best) {
          break;
        }
        bool valid = true;
        for (int i = 0; i < n; ++i) {
          int a = A[i];
          bool found = false;
          for (int x = 0; x <= ones; ++x) {
            for (int y = 0; y <= twos; ++y) {
              int rem = a - x - 2 * y;
              if (rem >= 0 and rem % 3 == 0 and rem / 3 <= threes) {
                found = true;
                break;
              }
            }
          }
          if (not found) {
            valid = false;
            break;
          }
        }
        if (valid) {
          best = k;
        }
      }
    }
  }
  cout << best << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
