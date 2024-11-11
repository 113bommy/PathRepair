#include <bits/stdc++.h>
using namespace std;
const long long N = 3e3 + 100, OO = 1e12 + 7, M = 1e9 + 7, P = 6151, sq = 500,
                lg = 23;
vector<long long> v[N];
pair<long long, long long> pr[N][N];
bool is[N][N];
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  is[1][n] = 1;
  pr[1][n] = {0, 0};
  queue<pair<long long, long long> > q;
  q.push({1, n});
  while (q.size()) {
    long long u1 = q.front().first, u2 = q.front().second;
    q.pop();
    if (u1 == u2) continue;
    for (auto v1 : v[u1]) {
      for (auto v2 : v[u2]) {
        if (is[v1][v2]) continue;
        is[v1][v2] = true;
        q.push({v1, v2});
        pr[v1][v2] = {u1, u2};
      }
    }
  }
  long long a = n, b = 1;
  if (!is[a][b]) return cout << -1, 0;
  vector<long long> ans1, ans2;
  while (a > 0 && b > 0) {
    ans1.push_back(a), ans2.push_back(b);
    pair<long long, long long> p = pr[a][b];
    a = p.first, b = p.second;
  }
  cout << (long long)ans1.size() - 1 << endl;
  for (auto u : ans2) cout << u << " ";
  cout << endl;
  for (auto u : ans1) cout << u << " ";
  return 0;
}
