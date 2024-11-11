#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp[10][10][10];
long long int arr[10][10];
int best;
void solve(int x, int y, int need) {
  queue<pair<int, int> > q;
  q.push(make_pair(x, 0));
  q.push(make_pair(y, 0));
  best = 1e9;
  int iterate = 0;
  while (!q.empty()) {
    int curr = q.front().first;
    int take = q.front().second;
    q.pop();
    if (curr == need) {
      best = min(best, take);
    } else {
      int num;
      num = curr + x;
      if (x > 0) q.push(make_pair(num % 10, take + 1));
      num = curr + y;
      if (y > 0) q.push(make_pair(num % 10, take + 1));
    }
    iterate++;
    if (iterate >= 2000) {
      while (!q.empty()) q.pop();
      break;
    }
  }
  if (best == 1e9) best = -1;
}
int main() {
  int n, i, j, k, x, y, ans, curr, temp, m;
  int tc;
  cin >> a;
  int len = a.length();
  int last = 0;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      for (int ii = 0; ii < 10; ii++) {
        solve(i, j, ii);
        dp[i][j][ii] = best;
      }
    }
  }
  for (i = 0; i < len - 1; i++) {
    x = a[i] - '0';
    y = a[i + 1] - '0';
    if (y < x) y += 10;
    curr = y - x;
    for (j = 0; j < 10; j++) {
      for (int jj = 0; jj < 10; jj++) {
        if (dp[j][jj][curr] == -1)
          arr[j][jj] = -1e18;
        else
          arr[j][jj] += dp[j][jj][curr];
      }
    }
  }
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      arr[i][j] = max(-1LL, arr[i][j]);
      printf("%lld ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
