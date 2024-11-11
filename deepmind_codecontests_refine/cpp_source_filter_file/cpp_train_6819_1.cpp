#include <bits/stdc++.h>
using namespace std;
const int maxA = 100000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int trees[n];
  for (int i = 0; i < n; i++) cin >> trees[i];
  int dp[maxA + 1];
  memset(dp, 0, sizeof(dp));
  int offset[n];
  for (int i = 0; i < n / 2; i++) offset[i] = i;
  for (int i = n / 2; i < n; i++) offset[i] = n - i - 1;
  for (int i = 0; i < n; i++) {
    int firstElem = trees[i] - offset[i];
    if (firstElem >= 0) {
      dp[firstElem]++;
    }
  }
  int maxGoodTrees = 1;
  for (int i = 0; i < maxA + 1; i++) {
    maxGoodTrees = max(maxGoodTrees, dp[i]);
  }
  cout << (n - maxGoodTrees) << '\n';
  return 0;
}
