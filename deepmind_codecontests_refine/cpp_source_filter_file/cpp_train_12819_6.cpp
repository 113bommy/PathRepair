#include <bits/stdc++.h>
using namespace std;
long long n, r1, c1, r2, c2;
vector<string> s;
long long vis[51][51];
vector<pair<long long, long long> > pp{
    {-1ll, 0ll}, {1ll, 0ll}, {0ll, 1ll}, {0ll, -1ll}};
vector<pair<long long, long long> > bfs(long long lx, long long ly) {
  vector<pair<long long, long long> > ans;
  queue<pair<long long, long long> > q;
  q.push({lx, ly});
  vis[lx][ly] = 1;
  while (q.size()) {
    auto top = q.front();
    ans.push_back(top);
    q.pop();
    for (auto &i : pp) {
      long long nx = top.first + i.first, ny = top.second + i.second;
      if (nx < 0 || nx >= n) continue;
      if (ny < 0 || ny >= n) continue;
      if (vis[nx][ny]) continue;
      if (s[nx][ny] == '1') continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> r1 >> c1 >> r2 >> c2;
  r1--;
  c1--;
  r2--;
  c2--;
  s.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
  }
  long long ans = n * n;
  auto a = bfs(r1, c1), b = bfs(r2, c2);
  for (auto &i : a) {
    for (auto &j : b) {
      ans = min(ans, (i.first - j.first) * (i.first - j.first) +
                         (i.second - j.second) * (i.second - j.second));
    }
  }
  cout << ans << '\n';
  return 0;
}
