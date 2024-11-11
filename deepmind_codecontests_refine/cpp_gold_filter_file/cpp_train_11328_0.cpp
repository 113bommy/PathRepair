#include<iostream>
  
int const MAXN = 3000;
int const MOD = 1000000007;

char s[MAXN];

int N;
int dp[2][MAXN];

int main() {
  std::cin >> N;
  std::cin >> s;

  for(int i = 0; i < N; ++i) dp[0][i] = 1;

  for(int j = 0; j < N-1; ++j) {
    if(s[j] == '>') {
      dp[(j+1)%2][N-j-2] = dp[j%2][N-j-1];
      for(int i = N-j-3; i >= 0; --i) {
        dp[(j+1)%2][i] = (dp[(j+1)%2][i+1] + dp[j%2][i+1])%MOD;
      }
    } else {
      dp[(j+1)%2][0] = dp[j%2][0];
      for(int i = 1; i < N-j-1; ++i) {
        dp[(j+1)%2][i] = (dp[(j+1)%2][i-1] + dp[j%2][i])%MOD;
      }
    }
  }
  std::cout << dp[(N-1)%2][0] << std::endl;
  return 0;
}