#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const long long int MAX = -1000000000000000000;
const long long int MIN = 1000000000000000000;
const long long int inf = 1000000000;
const long long int KOK = 100000;
const long long int LOG = 30;
const long long int li = 500005;
const long long int mod = 1000000007;
long long int n, m, b[li], a[li], k, flag, t, l[li], r[li],
    dp[(1 << 15) + 15][4][235];
long long int cev;
string s;
vector<long long int> v;
inline long long int add(long long int x, long long int y) {
  if (x + y >= mod) return x + y - mod;
  return x + y;
}
inline long long int f(long long int mask, long long int son,
                       long long int sure) {
  long long int cevv = 0;
  if (sure > m) return 0;
  if (sure == m) return 1;
  if (mask == (1 << n) - 1) return 0;
  if (~dp[mask][son][sure]) return dp[mask][son][sure];
  for (long long int i = 0; i < n; i++) {
    if (son == r[i]) continue;
    if ((mask & (1 << i)) == 0)
      cevv = add(cevv, f((mask | (1 << i)), r[i], sure + l[i]));
  }
  return dp[mask][son][sure] = cevv;
}
int main(void) {
  memset(dp, -1, sizeof(dp));
  scanf("%lld %lld", &n, &m);
  for (long long int i = 0; i < n; i++) {
    scanf("%lld %lld", &l[i], &r[i]);
  }
  printf("%lld\n", f(0, 0, 0));
  return 0;
}
