#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > v;
long long ans[50005][505];
long long vis[50005];
long long h[50005];
long long n, k;
long long res = 0;
void dfs(long long i, long long x) {
  vis[i] = 1;
  h[i] = x;
  ans[i][0]++;
  for (auto j : v[i]) {
    if (vis[j] == 0) {
      dfs(j, x + 1);
      for (long long l = 1; l <= k; ++l) {
        ans[i][l] += ans[j][l - 1];
      }
    }
  }
}
void dfs2(long long i) {
  vis[i] = 1;
  res += ans[i][k];
  long long cnt = 0;
  for (auto j : v[i]) {
    if (vis[j] == 0) {
      dfs2(j);
      for (long long l = 0; l <= k; ++l) {
        if (k - l - 2 >= 0)
          cnt += ans[j][l] * (ans[i][k - l - 1] - ans[j][k - l - 2]);
      }
    }
  }
  cnt /= 2;
  res += cnt;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  long long x, y;
  v.resize(n);
  for (long long i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    x--;
    y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(0, 0);
  fill_n(vis, 50005, 0);
  dfs2(0);
  cout << res;
}
