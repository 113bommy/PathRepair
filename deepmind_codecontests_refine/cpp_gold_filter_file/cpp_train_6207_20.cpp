#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 9;
const long long mod = 1e9 + 7;
const long long maxn = 2e3 + 8;
char s[6][maxn];
long long n, m;
void solve() {
  long long i, j;
  cin >> n;
  if (n & 1) {
    s[1][1] = s[2][1] = 'a';
    for (i = 2; i < n; i += 2)
      if (i & 2)
        s[1][i] = s[1][i + 1] = 'b', s[2][i] = s[2][i + 1] = 'c';
      else
        s[1][i] = s[1][i + 1] = 'c', s[2][i] = s[2][i + 1] = 'b';
    s[3][n] = s[4][n] = 'd';
    for (i = 1; i < n; i += 2)
      if (i & 2)
        s[3][i] = s[3][i + 1] = 'e', s[4][i] = s[4][i + 1] = 'f';
      else
        s[3][i] = s[3][i + 1] = 'f', s[4][i] = s[4][i + 1] = 'e';
  } else {
    for (i = 1; i <= n; i += 2)
      if (i & 2)
        s[1][i] = s[1][i + 1] = s[4][i] = s[4][i + 1] = 'a';
      else
        s[1][i] = s[1][i + 1] = s[4][i] = s[4][i + 1] = 'b';
    s[2][1] = s[3][1] = 'f';
    s[2][n] = s[3][n] = 'c';
    for (i = 2; i < n; i += 2)
      if (i & 2)
        s[2][i] = s[2][i + 1] = 'd', s[3][i] = s[3][i + 1] = 'e';
      else
        s[2][i] = s[2][i + 1] = 'e', s[3][i] = s[3][i + 1] = 'd';
  }
  for (i = 1; i <= 4; i++) cout << s[i] + 1 << endl;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
