#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
const long long N = 2e7 + 5;
vector<long long> vv[maxn], uu[maxn], pp[maxn];
long long degree[maxn];
long long n, m, k;
queue<long long> q;
long long vis[maxn];
bool res[maxn];
long long r;
void init() {
  r = 0;
  while (q.size()) q.pop();
  for (long long i = 1; i <= n; i++)
    vv[i].clear(), pp[i].clear(), degree[i] = 0;
}
long long step1() {
  long long cnt = n;
  for (long long i = 1; i <= n; ++i) {
    vis[i] = 0;
    if (degree[i] < k) q.push(i);
  }
  while (q.size()) {
    long long u = q.front();
    vis[u] = 1;
    cnt--;
    q.pop();
    if (degree[u] == k - 1) {
      ++r;
      uu[r].clear();
      pp[u].push_back(r);
      uu[r].push_back(u);
      for (long long i = 0; i < vv[u].size(); ++i) {
        if (!vis[vv[u][i]]) {
          uu[r].push_back(vv[u][i]);
          pp[vv[u][i]].push_back(r);
        }
      }
    }
    for (long long i = 0; i < vv[u].size(); i++) {
      long long v = vv[u][i];
      if (vis[v] == 0) {
        degree[v]--;
        if (degree[v] == k - 1) q.push(v);
      }
    }
  }
  if (cnt > 0) {
    cout << "1 " << cnt << "\n";
    for (long long i = 1; i <= n; ++i)
      if (degree[i] >= k) cout << i << " ";
    return cout << "\n", 1;
  }
  return 0;
}
long long step2() {
  for (long long i = 1; i <= n; i++) vis[i] = 0;
  for (long long i = 1; i <= r; i++) res[i] = true;
  for (long long i = 1; i <= n; i++) {
    if (pp[i].size() == 0) continue;
    vis[i] = 1;
    for (long long j = 0; j < vv[i].size(); j++) vis[vv[i][j]] = 1;
    for (long long j = 0; j < pp[i].size(); j++) {
      long long tuan = pp[i][j];
      if (res[tuan])
        for (long long k = 0; k < uu[tuan].size(); k++) {
          if (vis[uu[tuan][k]] == 0) {
            res[tuan] = false;
            break;
          }
        }
    }
    vis[i] = 0;
    for (long long j = 0; j < vv[i].size(); j++) vis[vv[i][j]] = 0;
  }
  for (long long i = 1; i <= r; ++i)
    if (res[i]) {
      cout << "2\n";
      for (long long j = 0; j < uu[i].size(); ++j) cout << uu[i][j] << " ";
      return cout << "\n", 1;
    }
  return 0;
}
void solve() {
  cin >> n >> m >> k;
  init();
  for (long long i = 1; i <= m; ++i) {
    long long x, y;
    cin >> x >> y;
    degree[x]++, degree[y]++;
    vv[y].push_back(x);
    vv[x].push_back(y);
  }
  if (k * (k - 1) > m * 2) {
    cout << "-1\n";
    return;
  }
  if (step1()) return;
  if (step2()) return;
  cout << "-1\n";
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
