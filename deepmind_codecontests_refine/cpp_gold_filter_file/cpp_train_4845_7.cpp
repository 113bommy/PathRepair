#include <bits/stdc++.h>
using namespace std;
long long Pow[11], test, n;
string s;
long long digits(long long x) {
  long long d = 0;
  while (x) ++d, x /= 10;
  return d;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Pow[0] = 1;
  for (long long i = 1; i <= 10; ++i) Pow[i] = Pow[i - 1] * 10;
  cin >> test;
  while (test--) {
    cin >> s;
    n = 0;
    long long m = 1, x;
    while (isdigit(s.back())) n += m * (s.back() - '0'), m *= 10, s.pop_back();
    x = 0;
    for (long long i = 1; i < digits(m / 10); ++i) x += Pow[i];
    x += 1988;
    while (n <= x) n += m;
    cout << n << endl;
  }
  return 0;
}
