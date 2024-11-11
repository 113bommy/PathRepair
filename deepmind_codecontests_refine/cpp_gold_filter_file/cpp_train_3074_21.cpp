#include <bits/stdc++.h>
using namespace std;
const int maxTT = 55;
int sum[maxTT], x_or[maxTT];
long long dp[maxTT][10][2][2];
long long solve(int pos, int carry, int oka, int okb) {
  if (pos == maxTT) {
    return carry == 0 && oka == 1 && okb == 1;
  }
  if (dp[pos][carry][oka][okb] != -1) {
    return dp[pos][carry][oka][okb];
  }
  long long answer = 0;
  if (carry % 2 == sum[pos] && x_or[pos] == 0) {
    answer += solve(pos + 1, carry / 2, oka, okb);
  }
  if ((1 + carry) % 2 == sum[pos] && x_or[pos] == 1) {
    answer += solve(pos + 1, (1 + carry) / 2, oka, 1);
  }
  if ((1 + carry) % 2 == sum[pos] && x_or[pos] == 1) {
    answer += solve(pos + 1, (1 + carry) / 2, 1, okb);
  }
  if ((2 + carry) % 2 == sum[pos] && x_or[pos] == 0) {
    answer += solve(pos + 1, (2 + carry) / 2, 1, 1);
  }
  return dp[pos][carry][oka][okb] = answer;
}
int main() {
  long long a, b;
  cin >> a >> b;
  for (int i = 0; i < maxTT; ++i) {
    sum[i] = a % 2;
    x_or[i] = b % 2;
    a /= 2;
    b /= 2;
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0, 0) << endl;
  return 0;
}
