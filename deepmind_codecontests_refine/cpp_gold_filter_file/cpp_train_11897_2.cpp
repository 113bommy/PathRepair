#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int n0 = 3003, inf = (int)2e9 + 123;
int n, x[n0], y[n0], c[n0], t;
int xl[n0], xr[n0], yl[n0], yr[n0], xp[n0], yp[n0];
int cur[n0], res[n0];
vector<int> g[n0], vec[n0];
void dfs(int v) {
  c[v] = t;
  for (int i : g[v]) {
    if (c[i] == -1) dfs(i);
  }
}
bitset<n0> b, b2, rg[n0];
bool ok(int k) {
  for (int i = 0; i < t; i++) vec[i].clear();
  t = 0;
  for (int i = 0; i < n; i++) g[i].clear();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((x[i] == x[j] && abs(y[i] - y[j]) <= k) ||
          (y[i] == y[j] && abs(x[i] - x[j]) <= k))
        g[i].push_back(j), g[j].push_back(i);
    }
  }
  memset(&c, -1, sizeof(c));
  vector<long long> vx, vy;
  for (int i = 0; i < n; i++) {
    if (c[i] == -1) dfs(i), t++;
    vec[c[i]].push_back(i);
    vx.push_back(x[i]), vx.push_back((long long)x[i] - k),
        vx.push_back((long long)x[i] + k);
    vy.push_back(y[i]), vy.push_back((long long)y[i] - k),
        vy.push_back((long long)y[i] + k);
  }
  if (t == 1) return true;
  sort(begin(vx), end(vx)), (vx).erase(unique(begin(vx), end(vx)), end(vx)),
      sort(begin(vy), end(vy)), (vy).erase(unique(begin(vy), end(vy)), end(vy));
  b.reset(), b2.reset();
  for (int i = 0; i < n; i++) {
    xl[i] =
        lower_bound(begin(vx), end(vx), (long long)x[i] - k) - begin(vx) + 1;
    xr[i] = upper_bound(begin(vx), end(vx), (long long)x[i] + k) - begin(vx);
    xp[i] = lower_bound(begin(vx), end(vx), x[i]) - begin(vx) + 1;
    yl[i] =
        lower_bound(begin(vy), end(vy), (long long)y[i] - k) - begin(vy) + 1;
    yr[i] = upper_bound(begin(vy), end(vy), (long long)y[i] + k) - begin(vy);
    yp[i] = lower_bound(begin(vy), end(vy), y[i]) - begin(vy) + 1;
    rg[i].reset();
    for (int j = yl[i]; j <= yr[i]; j++) rg[i][j] = 1;
  }
  for (int X = 1; X <= (int)(vx).size(); X++) {
    b2.set();
    for (int i = 0; i < t; i++) {
      b.reset();
      for (int j : vec[i]) {
        if (X == xp[j]) b |= rg[j];
        if (X >= xl[j] && X <= xr[j]) b[yp[j]] = 1;
      }
      b2 &= b;
    }
    if (b2.count()) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  int l = -1, r = inf;
  while (l < r - 1) {
    int mid = l + (r - l) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  if (r == inf)
    cout << -1;
  else
    cout << r;
}
