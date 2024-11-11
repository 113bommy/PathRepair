#include <bits/stdc++.h>
using namespace std;
double l, v1, v2, x, y, tmp, m, s1, s2, s, t, le, r;
long long n, k, i;
int main() {
  cin >> n >> l >> v1 >> v2 >> k;
  i = 1;
  le = 1;
  r = 1000000000;
  n = n / k + (n % k == 0 ? 0 : 1);
  while (i != 1000000) {
    m = (le + r) / 2;
    x = (m * v2 - l) / (v2 - v1);
    y = m - x;
    s1 = y * v1;
    s2 = y * v2;
    s = s2 - s1;
    t = s / (v1 + v2);
    if ((n - 1) * (y + t) > x) {
      le = m;
    } else {
      r = m;
    }
    i++;
  }
  printf("%.10f", m);
}
