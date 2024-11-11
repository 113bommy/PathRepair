#include <bits/stdc++.h>
using namespace std;
int d[180], K, dep[181], f[181][180], g[181][180], minf[181], ans[181],
    gsiz[181];
vector<int> mp[181];
void calcdep(int k, int p, int curd) {
  dep[k] = curd;
  for (auto c : mp[k])
    if (c != p) {
      calcdep(c, k, curd + 1);
      dep[k] = max(dep[k], dep[c]);
    }
}
void dfs(int k, int p, int curd) {
  int mxd = gsiz[k];
  for (auto c : mp[k])
    if (c != p) {
      gsiz[c] = max(gsiz[c], mxd);
      mxd = max(mxd, dep[c] - curd);
    }
  mxd = gsiz[k];
  for (int i = mp[k].size() - 1; i >= 0; --i)
    if (mp[k][i] != p) {
      gsiz[mp[k][i]] = max(gsiz[mp[k][i]], mxd);
      mxd = max(mxd, dep[mp[k][i]] - curd);
    }
  f[k][0] = K;
  for (auto c : mp[k])
    if (c != p) {
      ++gsiz[c];
      dfs(c, k, curd + 1);
      f[k][0] += min(g[c][1], minf[c]);
    }
  for (int i = 1; i <= dep[k] - curd; ++i) {
    int tot = 0;
    for (auto c : mp[k])
      if (c != p) tot += min(minf[c], g[c][i + 1]);
    f[k][i] = 1000000000;
    for (auto c : mp[k])
      if (c != p && dep[c] - curd >= i)
        f[k][i] = min(f[k][i], tot - min(minf[c], g[c][i + 1]) + f[c][i - 1]);
    f[k][i] += d[i];
  }
  for (int i = 1; i <= gsiz[k]; ++i) {
    g[k][i] = d[i];
    for (auto c : mp[k])
      if (c != p) g[k][i] += min(g[c][i + 1], minf[c]);
  }
  minf[k] = 1000000000;
  for (int i = 0; i <= dep[k] - curd; ++i) minf[k] = min(minf[k], f[k][i]);
}
void fprint(int k, int p, int curd, int fidx);
void gprint(int k, int p, int curd, int gidx) {
  ans[k] = ans[p];
  for (auto c : mp[k])
    if (c != p)
      g[c][gidx + 1] < minf[c] ? gprint(c, k, curd + 1, gidx + 1)
                               : fprint(c, k, curd + 1, -1);
}
void fprint(int k, int p, int curd, int fidx) {
  if (!fidx || (fidx == -1 && minf[k] == f[k][0])) {
    ans[k] = k;
    for (auto c : mp[k])
      if (c != p)
        g[c][1] < minf[c] ? gprint(c, k, curd + 1, 1)
                          : fprint(c, k, curd + 1, -1);
  } else {
    if (fidx == -1) {
      fidx = 1;
      while (f[k][fidx] != minf[k]) ++fidx;
    }
    int tot = d[fidx];
    for (auto c : mp[k])
      if (c != p) tot += min(minf[c], g[c][fidx + 1]);
    int mxv;
    for (auto c : mp[k])
      if (c != p && dep[c] - curd >= fidx &&
          tot - min(minf[c], g[c][fidx + 1]) + f[c][fidx - 1] == f[k][fidx]) {
        mxv = c;
        break;
      }
    fprint(mxv, k, curd + 1, fidx - 1);
    ans[k] = ans[mxv];
    for (auto c : mp[k])
      if (c != p && c != mxv)
        g[c][fidx + 1] < minf[c] ? gprint(c, k, curd + 1, fidx + 1)
                                 : fprint(c, k, curd + 1, -1);
  }
}
int main() {
  int n;
  scanf("%d%d", &n, &K);
  for (int i = 1; i < n; ++i) scanf("%d", d + i);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    mp[a].push_back(b);
    mp[b].push_back(a);
  }
  calcdep(1, 0, 0);
  dfs(1, 0, 0);
  printf("%d\n", minf[1]);
  fprint(1, 0, 0, -1);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
