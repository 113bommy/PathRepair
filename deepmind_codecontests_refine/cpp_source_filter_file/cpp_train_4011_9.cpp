#include <bits/stdc++.h>
using namespace std;
const int C = 1000000;
int main() {
  ios_base::sync_with_stdio(0);
  long long s, x, a;
  cin >> s >> x;
  a = x;
  int k1 = 0;
  long long y = 0, c = 0;
  while (x > 0) {
    if (x % 2)
      k1++;
    else {
      c += (1ll << (y + 1));
    }
    y++;
    x /= 2;
  }
  while ((1ll << (y + 1)) <= s) {
    c += (1ll << (y + 1));
    y++;
  }
  if (((s - a) & c) < (s - a)) {
    cout << 0 << endl;
    return 0;
  }
  long long t = (1ll << k1);
  if (s - a == 0)
    cout << t - 2;
  else
    cout << t << endl;
  return 0;
}
