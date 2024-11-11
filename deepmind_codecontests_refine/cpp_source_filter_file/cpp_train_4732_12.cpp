#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int small[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int geti(int p) {
  return lower_bound(small, small + sizeof small / sizeof(int), p) - small;
}
vector<int> primes(int n) {
  vector<int> ans;
  for (int p = 2; p * p <= n; p++) {
    if (n % p != 0) continue;
    ans.push_back(geti(p));
    do n /= p;
    while (n % p == 0);
  }
  if (n > 1) ans.push_back(geti(n));
  return move(ans);
}
pair<int, pair<int, int> > dp[101][1 << 16];
int main() {
  for (int i = 0; i < (101); i++)
    for (int j = 0; j < (1 << 16); j++)
      dp[i][j] = make_pair(INF, make_pair(-1, -1));
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  dp[0][0] = make_pair(0, make_pair(-1, -1));
  vector<vector<int> > ps(59);
  for (int i = (1); i <= (58); i++) {
    ps[i] = move(primes(i));
  }
  for (int i = 0; i < (n); i++) {
    int a;
    scanf("%d", &a);
    for (int k = 0; k < (1 << 10); k++) {
      for (int j = (1); j <= (58); j++) {
        bool fail = false;
        int kk = k;
        for (auto &g : ps[j]) {
          if (k & (1 << g)) {
            fail = true;
            break;
          }
          kk |= (1 << g);
        }
        if (fail) continue;
        dp[i + 1][kk] =
            min(dp[i + 1][kk],
                make_pair(dp[i][k].first + abs(j - a), make_pair(j, k)));
      }
    }
  }
  stack<int> ans;
  int mink = 0;
  for (int k = 0; k < (1 << 16); k++) {
    if (dp[n][k] < dp[n][mink]) mink = k;
  }
  for (int i = (n); i >= (1); i--) {
    ans.push(dp[i][mink].second.first);
    mink = dp[i][mink].second.second;
  }
  while (!ans.empty()) {
    printf("%d ", ans.top());
    ans.pop();
  }
  puts("");
  return 0;
}
