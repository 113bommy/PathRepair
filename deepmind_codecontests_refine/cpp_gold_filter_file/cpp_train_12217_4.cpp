#include <bits/stdc++.h>
using namespace std;
long long p(long long l) {
  if (l < 10) return l;
  long long f, t, ret;
  t = l % 10;
  f = l;
  while (f >= 10) f /= 10;
  ret = l / 10 + 9;
  if (t < f) ret--;
  return ret;
}
int main() {
  long long l, r;
  cin >> l >> r;
  cout << p(r) - p(l - 1) << endl;
  return 0;
}
