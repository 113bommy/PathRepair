#include <bits/stdc++.h>
using namespace std;
const long long nax = 3e5 + 5;
vector<long long> adj[nax];
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 7;
long long n, m;
long long a[nax];
signed main() {
  cin >> n >> m;
  string s;
  cin >> s;
  m--;
  if (m >= (n / 2)) {
    m = (n - 1) - m;
    reverse(s.begin(), s.end());
  }
  long long R = m, L = m, ans = 0;
  for (long long i = m; i < (n / 2); i++) {
    if (s[i] != s[(n - 1) - i]) {
      R = i;
      long long res = max(s[i], s[(n - 1) - i]) - min(s[i], s[(n - 1) - i]);
      if (res <= 13)
        ans += res;
      else
        ans += (25 - res) + 1;
    }
  }
  for (long long i = m - 1; i >= 0; i--) {
    if (s[i] != s[(n - 1) - i]) {
      L = i;
      long long res = max(s[i], s[(n - 1) - i]) - min(s[i], s[(n - 1) - i]);
      if (res <= 13)
        ans += res;
      else
        ans += (25 - res) + 1;
    }
  }
  long long res = min(R - m, m - L);
  cout << ans + res + (R - L) << "\n";
  return 0;
}
