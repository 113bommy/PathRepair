#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int dp[401][55][55];
int C[205][205];
inline int mul(int a, int b) { return 1ll * a * b % MOD; }
inline int add(int a, int b) {
  int p = a + b;
  if (p >= MOD) return p - MOD;
  return p;
}
inline int sub(int a, int b) {
  int p = a - b;
  if (p < 0) return p + MOD;
  return p;
}
inline void sadd(int &a, int b) { a = add(a, b); }
int a[3];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < 205; i++)
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
  int n, k;
  cin >> n >> k;
  k /= 50;
  for (int i = 1; i <= n; i++) {
    int f;
    cin >> f;
    a[f / 50]++;
  }
  dp[0][a[1]][a[2]] = 1;
  for (int ride = 0; ride <= 400; ride++) {
    if ((ride & 1) && dp[ride][a[1]][a[2]])
      return cout << ride << '\n' << dp[ride][a[1]][a[2]], 0;
    for (int i = 0; i <= a[1]; i++)
      for (int j = 0; j <= a[2]; j++)
        for (int go1 = 0; go1 <= i && go1 <= k; go1++)
          for (int go2 = 0; go2 <= j && (go2 << 1) + go1 <= k; go2++) {
            if (!go1 && !go2) continue;
            sadd(dp[ride + 1][a[1] - (i - go1)][a[2] - (j - go2)],
                 mul(dp[ride][i][j], mul(C[i][go1], C[j][go2])));
          }
  }
  cout << "-1\n0";
}
