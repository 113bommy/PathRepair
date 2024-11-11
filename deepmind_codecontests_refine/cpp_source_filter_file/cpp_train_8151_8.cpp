#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int t1, t2, t3, t4, t5;
  t1 = (l * k) / n;
  t2 = c * d;
  t3 = p / np;
  t4 = min({t1, t2, t3});
  t5 = t4 / n;
  cout << t5 << '\n';
  return 0;
}
