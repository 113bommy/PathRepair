#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long q;
  cin >> q;
  while (q--) {
    long long a;
    long long b;
    long long m;
    cin >> a >> b >> m;
    if (a == b) {
      cout << 1 << " " << a << "\n";
      continue;
    }
    if (m == 1) {
      long long x[50];
      x[0] = a;
      long long r = a;
      long res = -1;
      for (long i = 1; i <= 50 - 1; ++i) {
        x[i] = x[i - 1] * 2 - r + 1;
        r = 1;
        if (x[i] >= b) {
          if (x[i] == b) res = i + 1;
          break;
        }
      }
      if (res == -1) {
        cout << "-1\n";
      } else {
        cout << res << " ";
        for (long i = 0; i <= res - 1; ++i) {
          cout << x[i] << " ";
        }
        cout << "\n";
      }
      continue;
    }
    if (b <= a + m) {
      cout << 2 << " " << a << " " << b << "\n";
      continue;
    }
    long k = 0;
    long long mul = 0;
    long res = -1;
    while (true) {
      ++k;
      if (mul == 0) {
        mul = 1;
      } else {
        mul *= 2;
      }
      long long min_ = (a + 1) * mul;
      long long max_ = (a + m) * mul;
      if (min_ > b) {
        break;
      }
      if (k > 49) {
        break;
      }
      if (max_ < b) {
        continue;
      }
      long long x = min_;
      mul /= 2;
      long long rs[k];
      for (long i = 0; i <= k - 1; ++i) {
        long long to_add = (b - x) / mul;
        if (to_add > m - 1) to_add = m - 1;
        rs[i] = 1 + to_add;
        x += to_add * mul;
        mul /= 2;
        if (mul == 0) mul = 1;
      }
      x = a;
      cout << k + 1 << " ";
      cout << x << " ";
      long long r = a;
      for (long i = 0; i <= k - 1; ++i) {
        x = x * 2 - r + rs[i];
        cout << x << " ";
        r = rs[i];
      }
      cout << "\n";
      res = 0;
      break;
    }
    if (res == -1) {
      cout << -1 << "\n";
    }
  }
  return 0;
}
