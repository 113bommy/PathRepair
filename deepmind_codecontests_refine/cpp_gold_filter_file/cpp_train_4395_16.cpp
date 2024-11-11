#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e3 + 10;
const long long INF = 8e18;
const long long MOD = 998244353;
int n, S[MAXN][MAXN], E[MAXN][MAXN];
string s;
void mkey(int& a) {
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  n = s.size();
  s = '.' + s;
  S[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (s[i] == '(' && j > 0)
        mkey(S[i][j] = S[i - 1][j - 1]);
      else if (s[i] == ')')
        S[i][j] = S[i - 1][j];
      else if (s[i] == '?') {
        S[i][j] = S[i - 1][j];
        if (j) mkey(S[i][j] += S[i - 1][j - 1]);
      }
    }
  }
  for (int i = n; i > 0; i--)
    for (int j = 0; j <= n; j++)
      if (s[i] == '?' || s[i] == ')') mkey(S[i][j] -= S[i - 1][j]);
  E[n + 1][0] = 1;
  for (int i = n; i > 0; i--) {
    for (int j = 0; j <= n; j++) {
      if (s[i] == ')' && j > 0)
        E[i][j] = E[i + 1][j - 1];
      else if (s[i] == '(')
        E[i][j] = E[i + 1][j];
      else if (s[i] == '?') {
        E[i][j] = E[i + 1][j];
        if (j) mkey(E[i][j] += E[i + 1][j - 1]);
      }
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = n; j > 0; j--) {
      mkey(E[i][j] += E[i][j + 1]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int d = 1; d <= n; d++) mkey(ans += 1ll * S[i][d] * E[i + 1][d] % MOD);
  cout << ans << '\n';
  return 0;
}
