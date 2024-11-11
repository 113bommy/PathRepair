#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, p, d, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  l *= k;
  c *= d;
  p /= np;
  p /= n;
  l /= nl;
  l /= n;
  c /= n;
  cout << min(min(p, c), l) << endl;
}
