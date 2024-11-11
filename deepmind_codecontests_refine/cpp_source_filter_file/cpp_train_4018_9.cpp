#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
const int inf = 0x3f3f3f3f;
int dp[25000][2];
int main() {
  memset(dp, 0x3f, sizeof dp);
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> vec[2];
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    if (x == n) {
      printf("1\n");
      exit(0);
    }
    vec[x > n].push_back(abs(x - n));
  }
  for (int i = 0; i < 2; i++) {
    if (vec[i].empty()) {
      printf("-1\n");
      exit(0);
    }
    sort(begin(vec[i]), end(vec[i]));
    vec[i].resize(unique(begin(vec[i]), end(vec[i])) - begin(vec[i]));
  }
  int ans = inf;
  dp[0][0] = dp[0][1] = 0;
  for (int S = 1; S < 25000; S++) {
    for (int i = 0; i < 2; i++) {
      for (int x : vec[i]) {
        if (x > S) break;
        dp[S][i] = min(dp[S][i], 1 + dp[S - x][i]);
      }
    }
    ans = min(ans, dp[S][0] + dp[S][1]);
  }
  printf("%d\n", ans);
  return 0;
}
