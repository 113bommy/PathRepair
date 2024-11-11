#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long par[N], spec[N];
pair<long long, long long> siz[N];
long long root(long long x) {
  while (par[x] != -1) x = par[x];
  return x;
}
void merge(long long x, long long y) {
  x = root(x);
  y = root(y);
  if (x == y) return;
  if (siz[y] < siz[x]) swap(x, y);
  siz[y].first += siz[x].first;
  siz[y].second += siz[x].second;
  par[x] = y;
}
vector<pair<long long, pair<long long, long long> > > edges;
void solve() {
  memset(par, -1, sizeof par);
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 0; i < k; ++i) {
    long long x;
    cin >> x;
    spec[x] = 1;
  }
  for (long long i = 0; i < N; ++i) {
    if (spec[i])
      siz[i] = make_pair(1, 1);
    else
      siz[i] = make_pair(1, 0);
  }
  for (long long i = 0; i < m; ++i) {
    long long x, y, w;
    cin >> x >> y >> w;
    edges.push_back(make_pair(w, make_pair(x, y)));
  }
  long long ans = -1;
  sort(edges.begin(), edges.end());
  for (auto i : edges) {
    long long x = i.second.first;
    long long y = i.second.second;
    if (root(x) != root(y)) {
      merge(x, y);
      if (siz[root(x)].second == k) {
        ans = i.first;
        break;
      }
    }
  }
  for (long long i = 0; i < n; ++i) cout << ans << ' ';
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
