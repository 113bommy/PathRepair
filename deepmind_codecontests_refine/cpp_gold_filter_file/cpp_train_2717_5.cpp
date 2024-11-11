#include <bits/stdc++.h>
const int INF = 0x7fffffff;
const long long INF_LL = (long long)1e18;
const int maxn = 1e5 + 10;
using namespace std;
int n;
long long ans = 0;
long long X;
long long MIN = INF_LL;
long long MAX = -INF_LL;
long long min(long long x, long long y) { return x > y ? y : x; }
long long max(long long x, long long y) { return x > y ? x : y; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &X);
    ans += X >= 0 ? X : -X;
    MIN = min(MIN, X);
    MAX = max(MAX, X);
  }
  if (MIN > 0) ans -= 2 * MIN;
  if (MAX < 0) ans += 2 * MAX;
  if (n == 1) ans = MIN;
  cout << ans << "\n";
  return 0;
}
