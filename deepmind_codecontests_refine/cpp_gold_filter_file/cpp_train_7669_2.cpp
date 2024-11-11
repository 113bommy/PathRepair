#include <bits/stdc++.h>
using namespace std;
int N;
pair<long long, long long> tasks[60];
long long lo = 0, hi = 5000000000000000, dp[60][60];
long long solveIt(long long x) {
  for (int i = 0; i < 60; i++)
    for (int j = 0; j < 60; j++) dp[i][j] = -5000000000000000;
  dp[0][0] = 0;
  for (int i = 0; i < N;) {
    int nexty = i;
    while (nexty < N && tasks[i].first == tasks[nexty].first) nexty++;
    for (int j = 0; j <= N; j++) {
      int len = nexty - i;
      long long sum = 0;
      for (int k = 0; k <= len; k++) {
        if (j >= len - k)
          dp[nexty][j - (len - k) + k] =
              max(dp[nexty][j - (len - k) + k], dp[i][j] + sum);
        sum += x * tasks[i + k].second - tasks[i + k].first;
      }
    }
    i = nexty;
  }
  long long maxi = -5000000000000000;
  for (int i = 0; i <= N; i++) maxi = max(maxi, dp[N][i]);
  return maxi >= 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(18);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> tasks[i].first;
    tasks[i].first *= 1000;
  }
  for (int i = 0; i < N; i++) cin >> tasks[i].second;
  sort(tasks, tasks + N);
  reverse(tasks, tasks + N);
  while (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    if (solveIt(mid))
      hi = mid;
    else
      lo = mid;
  }
  cout << hi << '\n';
  return 0;
}
