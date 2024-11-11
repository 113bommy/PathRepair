#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long k;
  unsigned long long tmp, mx, my, mz, x, y, z;
  cin >> mx >> my >> mz >> k;
  mx--;
  my--;
  mz--;
  if (my < mz) {
    tmp = mz;
    mz = my;
    my = tmp;
  }
  if (mx < my) {
    tmp = mx;
    mx = my;
    my = tmp;
  }
  if (my < mz) {
    tmp = mz;
    mz = my;
    my = tmp;
  }
  x = y = z = k / 3;
  k -= (x + y + z);
  if (k != 0) {
    x++;
    k--;
  }
  if (k != 0) {
    y++;
    k--;
  }
  if (mz < z) {
    int tmp = (z - mz);
    x += tmp / 2;
    y += tmp - tmp / 2;
    z = mz;
  }
  if (my < y) {
    x += (y - my);
    y = my;
  }
  if (mx < x) x = mx;
  cout << (x + 1) * (y + 1) * (z + 1) << endl;
}
