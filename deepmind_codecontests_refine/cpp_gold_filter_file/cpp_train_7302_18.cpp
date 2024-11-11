#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long llinf = (1LL << 62);
const int inf = (1 << 30);
const int nmax = 3e5 + 50;
const long long mod = 1e9 + 7;
using namespace std;
long long n, a[nmax], m[nmax], i, j, rs, tot, cur;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i] >> m[i], tot += a[i];
  for (i = 0; i < 62; i++) {
    cur = 0;
    for (j = 1; j <= n; j++) {
      if (!((m[j] & (1LL << i)) && m[j] - (1LL << i) < (1LL << i))) continue;
      if (__builtin_popcountll(m[j] & rs) & 1)
        cur -= a[j];
      else
        cur += a[j];
    }
    if ((cur > 0 && tot > 0) || (cur < 0 && tot < 0)) rs |= (1LL << i);
  }
  cout << rs << endl;
  return 0;
}
