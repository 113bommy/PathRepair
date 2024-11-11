#include <bits/stdc++.h>
using namespace std;
const int N = 2000100;
const int MOD = 1e9 + 7;
const long long inf = 1e18 + 5;
int _;
int main() {
  long long n, q;
  cin >> n >> q;
  long long k = (2 * n) - 1;
  while (q--) {
    long long x;
    cin >> x;
    if (x % 2 != 0) {
      cout << (x / 2) + 1 << endl;
      continue;
    }
    x = k - x + 1;
    bool cond = false;
    for (int i = 0; i < 60; ++i) {
      if (x % (long long)pow(2, i) == 0) {
        long long v = x / (long long)pow(2, i);
        if ((v - 1) % 2 == 0) {
          long long gg = (v - 1) / 2;
          cout << (n - gg) << endl;
          cond = true;
          break;
        }
        if (cond) break;
      }
      if (cond) break;
    }
  }
  return 0;
}
