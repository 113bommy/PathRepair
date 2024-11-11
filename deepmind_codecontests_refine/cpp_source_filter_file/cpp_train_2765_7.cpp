#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int dp[200001];
  for (int i = 1; i < N + 1; i++) {
    cin >> dp[i];
    dp[i] = dp[i] + dp[i - 1];
  }
  int optChoice = dp[N];
  for (int i = N - 1; i > 0; i--) {
    optChoice = max(optChoice, dp[i] - optChoice);
  }
  cout << optChoice << endl;
  return 0;
}
