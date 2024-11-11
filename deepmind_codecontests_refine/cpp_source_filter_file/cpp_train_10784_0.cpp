#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10;
long long T, x, y, p, q;
bool Ok(int a) {
  return (a * p >= x && a * q >= y && (a * q) - y >= (a * p) - x);
}
int BS() {
  int l = 0, r = inf, mid;
  while (l + 1 != r) {
    mid = (l + r) / 2;
    if (!Ok(mid))
      l = mid;
    else
      r = mid;
  }
  if (l + 10 >= inf) return -1;
  return (r * q - y);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> x >> y >> p >> q;
    cout << BS() << endl;
  }
}
