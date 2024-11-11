#include <bits/stdc++.h>
using namespace std;
int a[3010], arr[3010];
long long dp[3010][3010];
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    scanf("%d", a + i);
    a[i] -= i;
    arr[i] = a[i];
  }
  sort(arr, arr + N);
  int M = unique(arr, arr + N) - arr;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dp[i][j] = abs(a[i] - arr[j]);
      if (i) dp[i][j] += dp[i - 1][j];
      if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    }
  }
  cout << dp[N - 1][M - 1] << endl;
  return 0;
}
