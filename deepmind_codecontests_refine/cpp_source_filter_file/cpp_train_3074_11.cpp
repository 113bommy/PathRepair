#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll s, x;
  cin >> s >> x;
  if (s - x < 0) {
    cout << 0 << endl;
    return 0;
  }
  ll m = s - x;
  if (m & 1) {
    cout << 0 << endl;
    return 0;
  }
  m >>= 1;
  if ((x & m) != 0) {
    cout << 0 << endl;
    return 0;
  }
  const int cnt = __builtin_popcount(x);
  if (m == 0) {
    cout << (1LL << cnt) - 2 << endl;
  } else {
    cout << (1LL << cnt) << endl;
  }
}
