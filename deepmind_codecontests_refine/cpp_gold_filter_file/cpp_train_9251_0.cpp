#include <bits/stdc++.h>
using namespace std;

using lint = long long;

lint n, s;
lint dp[1001][101][11];

lint dfs(int sum = 0, int num = 0, int cnt = 0) {
  if (cnt == n) return sum == s;
  if (num > 100 || sum > s) return 0;

  lint &ret = dp[sum][num][cnt];
  if (~ret) return ret;

  ret = dfs(sum, num + 1, cnt) + dfs(sum + num, num + 1, cnt + 1);

  return ret;
}

int main() {
  while (cin >> n >> s, n + s) {
    memset(dp, -1, sizeof(dp));
    cout << dfs() << endl;
  }
}