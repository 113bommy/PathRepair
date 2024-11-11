#include <bits/stdc++.h>
using namespace std;
int n;
int x[100005], y[100005];
int allx[100005], ally[100005], cx = 0, cy = 0;
vector<int> vx[100005], vy[100005];
pair<pair<int, int>, int> p[100005];
int par[100005], ra[100005], cyc[100005];
void dsuInit() {
  for (int i = 0; i < (int)(n); ++i) par[i] = i, ra[i] = 1, cyc[i] = 0;
}
int dsuParent(int v) {
  if (v == par[v]) return v;
  return par[v] = dsuParent(par[v]);
}
void dsuMerge(int u, int v) {
  u = dsuParent(u);
  v = dsuParent(v);
  if (u == v) {
    cyc[u] = 1;
    return;
  }
  if (ra[u] < ra[v]) swap(u, v);
  par[v] = u;
  ra[u] += ra[v];
  cyc[u] |= cyc[v];
}
vector<int> cm[100005];
const int MOD = int(1e9) + 7;
int po[200005];
int nused = 0;
int ux[100005], uy[100005];
int main() {
  po[0] = 1;
  for (int i = 1; i < 200005; ++i) {
    po[i] = 2 * po[i - 1] % MOD;
  }
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d%d", x + i, y + i);
  for (int i = 0; i < (int)(n); ++i) allx[i] = x[i], ally[i] = y[i];
  sort(allx, allx + n);
  sort(ally, ally + n);
  cx = unique(allx, allx + n) - allx;
  cy = unique(ally, ally + n) - ally;
  for (int i = 0; i < (int)(n); ++i)
    x[i] = lower_bound(allx, allx + cx, x[i]) - allx;
  for (int i = 0; i < (int)(n); ++i)
    y[i] = lower_bound(ally, ally + cy, y[i]) - ally;
  for (int i = 0; i < (int)(n); ++i) p[i] = make_pair(make_pair(x[i], y[i]), i);
  sort(p, p + n);
  for (int i = 0; i < (int)(n); ++i)
    vy[p[i].first.second].push_back(p[i].second);
  for (int i = 0; i < (int)(n); ++i) p[i] = make_pair(make_pair(y[i], x[i]), i);
  sort(p, p + n);
  for (int i = 0; i < (int)(n); ++i)
    vx[p[i].first.second].push_back(p[i].second);
  dsuInit();
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 1; j < (int)vx[i].size(); ++j) {
      dsuMerge(vx[i][j - 1], vx[i][j]);
    }
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 1; j < (int)vy[i].size(); ++j) {
      dsuMerge(vy[i][j - 1], vy[i][j]);
    }
  for (int i = 0; i < (int)(n); ++i) {
    cm[dsuParent(i)].push_back(i);
  }
  int ans = 1;
  for (int i = 0; i < (int)(n); ++i)
    if (!cm[i].empty()) {
      if (cyc[i]) {
        ++nused;
        int pp = 0;
        for (int ind : cm[i]) {
          if (ux[x[ind]] != nused) {
            ux[x[ind]] = nused;
            ++pp;
          }
          if (uy[y[ind]] != nused) {
            uy[y[ind]] = nused;
            ++pp;
          }
        }
        ans = (long long)ans * po[pp] % MOD;
      } else {
        ans = (long long)ans * (po[(int)cm[i].size() + 1] - 1) % MOD;
      }
    }
  cout << ans << endl;
  return 0;
}
