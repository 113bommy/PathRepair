#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
const long long MOD = 1e9 + 7;
const double PI = atan2(0, -1);
const long long inf = 1e9 + 10;
const long long infl = 2e18;
const double eps = 1e-7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(20) << fixed;
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k) {
    if (n == 1)
      s[0] = '0';
    else {
      if (s[0] != 1) {
        k--;
        s[0] = '1';
      }
      for (long long i = 1; i < n and k; i++) {
        if (s[i] == '0') continue;
        s[i] = '0';
        k--;
      }
    }
  }
  cout << s;
}
