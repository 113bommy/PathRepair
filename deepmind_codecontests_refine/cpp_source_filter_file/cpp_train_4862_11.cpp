#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long maxm(long long a, long long b) {
  long long c = a > b ? a : b;
  return c;
}
long long minm(long long a, long long b) {
  long long c = a > b ? b : a;
  return c;
}
void solve(void) {
  long long n;
  cin >> n;
  long long i, j;
  vector<long long> fb(4e5 + 1, 0), bf(4e5 + 1, 0);
  for (i = 0; i < n; i++) {
    string s;
    cin >> s;
    long long nn = s.size();
    long long cl = 0, cr = 0;
    for (j = 0; j < nn; j++) {
      if (s[j] == '(')
        cl++;
      else
        cr++;
      if (cr > cl) break;
    }
    if (j == nn) fb[cl - cr]++;
    cl = 0, cr = 0;
    for (j = nn - 1; j >= 0; j--) {
      if (s[j] == ')')
        cr++;
      else
        cl++;
      if (cl > cr) break;
    }
    if (j == -1) bf[cr - cl]++;
  }
  long long ans = 0;
  for (i = 0; i <= n; i++) ans += fb[i] * bf[i];
  cout << ans << "\n";
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long long t = 1;
  while (t--) solve();
  return 0;
}
