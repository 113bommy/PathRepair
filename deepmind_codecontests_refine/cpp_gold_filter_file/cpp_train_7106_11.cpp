#include <bits/stdc++.h>
using namespace std;
long long fastpow(long long a, long long b,
                  long long m = (long long)(1e9 + 7)) {
  long long res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
int32_t main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> arr(n), brr(m);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> brr[i];
  }
  for (long long i = 0; i <= 1200; i++) {
    bool poss = true;
    vector<long long> c;
    for (auto a : arr) {
      bool yes = false;
      for (auto b : brr) {
        if (((a & b) | i) == i) {
          yes = true;
          c.push_back(a & b);
          break;
        }
      }
      if (!yes) {
        poss = false;
        break;
      }
    }
    if (poss) {
      long long val = c[0];
      for (auto x : c) {
        val = (val | x);
      }
      if (val == i) {
        cout << i << endl;
        exit(0);
      }
    }
  }
  return 0;
}
