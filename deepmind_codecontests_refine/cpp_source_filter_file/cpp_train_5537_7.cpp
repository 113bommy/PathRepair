#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, w, e, r, t;
  cin >> q >> w >> e >> r >> t;
  long long a = q * (e - 1);
  a += w * (r - 1);
  if (a > t)
    cout << "0 ";
  else
    cout << min(q + w, t - a) << " ";
  if (e > r) {
    long long y = t / e;
    y = min(y, q);
    t -= (y * e);
    y += (t / r);
    cout << min(y, q + w);
  } else {
    long long y = t / r;
    y = min(y, w);
    t -= (y * r);
    y += (t / e);
    cout << min(y, q + w);
  }
  return 0;
}
