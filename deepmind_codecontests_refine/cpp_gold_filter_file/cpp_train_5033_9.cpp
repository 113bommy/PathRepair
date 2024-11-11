#include <bits/stdc++.h>
using namespace std;
const int maxn = 1505;
vector<long long> g[maxn];
long long n, u, v;
pair<pair<long long, long long>, int> pts[maxn];
long long sz[maxn];
bool leftTurn(pair<long long, long long> o, pair<long long, long long> a,
              pair<long long, long long> b) {
  return (a.first - o.first) * (b.second - o.second) -
             (a.second - o.second) * (b.first - o.first) >
         0;
}
long long dfs(long long u, long long prev) {
  sz[u] = 1;
  for (auto adj : g[u]) {
    if (adj != prev) {
      sz[u] += dfs(adj, u);
    }
  }
  return sz[u];
}
long long ans[maxn];
void solve(long long u, long long prev, long long l, long long r) {
  sort(&pts[l], &pts[r] + 1);
  pair<pair<long long, long long>, int> src = pts[l];
  sort(&pts[l] + 1, &pts[r] + 1,
       [&](pair<pair<long long, long long>, int> a,
           pair<pair<long long, long long>, int> b) {
         return leftTurn(src.first, a.first, b.first);
       });
  ans[src.second] = u;
  if (r - l < 1) return;
  l++;
  for (auto adj : g[u]) {
    if (adj != prev) {
      solve(adj, u, l, l + sz[adj] - 1);
      l += sz[adj];
    }
  }
}
int main() {
  scanf("%lld", &(n));
  for (int(i) = (1); (i) <= (n - 1); (i)++) {
    scanf("%lld", &(u));
    scanf("%lld", &(v));
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int(i) = (1); (i) <= (n); (i)++) {
    scanf("%lld", &(pts[i].first.first));
    scanf("%lld", &(pts[i].first.second));
    pts[i].second = i;
  }
  dfs(1, -1);
  solve(1, -1, 1, n);
  for (int(i) = (1); (i) <= (n); (i)++) cout << ans[i] << ' ';
  cout << endl;
}
