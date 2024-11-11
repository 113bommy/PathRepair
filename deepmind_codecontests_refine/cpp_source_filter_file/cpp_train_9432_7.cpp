#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, siz, srt, fin, edge;
int cycle[N], dep[N], a[N], b[N], par[N];
long long mx[N], tmp[N], sum[N], l[N], wght[N];
long long pre[N], suf[N], pre2[N], suf2[N], dia, ans;
bool vis[N], cyc[N];
vector<int> g[N];
void dfs(int x) {
  vis[x] = 1;
  for (auto it : g[x]) {
    int ver = a[it] ^ b[it] ^ x;
    if (vis[ver] and it != par[x]) {
      srt = x;
      fin = ver;
      edge = it;
    } else if (!vis[ver]) {
      par[ver] = it;
      dep[ver] = dep[x] + 1;
      dfs(ver);
    }
  }
}
int maxdfs(int x) {
  vis[x] = 1;
  int ver;
  long long z, mx = 0, smx = 0;
  for (int it : g[x]) {
    ver = a[it] ^ b[it] ^ x;
    if (!vis[ver] and !cyc[ver]) {
      z = maxdfs(ver) + l[it];
      if (z > mx) {
        smx = mx;
        mx = z;
      } else if (z > smx) {
        smx = z;
      }
    }
  }
  dia = max(dia, mx + smx);
  return mx;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%lld", a + i, b + i, l + i);
    g[a[i]].push_back(i);
    g[b[i]].push_back(i);
  }
  dfs(1);
  if (dep[fin] < dep[srt]) swap(srt, fin);
  int ver = fin;
  while (ver != srt) {
    siz++;
    cycle[siz] = ver;
    int e = par[ver];
    wght[siz] = l[e];
    ver = a[e] ^ b[e] ^ ver;
  }
  siz++;
  cycle[siz] = ver;
  wght[siz] = l[edge];
  for (int i = 1; i <= siz; i++) cyc[cycle[i]] = 1;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= siz; i++) {
    mx[i] = maxdfs(cycle[i]);
  }
  for (int i = 1; i <= siz; i++) {
    sum[i] = sum[i - 1] + wght[i];
  }
  pre[1] = mx[1];
  tmp[1] = mx[1];
  for (int i = 2; i <= siz; i++) {
    pre[i] = max(pre[i - 1], mx[i] + tmp[i - 1] + wght[i - 1]);
    tmp[i] = max(mx[i], wght[i - 1] + tmp[i - 1]);
  }
  suf[siz] = mx[siz];
  tmp[siz] = mx[siz];
  for (int i = siz - 1; i > 0; i--) {
    suf[i] = max(suf[i + 1], mx[i] + tmp[i + 1] + wght[i]);
    tmp[i] = max(mx[i], wght[i] + tmp[i + 1]);
  }
  pre2[1] = mx[1];
  for (int i = 2; i <= siz; i++) {
    pre2[i] = max(mx[i] + sum[i - 1], pre2[i - 1]);
  }
  suf2[siz] = wght[siz] + mx[siz];
  for (int i = siz - 1; i > 0; i--) {
    suf2[i] = max(suf2[i + 1], mx[i] + sum[siz] - sum[i - 1]);
  }
  ans = max(dia, pre[siz]);
  for (int i = 1; i < siz; i++) {
    long long r = max(pre[i], suf[i + 1]);
    r = max(r, pre2[i] + suf2[i + 1]);
    r = max(dia, r);
    ans = min(ans, r);
  }
  printf("%lld\n", ans);
}
