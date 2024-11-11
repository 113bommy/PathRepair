#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int h1, h2, h3;
  h1 = (k * l) / n;
  h2 = c * d;
  h3 = p * np;
  int h = min(h1, h2);
  cout << min(h, h3) / 3 << endl;
  ;
  return 0;
}
