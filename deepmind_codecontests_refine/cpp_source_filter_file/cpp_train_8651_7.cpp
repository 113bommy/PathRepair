#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  long long la, ra, ta, lb, rb, tb;
  cin >> la >> ra >> ta;
  cin >> lb >> rb >> tb;
  long long d = gcd(ta, tb);
  long long l0, l1, r0, r1;
  l0 = la % d;
  r0 = l0 + (ra - la);
  l1 = lb % d;
  r1 = l1 + (rb - lb);
  long long res = 0;
  long long l, r;
  l = max(l0, l1);
  r = min(r0, r1);
  res = max(res, r - l + 1);
  l = max(l0 + d, l1);
  r = min(r0 + d, r1);
  res = max(res, r - l + 1);
  l = max(l0, l1 + d);
  r = min(l0, r1 + d);
  res = max(res, r - l + 1);
  cout << res;
  return 0;
}
