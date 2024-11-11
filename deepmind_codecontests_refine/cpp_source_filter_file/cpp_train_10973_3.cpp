#include <bits/stdc++.h>
using namespace std;
signed long long int dp[2005][2005];
signed long long int sdp[2005][2005];
int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  S = " " + S;
  dp[0][0] = 1;
  sdp[0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int k = 1; k <= K; ++k) {
      dp[i][k] = sdp[i - 1][k] * (S[i] - 'a');
      dp[i][k] %= 1000000007;
      for (int j = i; j >= 1 and (i - j + 1) * (N - i + 1) <= k; --j) {
        dp[i][k] += dp[j - 1][k - (i - j + 1) * (N - i + 1)] * ('z' - S[i]);
        dp[i][k] %= 1000000007;
      }
      sdp[i][k] = (sdp[i - 1][k] + dp[i][k]) % 1000000007;
    }
  }
  cout << sdp[N][K];
}
