#include <bits/stdc++.h>
using namespace std;
long long n, x[((long long)101 * 1000)], y[((long long)101 * 1000)], cnt,
    ans = 1;
vector<long long> vx, vy, e[2][((long long)101 * 1000)];
bool cycle, mark[2][((long long)101 * 1000)];
void dfs(long long x, bool p, long long par = -1) {
  mark[p][x] = 1;
  cnt *= 2;
  cnt %= ((long long)1e9 + 7);
  for (auto u : e[p][x]) {
    if (u == par) continue;
    if (mark[!p][u]) {
      cycle = 1;
      continue;
    }
    dfs(u, !p, x);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    vx.push_back(x[i]);
    vy.push_back(y[i]);
  }
  sort(vx.begin(), vx.end());
  vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
  sort(vy.begin(), vy.end());
  vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
  for (int i = 0; i < n; i++) {
    long long v = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
    long long u = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
    e[0][v].push_back(u);
    e[1][u].push_back(v);
  }
  for (int i = 0; i < vx.size(); i++)
    if (!mark[0][i]) {
      cycle = 0;
      cnt = 1;
      dfs(i, 0);
      cnt -= 1 - cycle;
      cnt += ((long long)1e9 + 7);
      cnt %= ((long long)1e9 + 7);
      ans *= cnt;
      ans %= ((long long)1e9 + 7);
    }
  cout << ans << "\n";
  return 0;
}
