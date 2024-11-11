#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int a = (k * l) / n;
  int b = c * d;
  int t = p / np;
  cout << min(a, min(b, t)) / n;
  return 0;
}
