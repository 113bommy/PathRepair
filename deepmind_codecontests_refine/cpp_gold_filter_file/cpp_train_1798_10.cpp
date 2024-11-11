#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 200100;
int h[maxn], t[maxn];
vector<int> v[maxn];
long long dp[maxn][2];
void dfs(int x, int fa) {
  int in = 0, out = 0;
  long long cur = 0;
  vector<int> d;
  for (int y : v[x]) {
    if (y != fa) {
      dfs(y, x);
      if (h[y] != h[x])
        cur += dp[y][h[y] < h[x]], h[y] < h[x] ? in++ : out++;
      else {
        cur += dp[y][0];
        out++;
        d.push_back(dp[y][1] - dp[y][0]);
      }
    }
  }
  sort(d.begin(), d.end());
  dp[x][0] = min(dp[x][0], cur + 1ll * max(in + (x != 1), out) * t[x]),
  dp[x][1] = min(dp[x][1], cur + 1ll * max(in, out + (x != 1)) * t[x]);
  for (int i = 0; i < d.size(); i++) {
    out--, in++;
    cur += d[i];
    dp[x][0] = min(dp[x][0], cur + 1ll * max(in + (x != 1), out) * t[x]),
    dp[x][1] = min(dp[x][1], cur + 1ll * max(in, out + (x != 1)) * t[x]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(dp, 0x3f, sizeof dp);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) cin >> h[i];
  for (int i = 1, x, y; i < n; i++)
    cin >> x >> y, v[x].push_back(y), v[y].push_back(x);
  dfs(1, 0);
  cout << min(dp[1][1], dp[1][0]);
  return 0;
}
