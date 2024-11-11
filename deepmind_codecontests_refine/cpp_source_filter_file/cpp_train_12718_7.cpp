#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
using ll = long long;
vector<int> edges[maxn];
ll dp[maxn];
int sub[maxn];
void dfs(int x, int p) {
  sub[x] = 1;
  dp[x] = 0;
  for (auto i : edges[x]) {
    if (i != p) {
      dfs(i, x);
      sub[x] += sub[i];
      dp[x] += dp[i];
    }
  }
  dp[x] += sub[x];
}
ll ans = 0;
int n;
void dfs1(int x, int p) {
  ans = max(ans, dp[x]);
  for (auto i : edges[x]) {
    if (i != p) {
      int fdp = dp[x], fi = dp[i], fsx = sub[x], fsi = sub[i];
      sub[x] = n - sub[i];
      sub[i] = n;
      dp[x] -= fi + fsi;
      dp[i] += dp[x] + sub[x];
      dfs1(i, x);
      dp[x] = fdp;
      dp[i] = fi;
      sub[x] = fsx;
      sub[i] = fsi;
    }
  }
}
int main(int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  dfs(1, 1);
  dfs1(1, 1);
  cout << ans << endl;
  return 0;
}
