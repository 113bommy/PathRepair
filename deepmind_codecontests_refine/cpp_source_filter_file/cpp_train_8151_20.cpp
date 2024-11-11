#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int min1 = min(k * l / nl, c * d);
  int min2 = min(c * d, p / np);
  cout << min(min1, min2) / 3 << endl;
  return 0;
}
