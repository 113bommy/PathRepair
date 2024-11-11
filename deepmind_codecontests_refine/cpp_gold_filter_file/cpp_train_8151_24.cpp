#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int c1, c2, c3;
  c1 = ((k * l) / n) / nl;
  int min = c1;
  c2 = (c * d) / n;
  if (c2 < min) {
    min = c2;
  }
  c3 = (p / n) / np;
  if (c3 < min) {
    min = c3;
  }
  cout << min << endl;
  return 0;
}
