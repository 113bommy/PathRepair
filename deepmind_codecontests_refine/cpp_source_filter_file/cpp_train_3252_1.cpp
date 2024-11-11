#include <bits/stdc++.h>
std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
using namespace std;
const long long mod = 998244353;
long long T, n, x, fl, p, sum, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    p = 1;
    sum = 0;
    fl = n % 3;
    if (!fl)
      x = n / 3;
    else
      x = n / 3 + 1;
    while (sum + p < x) {
      sum += p;
      p *= 4;
    }
    p += x - sum - 1;
    if (fl == 1)
      cout << p << '\n';
    else {
      b = 0;
      x = 63 - __builtin_clzll(p);
      p ^= (1 << x);
      for (int i = 0; i < 62; i += 2) {
        if ((((1LL << i) | (1LL << (i + 1))) & p) >> i == 1)
          b |= (1LL << (i + 1));
        else if ((((1LL << i) | (1LL << (i + 1))) & p) >> i == 2)
          b |= ((1LL << i) | (1LL << (i + 1)));
        else if ((((1LL << i) | (1LL << (i + 1))) & p) >> i == 3)
          b |= (1LL << (i));
      }
      b ^= (1 << (x + 1));
      p ^= (1 << x);
      if (fl)
        cout << b << '\n';
      else
        cout << (b ^ p) << '\n';
    }
  }
  return 0;
}
