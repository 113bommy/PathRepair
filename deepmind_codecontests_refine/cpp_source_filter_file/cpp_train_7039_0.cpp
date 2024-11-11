#include <bits/stdc++.h>
using namespace std;
int l, r, t1, t2, lk, rk;
long long int res, t3 = 1;
long long int ref(int r, int rk) {
  long long int res = 0, keta = 1;
  while (rk-- > 0) {
    res += (9 - (r % 10)) * keta;
    r /= 10;
    keta *= 10;
  }
  return res;
}
int main() {
  cin >> l >> r;
  t1 = l;
  t2 = r;
  while (t1 != 0) {
    lk++;
    t1 /= 10;
  }
  while (t2 != 0) {
    rk++;
    t2 /= 10;
  }
  for (int i = 0; i < rk; i++) t3 *= 10;
  t3 /= 2;
  if (rk > lk) {
    if (rk >= t3 - 1)
      res = (t3 - 1) * t3;
    else
      res = r * ref(r, rk);
  } else {
    if (l >= t3 - 1)
      res = l * ref(l, lk);
    else if (r >= t3 - 1)
      res = t3 * (t3 - 1);
    else
      res = r * ref(r, rk);
  }
  cout << res << endl;
  return 0;
}
