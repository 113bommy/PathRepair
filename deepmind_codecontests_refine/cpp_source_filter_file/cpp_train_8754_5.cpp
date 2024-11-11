#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = size_t;
template <typename T>
inline T sqr(const T& a) {
  return a * a;
}
const int MOD = int(1e9 + 7.1);
inline void madd(int& x, int delta) {
  x += (x + delta < MOD ? delta : delta - MOD);
}
i64 gcd(i64 a, i64 b) {
  while (a && b) (a > b ? a %= b : b %= a);
  return a + b;
}
i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
bool isHere(i64 l, i64 r) {
  cout << (l + 1) << ' ' << r << endl;
  static string s;
  cin >> s;
  switch (s[0]) {
    case 'Y':
      return true;
    case 'N':
      return false;
    default:
      exit(1);
  }
}
int main() {
  cin.sync_with_stdio(false);
  int T = 1;
  for (int iTest = 1; iTest <= T; ++iTest) {
    srand(time(0));
    i64 n, k;
    cin >> n >> k;
    i64 l = 0, r = n;
    while (true) {
      while ((r - l) > 4 * k) {
        i64 mid = (l + r) / 2;
        if (isHere(l, mid)) {
          r = mid;
        } else {
          l = mid;
        }
        r = min(r + k, n);
        l = max(l - k, 0LL);
      }
      int x = rand() % (r - l);
      if (isHere(l + x, l + x + 1)) {
        break;
      }
      r = min(r + k, n);
      l = max(l - k, 0LL);
    }
  }
  return 0;
}
