#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> dp[50];
int input[50];
long long b;
long long a;
bool isA = false;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> input[i];
  if (n == 1) cout << "0 " << input[0] << endl;
  if (n == 2)
    cout << min(input[0], input[1]) << " " << max(input[0], input[1]) << endl;
  else {
    dp[n - 2] = make_pair(max(input[n - 2], input[n - 1]),
                          min(input[n - 2], input[n - 1]));
    for (int i = n - 3; i >= 0; i--)
      dp[i] = make_pair(max(dp[i + 1].first, dp[i + 1].second + input[i]),
                        min(dp[i + 1].first, dp[i + 1].second + input[i]));
    cout << dp[0].second << " " << dp[0].first << endl;
  }
}
