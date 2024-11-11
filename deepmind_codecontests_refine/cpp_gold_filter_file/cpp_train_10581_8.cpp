#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= M;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % M;
    a = a * a % M;
  }
  return res % M;
}
const int N = 1e5 + 10;
int main() {
  double n, m;
  cin >> n >> m;
  double ans = M;
  while (n--) {
    double a, b;
    cin >> a >> b;
    ans = min(ans, a / b);
  }
  printf("%.9lf\n", ans * m);
  return 0;
}
