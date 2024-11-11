#include <bits/stdc++.h>
using namespace std;
long long const N = 1001, INF = 1e9;
long long dp[N][N], a[N][N], used[N];
vector<int> requests, otv;
int main() {
  long long n, ves, sum = 0;
  cin >> n;
  requests.resize(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = INF;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      dp[i][j] = a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> requests[i];
    requests[i]--;
  }
  for (int z = n - 1; z >= 0; z--) {
    used[requests[z]] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = min(dp[i][j], dp[i][requests[z]] + dp[requests[z]][j]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (used[i] && used[j]) {
          sum += dp[i][j];
        }
      }
    }
    otv.push_back(sum);
    used[requests[z]] = 1;
    sum = 0;
  }
  reverse(otv.begin(), otv.end());
  for (int i = 0; i < otv.size(); i++) {
    cout << otv[i] << " ";
  }
  return 0;
}
