#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int x = (p / (n * np));
  int y = (k * l) / (n * nl);
  int z = (c * d) / n;
  int r = (x > y) ? ((z > y) ? y : z) : ((z > x) ? x : z);
  cout << r;
  return 0;
}
