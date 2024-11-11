#include <bits/stdc++.h>
using namespace std;
long long a[1002][1002], vis[1002][1002], arr[1002][1002], n, m, k,
    parent[1000005], siz[1000005], need, num;
vector<pair<long long, pair<long long, long long> > > v;
set<pair<long long, long long> > s;
vector<pair<long long, long long> > ans;
void dfs(long long x, long long y) {
  vis[x][y] = 1;
  if ((long long)ans.size() > need) return;
  ans.push_back({x, y});
  for (long long i = -1; i < 2; i++) {
    for (long long j = -1; j < 2; j++) {
      if (i * j == 0 && !(i == 0 && j == 0) && x + i >= 0 && x + i <= n &&
          y + j >= 0 && y + j <= m && !vis[x + i][y + j] &&
          a[x + i][y + j] >= num)
        dfs(x + i, y + j);
    }
  }
}
long long find(long long u) {
  if (parent[u] != u) parent[u] = find(parent[u]);
  return parent[u];
}
void merge(long long u, long long v) {
  u = find(u);
  v = find(v);
  if (u != v) {
    if (siz[v] >= siz[u]) swap(u, v);
    siz[u] += siz[v];
    parent[v] = u;
  }
}
void solve() {
  cin >> n >> m >> k;
  for (long long i = 1; i < n * m + 1; i++) parent[i] = i, siz[i] = 1;
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      cin >> a[i][j];
      v.push_back({a[i][j], {i, j}});
    }
  }
  sort((v).begin(), (v).end());
  reverse((v).begin(), (v).end());
  long long f = 0;
  pair<long long, long long> c;
  for (auto p : v) {
    c = p.second;
    long long x = c.first, y = c.second;
    for (long long i = -1; i < 2; i++) {
      for (long long j = -1; j < 2; j++) {
        if (i * j == 0 && !(i == 0 && j == 0) && x + i >= 0 && x + i <= n &&
            y + j >= 0 && y + j <= m && s.find({x + i, y + j}) != s.end())
          merge((x - 1) * m + y, (x + i - 1) * m + (y + j));
      }
    }
    s.insert(c);
    if (k % a[x][y] == 0 && siz[find((x - 1) * m + y)] >= k / a[x][y]) {
      f = 1;
      break;
    }
  }
  if (f == 0)
    cout << "NO";
  else {
    cout << "YES" << '\n';
    need = k / a[c.first][c.second], num = a[c.first][c.second];
    dfs(c.first, c.second);
    for (auto p : ans) arr[p.first][p.second] = num;
    for (long long i = 1; i < n + 1; i++) {
      for (long long j = 1; j < m + 1; j++) {
        cout << arr[i][j] << " ";
      }
      cout << '\n';
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
