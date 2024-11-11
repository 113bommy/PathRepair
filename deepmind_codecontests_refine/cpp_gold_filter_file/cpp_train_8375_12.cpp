#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
int bits(long long nm) {
  int rs = 0;
  while (nm) {
    rs += (nm % 2);
    nm /= 2;
  }
  return rs;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  long long l, r;
  while (n--) {
    cin >> l >> r;
    int mx = bits(l);
    long long ans = l;
    for (int i = 0; i < 63; ++i) {
      l = (l | (1ll << i));
      if (l <= r) {
        if (mx < bits(l)) {
          mx = bits(l);
          ans = l;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
