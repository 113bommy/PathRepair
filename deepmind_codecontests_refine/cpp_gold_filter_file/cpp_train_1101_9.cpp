#include <bits/stdc++.h>
using namespace std;
set<long long> S;
long long b, q, l, m, rs;
int main() {
  cin >> b >> q >> l >> m;
  for (long long x; m--;) {
    cin >> x;
    S.insert(x);
  }
  if (abs(b) > l) return cout << 0, 0;
  if (q == 0 || b == 0) {
    if (S.count(0))
      return cout << (S.count(b) == 0), 0;
    else
      return cout << "inf", 0;
  }
  if (q == 1) {
    if (S.count(b))
      return cout << 0, 0;
    else
      return cout << "inf", 0;
  }
  if (q == -1) {
    if (S.count(-b) && S.count(b))
      return cout << 0, 0;
    else
      return cout << "inf", 0;
  }
  while (abs(b) <= l) rs += (S.count(b) == 0), b *= q;
  cout << rs;
}
