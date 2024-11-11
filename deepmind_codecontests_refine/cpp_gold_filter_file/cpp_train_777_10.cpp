#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
const double inf = 9e25 + 7;
int ar[N], sz[N], dist[N], ver = N;
vector<pair<int, int> > adj[N];
double ans = inf, deri[N], pot;
bool used[N];
void dfs(int x, int p) {
  sz[x] = 1;
  for (auto i : adj[x]) {
    if (used[i.first] || i.first == p) {
      continue;
    }
    dfs(i.first, x);
    sz[x] += sz[i.first];
  }
}
int findcen(int x, int p, int siz) {
  for (auto i : adj[x]) {
    if (used[i.first] || i.first == p) {
      continue;
    }
    if (sz[i.first] > siz / 2) {
      return findcen(i.first, x, siz);
    }
  }
  return x;
}
void dfs1(int x, int p, int from) {
  deri[from] += sqrt(dist[x]) * 3.0 / 2 * ar[x];
  pot += 1.0 * sqrt(dist[x]) * dist[x] * ar[x];
  for (auto i : adj[x]) {
    if (i.first == p) {
      continue;
    }
    dist[i.first] = dist[x] + i.second;
    dfs1(i.first, x, from);
  }
}
void centroid(int x, int siz) {
  dfs(x, x);
  int cen = findcen(x, x, siz);
  dfs(cen, cen);
  used[cen] = true;
  double sumd = 0;
  pot = 0;
  for (auto i : adj[cen]) {
    dist[i.first] = i.second;
    deri[i.first] = 0;
    dfs1(i.first, cen, i.first);
    sumd += deri[i.first];
  }
  if (pot < ans) {
    ans = pot;
    ver = cen;
  }
  for (auto i : adj[cen]) {
    if (sumd - 2 * deri[i.first] < 0 && !used[i.first]) {
      centroid(i.first, sz[i.first]);
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, i, j, k, l, m;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for (i = 1; i < n; i++) {
    cin >> j >> k >> l;
    adj[j].push_back({k, l});
    adj[k].push_back({j, l});
  }
  centroid(1, n);
  cout << ver << ' ' << fixed << setprecision(15) << ans;
}
