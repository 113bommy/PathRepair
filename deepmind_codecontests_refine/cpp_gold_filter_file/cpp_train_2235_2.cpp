#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, a1, b1, max = 0, u, d, res = 0, j, tiv1[10] = {0}, y,
                    tiv2[10] = {0}, i, ost, cur, ind, k;
  bool t;
  cin >> a >> b;
  a1 = a;
  b1 = b;
  while (a1 > 0) {
    if ((a1 % 10) > max) max = a1 % 10;
    a1 /= 10;
  }
  while (b1 > 0) {
    if ((b1 % 10) > max) max = b1 % 10;
    b1 /= 10;
  }
  max++;
  j = 0;
  while (a > 0) {
    tiv1[j] = a % 10;
    a /= 10;
    j++;
  }
  i = 0;
  while (b > 0) {
    tiv2[i] = b % 10;
    b /= 10;
    i++;
  }
  for (y = max; y <= 20; y++) {
    ost = 0;
    cur = 0;
    ind = 1;
    k = 1;
    t = true;
    cur = (tiv1[0] + tiv2[0]) / y;
    while (t) {
      if (k >= i && k >= j && cur == 0) t = false;
      cur = (cur + tiv1[k] + tiv2[k]) / y;
      ind++;
      k++;
    }
    if (ind > res) res = ind;
  }
  cout << res - 1;
  return 0;
}
