#include <bits/stdc++.h>
using namespace std;
int n, a, b;
char c[5010];
int dp[5010];
set<int> s;
vector<pair<int, int> > v[3];
int main() {
  memset(dp, 0x3f, sizeof(dp));
  scanf("%d %d %d", &n, &a, &b);
  scanf("%s", c + 1);
  bool flag = 1;
  dp[1] = a;
  for (int i = 2; i <= n; i++) {
    v[flag ^ 1].clear();
    s.clear();
    int size = v[flag].size();
    int now = i;
    for (int j = 0; j < size; j++) {
      pair<int, int> x = v[flag][j];
      if (c[x.second + 1] == c[i] && x.second + 1 < i - x.first) {
        v[flag ^ 1].push_back(pair<int, int>(x.first + 1, x.second + 1));
        dp[i] = min(dp[i - x.first - 1] + b, dp[i]);
        s.insert(x.second + 1);
      }
    }
    for (int j = 1; j < i; j++) {
      if (c[j] == c[i] && !s.count(j)) {
        v[flag ^ 1].push_back(pair<int, int>(1, j));
        dp[i] = min(dp[i - 1] + b, dp[i]);
      }
    }
    dp[i] = min(dp[i], dp[i - 1] + a);
    flag ^= 1;
  }
  cout << dp[n] << endl;
  return 0;
}
