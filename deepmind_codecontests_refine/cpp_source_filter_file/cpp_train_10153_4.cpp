#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;
long long a[maxn];
vector<int> rb[maxn];
bool pm1[maxn], pm2[maxn];
long long dw[maxn], adw[maxn];
long long ans = 0;
void dfs1(int u) {
  bool *pm = pm1;
  pm[u] = 1;
  long long c1 = 0, c2 = 0;
  for (int i = 0; i < (int)rb[u].size(); i++) {
    int &v = rb[u][i];
    if (pm[v]) continue;
    dfs1(v);
    dw[u] = max(dw[u], dw[v] + a[v]);
    if (c2 < dw[v] + a[v]) {
      c2 = dw[v] + a[v];
    }
    if (c1 < dw[v] + a[v]) {
      swap(c1, c2);
    }
    adw[u] = max(adw[u], adw[v]);
  }
  adw[u] = max(adw[u], c1 + c2 + a[u]);
}
void dfs2(int u, int p = -1, long long dwp = 0, long long adwp = 0) {
  bool *pm = pm2;
  pm[u] = 1;
  long long c1 = dwp, c2 = 0, c3 = 0, ic1 = p, ic2 = -1, ic3 = -1;
  long long d1 = adwp, d2 = 0, id1 = p, id2 = -1;
  for (int i = 0; i < (int)rb[u].size(); i++) {
    int &v = rb[u][i];
    if (pm[v]) continue;
    if (c3 < dw[v] + a[v]) {
      c3 = dw[v] + a[v];
      ic3 = v;
    }
    if (c2 < dw[v] + a[v]) {
      swap(c2, c3);
      swap(ic2, ic3);
    }
    if (c1 < dw[v] + a[v]) {
      swap(c1, c2);
      swap(ic1, ic2);
    }
    if (d2 < adw[v]) {
      d2 = adw[v];
      id2 = v;
    }
    if (d1 < adw[v]) {
      swap(d1, d2);
      swap(id1, id2);
    }
  }
  for (int i = 0; i < (int)rb[u].size(); i++) {
    int &v = rb[u][i];
    if (pm[v]) continue;
    int nadwp = 0, ndwp = 0;
    if (ic1 == v) {
      nadwp = c2 + c3 + a[u];
      ndwp = c2 + a[u];
    } else if (ic2 == v) {
      nadwp = c1 + c3 + a[u];
      ndwp = c1 + a[u];
    } else {
      nadwp = c1 + c2 + a[u];
      ndwp = c1 + a[u];
    }
    if (d1 > nadwp && id1 != v) {
      nadwp = d1;
    }
    if (d2 > nadwp && id2 != v) {
      nadwp = d2;
    }
    dfs2(v, u, ndwp, nadwp);
    ans = max(ans, nadwp + adw[v]);
  }
}
int main() {
  {
    srand(time(0));
    const string file = "";
    if (!file.empty()) {
      freopen((file + ".in").c_str(), "r", stdin);
      freopen((file + ".out").c_str(), "w", stdout);
    }
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    rb[--u].push_back(--v);
    rb[v].push_back(u);
  }
  dfs1(0);
  dfs2(0);
  printf("%lld", ans);
  return (0);
}
