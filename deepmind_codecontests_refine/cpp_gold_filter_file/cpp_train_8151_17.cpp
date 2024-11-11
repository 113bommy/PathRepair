#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int kol;
  kol = min(min(k * l / nl, c * d), min(c * d, p / np)) / n;
  cout << kol;
  return 0;
}
