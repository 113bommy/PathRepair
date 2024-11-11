#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10, MOD = 1e9 + 7, nax = 1000005;
long long n, m, ncr[1001][1001], po[1001], s[1001], ans = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == 0 || i == j)
        ncr[i][j] = 1;
      else
        ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
    }
  }
  po[0] = 1, po[1] = 1;
  for (int i = 2; i <= n; i++) po[i] = (po[i - 1] * 2) % MOD;
  for (int i = 0; i < m; i++) cin >> s[i];
  sort(s, s + m);
  long long cnt = 0, tmp;
  for (int i = 0; i < m; i++) {
    if (i == 0)
      tmp = s[i] - 1;
    else {
      tmp = s[i] - s[i - 1] - 1;
      ans = (ans * po[tmp]) % MOD;
    }
    cnt += tmp;
    ans = (ans * ncr[cnt][tmp]) % MOD;
  }
  cnt += n - s[m - 1];
  ans = ans * ncr[cnt][n - s[m - 1]] % MOD;
  cout << ans << "\n";
  return 0;
}
