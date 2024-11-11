#include <bits/stdc++.h>
using namespace std;
const int sz = 2e5 + 10;
const int mod = 1e9 + 7;
long long int dp[sz][3];
long long int n;
long long int ara[3];
int nai(int k) { return k / 3; }
long long int fun(long long int pos, long long int x) {
  if (pos == n) return x == 0;
  long long int res = 0, p;
  if (dp[pos][x] != -1) return dp[pos][x];
  for (int i = 0; i < 3; i++) {
    p = (ara[i] * fun(pos + 1, (x + i) % 3)) % mod;
    res = (res + p) % mod;
  }
  return dp[pos][x] = res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int a, b, c, ans, ct1, d, ct, t, cs = 1, p, q, x, y, i, j, k, mn, z,
                                             mx, len, m, ct2, r, l;
  string str, str1, str2;
  bool bl, bl1;
  char ch;
  while (cin >> n >> l >> r) {
    memset(dp, -1, sizeof dp);
    ara[0] = nai(r) - nai(l - 1) % 3;
    ara[1] = nai(r + 2) - nai(l + 1);
    ara[2] = nai(r + 1) - nai(l);
    ans = fun(0, 0);
    cout << ans << endl;
  }
}
