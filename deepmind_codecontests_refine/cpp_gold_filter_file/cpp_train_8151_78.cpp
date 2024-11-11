#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int Res = min((k * l) / nl, (c * d));
  Res = min(Res, (p / np));
  Res /= n;
  cout << Res;
  return 0;
}
