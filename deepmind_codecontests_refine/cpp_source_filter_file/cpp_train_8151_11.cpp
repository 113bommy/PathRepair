#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  cout << min((k * l) / n, min(c * d, p / np)) / 3;
  return 0;
}
