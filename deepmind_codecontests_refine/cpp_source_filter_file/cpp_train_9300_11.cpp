#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long quick_power(long long a, long long b) {
  long long t = 1;
  while (b) {
    if (b & 1) {
      t = t * a % MOD;
    }
    a = a * a % MOD;
    b = b >> 1;
  }
  return t;
}
int main() {
  long long n, ans;
  cin >> n;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  ans = quick_power(2, n - 1);
  ans = (ans * 2 % MOD + 1) * ans % MOD;
  cout << ans << endl;
  return 0;
}
