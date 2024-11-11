#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-9;
long long l, r;
long long mirr(long long x) {
  long long z = 1;
  while (z <= x) {
    z *= 10;
  }
  return z - x - 1;
}
int main() {
  cout.flags(ios::fixed);
  cout.precision(2);
  cin >> l >> r;
  long long z = 1;
  while (z <= r) {
    z *= 10;
  }
  l = max(l, z / 10);
  while (r - l > 10) {
    long long A = (2 * l + r) / 3, B = (l + 2 * r) / 3;
    if (A * mirr(A) < B * mirr(B))
      l = A;
    else
      r = B;
  }
  long long ans = 0;
  for (long long i = l; i <= r; i++) {
    ans = max(ans, i * mirr(i));
  }
  cout << ans;
  return 0;
}
