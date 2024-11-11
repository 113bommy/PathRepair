#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll s, x;
  cin >> s >> x;
  ll a = s - x;
  if (a < 0 || a % 2 != 0) {
    puts("0");
    return 0;
  }
  a /= 2;
  if (x & a) {
    puts("0");
    return 0;
  }
  if (a != 0) {
    ll b = __builtin_popcountll(x);
    cout << (1LL << b) << endl;
    return 0;
  }
  ll b = __builtin_popcountll(x);
  if (b < 2) {
    cout << 0 << endl;
    return 0;
  }
  cout << (1LL << (b - 1)) << endl;
  return 0;
}
