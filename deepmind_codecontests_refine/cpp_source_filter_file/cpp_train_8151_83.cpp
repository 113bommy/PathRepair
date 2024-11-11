#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int enough = (k * l) / (nl);
  int limes = (c * d) / n;
  int salt = (p / (n * p));
  cout << min(min(enough, limes), salt) / n << '\n';
}
