#include <bits/stdc++.h>
using namespace std;
long long getDigits(long long n) {
  long long lar = 0;
  long long smal = 9;
  while (n != 0) {
    long long r = n % 10;
    lar = max(r, lar);
    smal = min(r, smal);
    n = n / 10;
  }
  return lar * smal;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    bool flag = 1;
    for (long long i = 1; i < k; i++) {
      long long ans = getDigits(n);
      if (ans == 0) {
        cout << n << '\n';
        flag = 0;
        break;
      }
      n = n + ans;
    }
    if (flag) cout << n << '\n';
  }
}
