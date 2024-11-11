#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int PRIME = 999983;
const int MOD = 1000000007;
const int MULTI = 1000000007;
const long double EPS = 1e-10;
inline bool isodd(int x) { return x & 1; }
inline bool isodd(long long x) { return x & 1; }
int main(void) {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  long double p = 1.0 * a / b, q = 1.0 * c / d, ans = 0, inc = 1;
  for (int i = 1; i <= 3000; i++) {
    ans += inc * p;
    inc *= (1 - p) * (1 - q);
    if (inc < EPS) break;
  }
  cout.precision(9);
  cout << ans << endl;
  return 0;
}
