#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int cur = 1;
    while (n > (1ull << 2 * cur) - 1) cur++;
    cur--;
    n -= 1ll << 2 * cur;
    int mod = n % 3;
    n /= 3;
    long long a = (1 << 2 * cur) + n, tmp = a;
    if (mod == 0)
      cout << a << '\n';
    else {
      long long b = 0;
      int cnt = 0, x;
      while (tmp) {
        switch (tmp & 3) {
          case 0:
            x = 0;
            break;
          case 1:
            x = 2;
            break;
          case 2:
            x = 3;
            break;
          case 3:
            x = 1;
            break;
        }
        b |= 1ll * x << 2 * cnt;
        cnt += 1;
        tmp >>= 2;
      }
      if (mod == 1) cout << b << '\n';
      if (mod == 2) cout << (a ^ b) << '\n';
    }
  }
}
