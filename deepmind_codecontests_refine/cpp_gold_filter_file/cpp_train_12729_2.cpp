#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a, b, c, d;
  cin >> a >> b >> c;
  d = a + b;
  sort(d.begin(), d.end());
  sort(c.begin(), c.end());
  (d == c) ? cout << "YES" : cout << "NO";
  return 0;
}
