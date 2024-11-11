#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int Pow(int x, int64_t y) {
  int ret = 1;
  for (; y > 0; y /= 2) {
    if (y & 1) ret = (int64_t)ret * x % MOD;
    x = (int64_t)x * x % MOD;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  bool ok = true;
  int cnt2 = 0;
  int64_t first = -1;
  int ans = 2;
  vector<int> A;
  while (k-- > 0) {
    int64_t x;
    cin >> x;
    if (x != 1) {
      ok = false;
    }
    if (x >= 2) {
      first = x;
      cnt2++;
    }
    ans = Pow(ans, x);
    A.push_back(x);
  }
  if (ok) {
    cout << "0/1\n";
  } else if (cnt2 == 1 && first == 2) {
    cout << "1/2\n";
  } else {
    ans = (int64_t)ans * Pow(2, MOD - 2) % MOD;
    int ans1 = (ans - 1 + MOD) % MOD;
    bool even = false;
    for (int64_t x : A) {
      if (x % 2 == 0) {
        even = true;
      }
    }
    if (!even) {
      int rv = ans;
      rv = (rv - 1 + MOD) % MOD;
      rv = (int64_t)rv * Pow(3, MOD - 2) % MOD;
      ans1 = (ans1 - 2LL * rv + 2LL * MOD) % MOD;
    } else {
      int rv = (int64_t)ans * Pow(2, MOD - 2) % MOD;
      rv = (rv - 1 + MOD) % MOD;
      rv = (int64_t)rv * Pow(3, MOD - 2) % MOD;
      rv = (int64_t)rv * 2 % MOD;
      ans1 = (ans1 - 2LL * rv + 2LL * MOD) % MOD;
    }
    cout << ans1 << ' ' << ans << '\n';
  }
}
