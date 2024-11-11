#include <bits/stdc++.h>
using namespace std;
int dp[6003][503];
int N, K;
int fav[100001], favcnt[100001];
int joy[100001];
int card[100001];
int cnt[100001];
int main() {
  cin >> N >> K;
  for (int i = 0; i < N * K; i++) {
    cin >> card[i];
    cnt[card[i]]++;
  }
  for (int i = 0; i < N; i++) {
    cin >> fav[i];
    favcnt[fav[i]]++;
  }
  for (int i = 1; i <= K; i++) cin >> joy[i];
  for (int k = 0; k <= N; k++)
    for (int j = 0; j <= N * K; j++)
      for (int i = 1; i <= K; i++)
        dp[i + j][k + 1] = max(dp[i + j][k + 1], dp[j][k] + joy[i]);
  long long ans = 0;
  for (int i = 1; i <= 100000; i++) ans += dp[cnt[i]][favcnt[i]];
  cout << ans << endl;
  return 0;
}
