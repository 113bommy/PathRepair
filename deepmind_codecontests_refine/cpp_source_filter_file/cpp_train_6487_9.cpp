#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 1 || k > n) {
    ll res = 1;
    for (int i = 0; i < n; ++i) {
      res *= m;
      res %= MOD;
    }
    cout << res;
  } else if (k == n) {
    ll res = 1;
    for (int i = 0; i < (n + 1) / 2; ++i) {
      res *= m;
      res %= MOD;
    }
    cout << res;
  } else if (k % 2 == 0) {
    cout << m;
  } else if (k % 2 != 0) {
    cout << m * (m - 1);
  }
}
