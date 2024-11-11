#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
template <typename first>
inline first abs(const first& a) {
  return a < 0 ? -a : a;
}
template <typename first>
inline first sqr(const first& a) {
  return a * a;
}
const int INF = INT_MAX / 2;
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  bool ok = false;
  for (int i = 0; i < int(k); i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int d1 = min(x, n - x - 1);
    if (d1 <= 5) ok = true;
    int d2 = min(y, m - y - 1);
    if (d2 <= 5) ok = true;
  }
  if (ok)
    puts("YES");
  else
    puts("NO");
  return 0;
}
