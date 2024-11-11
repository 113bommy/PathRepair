#include <bits/stdc++.h>
using namespace std;
int n = 0;
bool valid(int i, int j) {
  return ((i >= 0) && (i < n) && (j >= 0) && (j < n));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  long long a[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  long long dp[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) dp[i][j] = 0;
  for (int j = 0; j < n; j++) {
    int x = 0;
    int y = j;
    long long sum = 0;
    while (valid(x, y)) {
      sum += a[x][y];
      x++;
      y++;
    }
    x = 0;
    y = j;
    while (valid(x, y)) {
      dp[x][y] += sum;
      x++;
      y++;
    }
  }
  for (int i = 1; i < n; i++) {
    int x = i;
    int y = 0;
    long long sum = 0;
    while (valid(x, y)) {
      sum += a[x][y];
      x++;
      y++;
    }
    x = i;
    y = 0;
    while (valid(x, y)) {
      dp[x][y] += sum;
      x++;
      y++;
    }
  }
  long long evensum = 0;
  long long oddsum = 0;
  pair<int, int> even;
  pair<int, int> odd;
  for (int j = 0; j < n; j++) {
    int x = 0;
    int y = j;
    long long sum = 0;
    while (valid(x, y)) {
      sum += a[x][y];
      x++;
      y--;
    }
    x = 0;
    y = j;
    while (valid(x, y)) {
      dp[x][y] += sum - a[x][y];
      x++;
      y--;
    }
  }
  for (int i = 1; i < n; i++) {
    int x = i;
    int y = n - 1;
    long long sum = 0;
    while (valid(x, y)) {
      sum += a[x][y];
      x++;
      y--;
    }
    x = i;
    y = 0;
    while (valid(x, y)) {
      dp[x][y] += sum - a[x][y];
      x++;
      y--;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if ((i + j) % 2 == 0) {
        if (dp[i][j] >= evensum) {
          evensum = dp[i][j];
          even.first = i + 1;
          even.second = j + 1;
        }
      } else {
        if (dp[i][j] >= oddsum) {
          oddsum = dp[i][j];
          odd.first = i + 1;
          odd.second = j + 1;
        }
      }
  cout << oddsum + evensum;
  cout << '\n';
  cout << even.first << " " << even.second << " " << odd.first << " "
       << odd.second;
}
