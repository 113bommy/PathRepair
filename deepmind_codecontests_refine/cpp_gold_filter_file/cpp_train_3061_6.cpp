#include <bits/stdc++.h>
using namespace std;
const int prime = 1000000007;
int n, m;
int d[60][60], l[60][60], r[60][60], vis[100000];
bool con[60][60];
void init() {
  scanf("%d%d", &n, &m);
  memset(d, 0, sizeof(d));
  memset(con, false, sizeof(con));
  memset(vis, 0, sizeof(vis));
  int top = 0;
  int i, j;
  for (i = 1; i <= (m); ++i) {
    int x, y, z, t;
    scanf("%d%d%d", &x, &y, &z);
    d[x][y] = z;
    con[x][y] = true;
    l[x][y] = top + 1;
    r[x][y] = top + z;
    for (j = 1; j <= (z); ++j) {
      scanf("%d", &t);
      vis[top + j] = t;
    }
    top += z;
  }
}
int ql, qr;
int q[1000];
void goback() {
  while (ql <= qr && qr <= 2 * n + 2) {
    int y = q[ql - 1];
    int x = q[ql++];
    if (!con[x][y]) {
      qr = ql + 1;
      return;
    }
    for (int p = r[x][y]; p >= l[x][y]; --p) q[++qr] = vis[p];
  }
}
void gofront() {
  while (ql <= qr && qr <= 2 * n + 2) {
    int x = q[ql - 1];
    int y = q[ql++];
    if (!con[x][y]) {
      qr = ql + 1;
      return;
    }
    for (int p = l[x][y]; p <= r[x][y]; ++p) q[++qr] = vis[p];
  }
}
int fullpath[60][60][120], prefix[60][60][120], suffix[60][60][120];
int ans[60];
vector<pair<int, int> > g1[60][60], g2[60][60], g3[60][60];
int f0[120][60], f1[120][60], s[60];
inline void update(int &x, int &y, int z) {
  x = (x + (long long)y * z) % prime;
}
void work() {
  int i, j, k, len;
  memset(fullpath, 0, sizeof(fullpath));
  memset(prefix, 0, sizeof(prefix));
  memset(suffix, 0, sizeof(suffix));
  for (i = 1; i <= (n); ++i)
    for (j = 1; j <= (n); ++j)
      for (k = l[i][j]; k <= (r[i][j] - 1); ++k)
        if (vis[k] == i && vis[k + 1] == j) {
          int len = 0;
          ql = 2;
          qr = 0;
          for (int p = k; p >= l[i][j]; --p) q[++qr] = vis[p];
          goback();
          int x = q[qr];
          len += qr;
          if (ql <= qr) continue;
          ql = 2;
          qr = 0;
          for (int p = k + 1; p <= r[i][j]; ++p) q[++qr] = vis[p];
          gofront();
          int y = q[qr];
          len += qr;
          if (ql <= qr) continue;
          fullpath[x][y][len]++;
        }
  for (i = 1; i <= (n); ++i)
    for (j = 1; j <= (n); ++j)
      if (vis[r[i][j]] == i && l[i][j] <= r[i][j]) {
        int len = 0;
        ql = 2;
        qr = 0;
        for (int p = r[i][j]; p >= l[i][j]; --p) q[++qr] = vis[p];
        goback();
        int x = q[qr];
        len += qr;
        if (ql <= qr) continue;
        prefix[x][j][len]++;
      }
  for (i = 1; i <= (n); ++i)
    for (j = 1; j <= (n); ++j)
      if (vis[l[i][j]] == j && l[i][j] <= r[i][j]) {
        int len = 0;
        ql = 2;
        qr = 0;
        for (int p = l[i][j]; p <= r[i][j]; ++p) q[++qr] = vis[p];
        gofront();
        int y = q[qr];
        len += qr;
        if (ql <= qr) continue;
        suffix[i][y][len]++;
      }
  for (i = 1; i <= (n); ++i)
    for (j = 1; j <= (n); ++j)
      for (k = 1; k <= (n * 2 + 1); ++k) {
        if (prefix[i][j][k] != 0)
          g1[i][j].push_back(make_pair(prefix[i][j][k], k));
        if (fullpath[i][j][k] != 0)
          g2[i][j].push_back(make_pair(fullpath[i][j][k], k));
        if (suffix[i][j][k] != 0)
          g3[i][j].push_back(make_pair(suffix[i][j][k], k));
      }
  memset(f0, 0, sizeof(f0));
  memset(f1, 0, sizeof(f1));
  for (i = 1; i <= (n); ++i) f0[0][i] = 1;
  vector<pair<int, int> >::iterator p;
  for (len = 0; len <= (n * 2); ++len) {
    memset(s, 0, sizeof(s));
    for (i = 1; i <= (n); ++i)
      for (j = 1; j <= (n); ++j) {
        for (p = g1[i][j].begin();
             p != g1[i][j].end() && p->second + len <= n * 2 + 1; ++p)
          update(f0[len + p->second][j], f0[len][i], p->first);
        for (p = g2[i][j].begin();
             p != g2[i][j].end() && p->second + len <= n * 2 + 1; ++p)
          update(f1[len + p->second][j], f0[len][i], p->first);
        for (p = g3[i][j].begin();
             p != g3[i][j].end() && p->second + len <= n * 2 + 1; ++p)
          update(f1[len + p->second][j], f1[len][i], p->first);
      }
    if (len == 0) continue;
    for (i = 1; i <= (n); ++i)
      for (j = 1; j <= (n); ++j)
        if (d[i][j] == 0 && con[i][j]) update(s[j], f1[len][i], 1);
    for (j = 1; j <= (n); ++j)
      for (k = 1; k <= (n); ++k) {
        for (p = g1[j][k].begin();
             p != g1[j][k].end() && p->second + len <= n * 2 + 1; ++p)
          update(f0[len + p->second][k], s[j], p->first);
        for (p = g2[j][k].begin();
             p != g2[j][k].end() && p->second + len <= n * 2 + 1; ++p)
          update(f1[len + p->second][k], s[j], p->first);
      }
  }
  memset(ans, 0, sizeof(ans));
  for (len = 2; len <= (n * 2 + 1); ++len)
    for (i = 1; i <= (n); ++i) update(ans[len - 1], f1[len][i], 1);
  for (i = 1; i <= (n * 2); ++i) printf("%d\n", ans[i]);
}
int main() {
  init();
  work();
  return 0;
}
