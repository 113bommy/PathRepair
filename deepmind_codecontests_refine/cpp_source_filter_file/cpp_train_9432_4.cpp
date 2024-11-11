#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, siz, srt, fin, edge;
int cycle[N], dep[N], a[N], b[N], par[N];
long long mx[N], tmp, sum[N], l[N], wght[N];
long long pre[N], suf[N], pre2[N], suf2[N], dia, ans;
bool vis[N], cyc[N];
vector<int> g[N];
void dfs(int x, int p, int d) {
  vis[x] = 1;
  dep[x] = d;
  for (auto it : g[x]) {
    int ver = a[it] ^ b[it] ^ x;
    if (ver == p) continue;
    if (vis[ver]) {
      srt = x;
      fin = ver;
      edge = it;
    } else {
      par[ver] = it;
      dfs(ver, x, d + 1);
    }
  }
}
int maxdfs(int x, int p) {
  vis[x] = 1;
  int ver;
  long long z, mx = 0, smx = 0;
  for (int it : g[x]) {
    ver = a[it] ^ b[it] ^ x;
    if (ver != p and !cyc[ver]) {
      z = maxdfs(ver, x) + l[it];
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
  dfs(1, 0, 1);
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
  cycle[siz] = srt;
  for (int it : g[srt]) {
    ver = a[it] ^ b[it] ^ srt;
    if (ver == fin) {
      wght[siz] = l[it];
      break;
    }
  }
  for (int i = 1; i <= siz; i++) cyc[cycle[i]] = 1;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= siz; i++) {
    mx[i] = maxdfs(cycle[i], 0);
  }
  for (int i = 2; i <= siz; i++) {
    sum[i] = sum[i - 1] + wght[i - 1];
  }
  pre[1] = mx[1];
  tmp = mx[1];
  for (int i = 2; i <= siz; i++) {
    pre[i] = max(pre[i - 1], mx[i] + tmp + sum[i]);
    tmp = max(tmp, mx[i] - sum[i]);
  }
  suf[siz] = mx[siz];
  tmp = mx[siz];
  for (int i = siz - 1; i > 0; i--) {
    suf[i] = max(suf[i + 1], mx[i] + tmp + sum[siz] - sum[i]);
    tmp = max(tmp, mx[i] - sum[siz] + sum[i]);
  }
  pre2[1] = mx[1];
  for (int i = 2; i <= siz; i++) {
    pre2[i] = max(mx[i] + sum[i], pre2[i - 1]);
  }
  suf2[siz] = mx[siz];
  for (int i = siz - 1; i > 0; i--) {
    suf2[i] = max(suf2[i + 1], mx[i] + sum[siz] - sum[i]);
  }
  ans = max(dia, pre[siz]);
  for (int i = 1; i < siz; i++) {
    long long r = max(pre[i], suf[i + 1]);
    r = max(r, pre2[i] + suf2[i + 1] + wght[siz]);
    r = max(dia, r);
    ans = min(ans, r);
  }
  printf("%lld\n", ans);
}
