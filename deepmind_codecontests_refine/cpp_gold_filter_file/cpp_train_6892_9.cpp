#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, x, y, t;
  cin >> a >> b >> x >> y >> t;
  if (b == a) {
    cout << x << ' ' << y;
    return;
  }
  if (t == a) {
    cout << x << " 0";
    return;
  }
  if (t == b) {
    cout << "0 " << y;
    return;
  }
  long long p = 0, q = y;
  long double T = (b - t), TT;
  for (long long i = 1; i < x + 1; i++) {
    long long z = (i * (-a + t)) / (b - t);
    if ((i * (t - a)) % (b - t)) z++;
    z = min(y, z);
    TT = ((a * i + b * z) * 1.0) / (i + z) - t;
    if (T < 0 && TT >= 0) {
      T = TT;
      p = i;
      q = z;
    } else if (TT >= 0 && TT <= T) {
      T = TT;
      p = i;
      q = z;
    }
  }
  cout << p << ' ' << q;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  while (T--) solve();
  return 0;
}
