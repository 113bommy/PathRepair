#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
vector<pair<long long, pair<long long, long long> > > dsk[300005];
bool chkdsk[300005];
vector<long long> vs;
void input() {
  cin >> n >> m >> k;
  long long x, y, c;
  for (long long i = 1; i <= n; i++) {
    cin >> x >> y >> c;
    dsk[x].push_back({-c, {y, i}});
    dsk[y].push_back({-c, {x, i}});
  }
  return;
}
void Dijkstra() {
  priority_queue<pair<long long, pair<long long, long long> > > q;
  q.push({0, {1, 69696}});
  long long chk = -1;
  while (!q.empty() && chk < k) {
    long long x = q.top().first, y = q.top().second.first,
              z = q.top().second.second;
    q.pop();
    if (chkdsk[y]) {
      continue;
    }
    chk++;
    chkdsk[y] = 1;
    vs.push_back(z);
    for (long long i = 0; i < dsk[y].size(); i++) {
      long long a = dsk[y][i].first, b = dsk[y][i].second.first,
                c = dsk[y][i].second.second;
      q.push({x + a, {b, c}});
    }
  }
}
void solve() {
  Dijkstra();
  return;
}
void output() {
  cout << vs.size() - 1 << endl;
  for (long long i = 1; i < vs.size(); i++) {
    cout << vs[i] << " ";
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  input();
  solve();
  output();
  return 0;
}
