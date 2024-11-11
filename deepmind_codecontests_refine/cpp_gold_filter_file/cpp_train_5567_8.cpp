#include <bits/stdc++.h>
using namespace std;
int arr[30005];
int lol = INT_MIN;
int dp[30005][1005];
int n;
int memo[30005][1005];
int compute(int i, int j) {
  int ans;
  if (i >= 30005) return 0;
  if (memo[i][j] == 1) return dp[i][j];
  memo[i][j] = 1;
  if (j == 1) {
    ans = arr[i] + max(compute(i + j, j), compute(i + j + 1, j + 1));
  } else {
    ans = arr[i] + max(max(compute(i + j - 1, j - 1), compute(i + j, j)),
                       compute(i + j + 1, j + 1));
  }
  dp[i][j] = ans;
  return ans;
}
int main() {
  int d;
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; i++) {
    int value;
    scanf("%d", &value);
    int lol = max(lol, value);
    arr[value]++;
  }
  int sol = compute(d, d);
  printf("%d", sol);
  return 0;
}
