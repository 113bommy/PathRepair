#include <bits/stdc++.h>
using namespace std;
const int N = 62;
int ar[N];
int dp[N][N][N * 30];
pair<int, int> trace[N][N][N * 30], ans_lis[N];
int ans[N][N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, i, j, k, l, num = N, sum, num1, now, now1;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  sort(ar + 1, ar + 1 + n);
  dp[0][0][0] = 1;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= 61; j++) {
      for (k = j * (j - 1) / 2; k <= 30 * j; k++) {
        if (dp[i - 1][j][k]) {
          dp[i][j + 1][k + ar[i]] = 1;
          trace[i][j + 1][k + ar[i]] = {i - 1, ar[i]};
        }
        if (dp[i][j][k]) {
          dp[i][j + 1][k + ar[i]] = 1;
          trace[i][j + 1][k + ar[i]] = {i, ar[i]};
        }
      }
    }
  }
  for (j = n; j <= 61; j++) {
    if (dp[n][j][j * (j - 1) / 2]) {
      num = j;
      sum = j * (j - 1) / 2;
      break;
    }
  }
  if (num == N) {
    cout << "=(";
    return 0;
  }
  num1 = num;
  now = n;
  while (num) {
    ans_lis[num].first = trace[now][num][sum].second;
    ans_lis[num].second = num;
    now1 = now;
    now = trace[now][num][sum].first;
    sum -= trace[now1][num][sum].second;
    num--;
  }
  num = num1;
  for (i = num; i >= 1; i--) {
    sort(ans_lis + 1, ans_lis + 1 + i);
    for (j = ans_lis[i].first + 1; j < i; j++) {
      ans_lis[j].first--;
      ans[ans_lis[j].second][ans_lis[i].second] = 1;
    }
    for (j = 1; j <= ans_lis[i].first; j++) {
      ans[ans_lis[i].second][ans_lis[j].second] = 1;
    }
  }
  cout << num << '\n';
  for (i = 1; i <= num; i++) {
    for (j = 1; j <= num; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}
