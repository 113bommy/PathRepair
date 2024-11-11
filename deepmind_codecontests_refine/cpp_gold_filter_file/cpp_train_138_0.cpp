#include <bits/stdc++.h>
using namespace std;
void oj() {}
long long dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
long long dy[] = {0, 1, -1, 1, -1, 0, 1, -1};
long long solve() {
  long long x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;
  long long n;
  cin >> n;
  long long r, a, b;
  map<pair<long long, long long>, long long> mp, vis, dist;
  for (long long i = 0; i < n; i++) {
    cin >> r >> a >> b;
    for (long long j = a; j <= b; j++) {
      mp[{r, j}]++;
    }
  }
  queue<pair<pair<long long, long long>, long long>> q;
  q.push({{x0, y0}, 0});
  vis[{x0, y0}]++;
  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    long long x = it.first.first;
    long long y = it.first.second;
    long long steps = it.second;
    for (long long i = 0; i < 8; i++) {
      long long newi = x + dx[i];
      long long newj = y + dy[i];
      if (vis.find({newi, newj}) == vis.end() &&
          mp.find({newi, newj}) != mp.end()) {
        q.push({{newi, newj}, steps + 1});
        vis[{newi, newj}]++;
        if (newi == x1 && newj == y1) return (steps + 1);
      }
    }
  }
  return -1;
}
int32_t main() {
  oj();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    cout << solve() << "\n";
  }
  return 0;
}
