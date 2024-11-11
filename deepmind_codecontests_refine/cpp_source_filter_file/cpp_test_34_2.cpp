#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n;
int a[10010];
vector<int> vec[5010];
int dp[2][10010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    vec[a[i]].push_back(i);
  }
  int per = 0, now = 1;
  for (int i = 1; i < 9000; ++i) dp[per][i] = 0x3f3f3f3f;
  dp[per][0] = 0;
  for (int i = 1; i <= 5000; ++i) {
    for (int j = 0; j < 9000; ++j) {
      dp[now][j] = dp[per][j];
    }
    for (int j = 0; j < 9000; ++j) {
      if (dp[per][j] == 0x3f3f3f3f) continue;
      auto it = upper_bound(vec[i].begin(), vec[i].end(), dp[per][j]);
      if (it != vec[i].end()) {
        dp[now][j ^ i] = min(dp[now][j ^ i], *it);
      }
    }
    now++;
    per++;
    now %= 2;
    per %= 2;
  }
  int cnt = 0;
  for (int j = 0; j < 9000; ++j) {
    if (dp[per][j] != 0x3f3f3f3f) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
  for (int j = 0; j < 9000; ++j) {
    if (dp[per][j] != 0x3f3f3f3f) {
      printf("%d ", j);
    }
  }
  return 0;
}
