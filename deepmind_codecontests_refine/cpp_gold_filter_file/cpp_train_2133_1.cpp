#include <bits/stdc++.h>
using namespace std;
long long A, B, n;
long long l, t, m;
int main() {
  cin >> A >> B >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >> t >> m;
    long long li = l;
    long long ri = l + 1e6 + 1;
    long long sl = A + (l - 1) * B;
    if (sl > t) {
      cout << -1 << endl;
      continue;
    }
    while (li + 1 < ri) {
      long long mid = (li + ri) / 2;
      long long val =
          (mid - l + 1) * A + B * ((l + mid - 2) * (mid - l + 1) / 2);
      long long range = min(m, (mid - l + 1));
      long long sr = A + (mid - 1) * B;
      if (sr > t) {
        ri = mid;
        continue;
      }
      if (val > range * t)
        ri = mid;
      else
        li = mid;
    }
    cout << li << endl;
  }
  return 0;
}
