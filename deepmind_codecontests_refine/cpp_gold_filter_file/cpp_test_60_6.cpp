#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
inline bool isSame(double c, double d) { return abs(c - d) < 1e-9; }
long long binpow(long long base, long long exp, int mod) {
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return res;
}
long long mod(long long x) {
  return ((x % 1000000007LL + 1000000007LL) % 1000000007LL);
}
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
long long int decbin(string s) { return stoll(s, 0, 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int sum = 0;
    map<long long int, long long int> m;
    long long int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    if (((2 * sum) % n) != 0) {
      cout << 0 << "\n";
    } else {
      long long int x = 0, t = (2 * sum) / n;
      for (int i = 0; i < n; i++) {
        x += m[t - arr[i]];
        m[arr[i]]++;
      }
      cout << x << "\n";
    }
  };
  return 0;
}
