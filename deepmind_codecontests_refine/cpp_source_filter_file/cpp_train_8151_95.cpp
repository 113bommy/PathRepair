#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np, sum = 0;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  d = d * c;
  l = k * l;
  for (int i = 0; i < 1000; i++) {
    if (l - nl < 0) {
      cout << sum / n << endl;
      return 0;
    } else
      l = l - nl;
    if (d - 1 < 0) {
      cout << sum / n << endl;
      return 0;
    } else
      d = d - 1;
    if (p - np < 0) {
      cout << sum / n << endl;
      return 0;
    } else
      p = p - np;
    sum++;
  }
  return 0;
}
