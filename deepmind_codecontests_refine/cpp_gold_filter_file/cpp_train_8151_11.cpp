#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, l, c, d, p, nl, np, t1, t2, t3, t4, t5;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  t1 = (l * k) / nl;
  t2 = c * d;
  t3 = p / np;
  t4 = min(t1, t2);
  t5 = min(t2, t3);
  cout << min(t4, t5) / n;
  return 0;
}
