#include <bits/stdc++.h>
using namespace std;
struct str {
  int x, y;
};
const int NMAX = 100003;
int viz[NMAX], dp[NMAX];
vector<pair<int, int> > v[NMAX];
vector<int> mSet;
int m, n;
void dfs(int x, int cost) {
  viz[x] = 1;
  for (auto nod : v[x]) {
    if (!viz[nod.first]) {
      dp[nod.first] = cost ^ nod.second;
      dfs(nod.first, dp[nod.first]);
    } else {
      int xo = dp[nod.first] ^ cost ^ nod.second;
      for (auto sxor : mSet) {
        xo = min(xo, xo ^ sxor);
      }
      if (xo) {
        mSet.push_back(xo);
      }
    }
  }
}
int main() {
  int x, y, w;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> w;
    v[x].push_back(make_pair(y, w));
    v[y].push_back(make_pair(x, w));
  }
  dfs(1, 0);
  for (auto p : mSet) {
    dp[n] = min(dp[n], p ^ dp[n]);
  }
  cout << dp[n];
}
