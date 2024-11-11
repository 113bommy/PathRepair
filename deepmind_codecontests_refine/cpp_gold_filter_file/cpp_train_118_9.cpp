#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 7, inf = 1e18 + 7, mod = 998244353;
long long tc, n, m, x, a, b, c, d, h, i, j, k, l, id, sum, cnt, ans, tmp, flag,
    mn, mx;
long long ar[25], br[25];
string s[N];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s[i];
    br[s[i].size()]++;
  }
  for (i = 11; i > 0; i--) br[i] += br[i + 1];
  br[0] = n;
  for (i = 0; i < n; i++) {
    for (j = s[i].size() - 1, k = 1; j >= 0; j--, k++) {
      ar[2 * k - 1] += (s[i][j] - '0') * br[k];
      ar[2 * k] += (s[i][j] - '0') * br[k];
      for (l = 2 * k - 1, h = j; h >= 0; h--, l++)
        ar[l] += (s[i][h] - '0') * 2 * (br[k - 1] - br[k]);
    }
  }
  for (i = 1; ar[i]; i++) {
    ar[i + 1] += ar[i] / 10;
    ar[i] %= 10;
  }
  for (j = 1, k = 1; j < i; j++, k = (k * 10) % mod) {
    ans = (ans + (ar[j] * k) % mod) % mod;
  }
  cout << ans << endl;
}
