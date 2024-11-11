#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const double eps = 1e-10;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
const long long N = 2e5 + 5;
const long long MOD = 1e9 + 7;
long long pw(long long b, long long p) {
  b %= MOD;
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = res * b % MOD;
    b = b * b % MOD;
    p >>= 1;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  long long gr = 0, tot = 0;
  bool mark[n + 5];
  memset(mark, false, sizeof(mark));
  for (long long i = 0; i < n; i++) {
    if (s[i] == '.') {
      if (!i || s[i - 1] != '.') gr++;
      tot++;
      mark[i + 1] = true;
    }
  }
  long long idx;
  char c;
  for (long long i = 0; i < m; i++) {
    cin >> idx >> c;
    bool x = mark[idx], y = (c == '.');
    if (x != y) {
      if (x)
        tot--;
      else
        tot++;
      if (mark[idx - 1] && mark[idx + 1]) {
        if (y)
          gr--;
        else
          gr++;
      } else if (!mark[idx - 1] && !mark[idx + 1]) {
        if (y)
          gr++;
        else
          gr--;
      }
    }
    cout << tot - gr << '\n';
    mark[idx] = y;
  }
  return 0;
}
