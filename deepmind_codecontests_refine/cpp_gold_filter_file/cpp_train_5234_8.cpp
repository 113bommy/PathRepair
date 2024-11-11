#include <bits/stdc++.h>
using namespace std;
long long t, n, s, ans;
int sum(long long x) {
  int tong = 0;
  while (x > 0) {
    tong += x % 10;
    x = x / 10;
  }
  return tong;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    ans = n;
    if (sum(n) <= s) {
      cout << 0 << endl;
      continue;
    }
    long long Pow = 10;
    for (int i = 1; i <= 19; i++) {
      long long luu = n % Pow;
      long long x = Pow - luu;
      n = n + x;
      if (sum(n) <= s) {
        break;
      }
      Pow = Pow * 10;
    }
    cout << n - ans << endl;
  }
}
