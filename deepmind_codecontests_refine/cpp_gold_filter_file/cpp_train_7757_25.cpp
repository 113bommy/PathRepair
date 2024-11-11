#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int N, M;
long long dp[2010][2010];
int bad_sum;
int must_inz;
void build() {
  dp[0][0] = 1;
  for (int i = 1; i <= 2005; i++) {
    dp[i][0] = dp[i - 1][1];
    for (int j = 1; j <= i; j++)
      dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % MOD;
  }
}
int main() {
  build();
  ios::sync_with_stdio(0);
  string s;
  cin >> N >> M >> s;
  int per_iniziare = 0;
  for (char c : s)
    bad_sum += (c == '(' ? 1 : -1), must_inz -= (c == '(' ? 1 : -1),
        per_iniziare = max(per_iniziare, must_inz);
  N = N - M;
  long long res = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = per_iniziare; j <= i; j++) {
      long long pre = dp[i][j];
      int rem = abs(j + bad_sum);
      if (N - i < rem) continue;
      long long post = dp[N - i][rem];
      res = (res + (pre * post) % MOD) % MOD;
    }
  }
  cout << res;
  return 0;
}
