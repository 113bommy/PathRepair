#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7, N = 1005;
int n, k, C[N][N], dp[N][N], f[N];
long long res;
string s;
int main() {
  ios::sync_with_stdio(0);
  f[1] = 0;
  C[0][0] = 1;
  for (int i = 2; i < N; i++) f[i] = f[__builtin_popcount(i)] + 1;
  for (int i = 1; i < N; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
  }
  cin >> s >> k;
  if (!k) return puts("1"), 0;
  n = s.size();
  reverse(s.begin(), s.end());
  for (int i = 0; i < n; i++) s[i] -= '0';
  dp[0][0] = 1;
  dp[0][1] = (s[0] ? 1 : 0);
  for (int i = 1; i < n; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= i + 1; j++)
      if (s[i])
        dp[i][j] = (dp[i - 1][j - 1] + C[i][j]) % M;
      else
        dp[i][j] = dp[i - 1][j] % M;
  }
  for (int i = 0; i <= n; i++)
    if (f[i] == k - 1) res = (res + dp[n - 1][i]) % M;
  if (k == 1) res--;
  cout << (res % M + M) % M << "\n";
  return 0;
}
