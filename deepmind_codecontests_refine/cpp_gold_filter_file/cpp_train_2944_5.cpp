#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
int arr[200009];
int dp[200009][4];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> arr[i];
      dp[i][1] = dp[i][0] = INF;
    }
    dp[1][1] = arr[1];
    dp[2][1] = arr[1] + arr[2];
    dp[2][0] = dp[1][1];
    for (int i = 3; i <= N; i++) {
      dp[i][1] = min(dp[i - 1][0] + arr[i], dp[i - 2][0] + arr[i] + arr[i - 1]);
      dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);
    }
    cout << min(dp[N][0], dp[N][1]) << "\n";
  }
  return 0;
}
