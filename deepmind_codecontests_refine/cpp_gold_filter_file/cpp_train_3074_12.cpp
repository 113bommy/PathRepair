#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s, x;
  cin >> s >> x;
  long long andd = (s - x) >> 1;
  if (s < x || (s - x) % 2 != 0 || (x & andd) != 0) return puts("0"), 0;
  int bit = 0;
  while (x) {
    if (x & 1) ++bit;
    x >>= 1;
  }
  long long ans = 1ll << bit;
  if (andd == 0) ans -= 2;
  cout << ans << endl;
  return 0;
}
