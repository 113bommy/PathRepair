#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[1 << 19];
int s[1 << 19], d[1 << 19], r[1 << 19];
int f[1 << 22], w;
int n;
void dfs2(int x, int m, int dd, int& r) {
  if (f[m] >= 0) r = max(r, f[m] + d[x] - dd);
  for (int i = 0, ThxDem = 22; i < ThxDem; ++i) {
    int m2 = m ^ (1 << i);
    if (f[m2] >= 0) r = max(r, f[m2] + d[x] - dd);
  }
  for (auto p : g[x]) {
    int y = p.first, c = p.second;
    dfs2(y, m ^ (1 << c), dd, r);
  }
}
void dfs3(int x, int m) {
  f[m] = max(f[m], d[x]);
  for (auto p : g[x]) {
    int y = p.first, c = p.second;
    dfs3(y, m ^ (1 << c));
  }
}
void dfs4(int x, int m) {
  f[m] = -1;
  for (auto p : g[x]) {
    int y = p.first, c = p.second;
    dfs4(y, m ^ (1 << c));
  }
}
void dfs0(int x) {
  s[x] = 1;
  for (auto p : g[x]) d[p.first] = d[x] + 1, dfs0(p.first), s[x] += s[p.first];
}
void dfs1(int x, bool clear = true) {
  if (!((int)(g[x]).size())) {
    if (!clear) f[w] = max(f[w], d[x]);
    return;
  }
  int z = g[x][0].first, zc = g[x][0].second;
  for (auto p : g[x])
    if (s[p.first] > s[z]) z = p.first, zc = p.second;
  for (auto p : g[x])
    if (p.first != z) dfs1(p.first), r[x] = max(r[x], r[p.first]);
  dfs1(z, false);
  r[x] = max(r[x], r[z]);
  w ^= 1 << zc;
  r[x] = max(r[x], f[w] - d[x]);
  for (int i = 0, ThxDem = 22; i < ThxDem; ++i) {
    int m = w ^ (1 << i);
    if (f[m] >= 0) r[x] = max(r[x], f[m] - d[x]);
  }
  f[w] = max(f[w], d[x]);
  for (auto p : g[x]) {
    int y = p.first, c = p.second;
    if (y == z) continue;
    dfs2(y, w ^ (1 << c), d[x], r[x]);
    dfs3(y, w ^ (1 << c));
  }
  if (clear) dfs4(x, w);
}
int main() {
  scanf("%d", &n);
  for (int i = 1, ThxDem = n; i < ThxDem; ++i) {
    int p;
    char s[4];
    scanf("%d%s", &p, s);
    p--;
    g[p].push_back(make_pair(i, s[0] - 'a'));
  }
  memset(f, -1, sizeof(f));
  dfs0(0);
  dfs1(0);
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    printf("%d%c", r[i], " \n"[i == n - 1]);
  return 0;
}
