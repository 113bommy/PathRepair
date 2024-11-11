#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const long long inf = 1e14;
vector<pair<int, long long> > G[maxn];
long long plen[maxn];
int pi[maxn];
void dfs1(int x, int p, long long l) {
  pi[x] = p;
  plen[x] = l;
  for (pair<int, long long> z : G[x]) {
    if (z.first == p) continue;
    dfs1(z.first, x, l + z.second);
  }
}
vector<int> path;
long long ext[maxn];
long long nx[maxn];
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
  };
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int x, y;
    long long w;
    cin >> x >> y >> w;
    G[x].push_back({y, w});
    G[y].push_back({x, w});
  }
  dfs1(1, -1, 0);
  int cur = n;
  while (cur > 0) {
    path.push_back(cur);
    cur = pi[cur];
  }
  int k = path.size();
  bool cons = false;
  int seen = k;
  for (int i = 0; i < k; i++) {
    nx[i] = 0;
    ext[i] = 0;
    int v = path[i];
    int nv = (i + 1 < k) ? path[i + 1] : -1;
    int pv = (i - 1 >= 0) ? path[i - 1] : -1;
    int cnt = 0;
    for (pair<int, long long> z : G[v]) {
      if (z.first == nv) {
        nx[i] = z.second;
      }
      if (z.first != nv && z.first != pv) {
        cnt++;
        if (cnt > 1) {
          cons = true;
          goto done;
        }
        ext[i] = z.second;
        seen++;
      }
    }
  }
done:
  if (cons || seen < n) {
    while (m--) {
      cout << plen[n] << endl;
    }
    return 0;
  }
  long long bound = inf;
  for (int i = 0; i < k; i++) {
    if (i + 2 < k) {
      bound = min(bound, nx[i] + nx[i + 1]);
    }
    if (i + 1 < k) {
      if (ext[i] > 0) {
        bound = min(bound, nx[i] - ext[i]);
      }
      if (ext[i + 1] > 0) {
        bound = min(bound, nx[i] - ext[i + 1]);
      }
      if (ext[i] > 0 && ext[i + 1] > 0) {
        bound = min(bound, nx[i] - ext[i] - ext[i + 1]);
      }
    }
  }
  while (m--) {
    long long w;
    cin >> w;
    cout << plen[n] - max(0ll, bound - w) << endl;
  }
}
