#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int s, x;
  cin >> s >> x;
  int bits = __builtin_popcountll(x);
  long long int ans = 2ll << (bits - 1);
  if (s == x) ans -= 2;
  if (x == 0) ans = 1;
  long long int z = s - x;
  long long int mask = 0;
  for (int i = 55; i >= 0; i--) {
    if (!((x >> i) & 1)) mask |= 1ll << i;
  }
  mask <<= 1;
  if ((mask & z) == z)
    cout << ans << endl;
  else
    cout << 0 << endl;
  return 0;
}
