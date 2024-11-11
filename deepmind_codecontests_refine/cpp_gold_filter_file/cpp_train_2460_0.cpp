#include <bits/stdc++.h>
using namespace std;
int p[1 << 16];
int comp[2][1 << 14];
char s[1 << 14];
bool g[2][1 << 14];
int find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}
int seen[1 << 16], sid;
int mp[1 << 16];
int main() {
  int R, C;
  scanf("%d%d", &R, &C);
  int last = 0;
  int res = 0;
  for (int i = 0; i < R; ++i) {
    scanf("%s", s);
    int idx = 0;
    if (0) {
      for (int j = 0; j < C; ++j) g[i & 1][idx++] = s[j] == '1';
    } else {
      for (int j = 0; s[j]; ++j) {
        int val = s[j] >= 'A' ? s[j] - 'A' + 10 : s[j] - '0';
        for (int j = 3; j >= 0; --j) g[i & 1][idx++] = (val >> j) & 1;
      }
    }
    for (int j = 0; j < C; ++j) {
      if (g[i & 1][j]) {
        if (j && g[i & 1][j - 1])
          comp[i & 1][j] = comp[i & 1][j - 1];
        else
          comp[i & 1][j] = last++;
      }
    }
    if (i) {
      for (int k = 0; k < last; ++k) p[k] = k;
      for (int j = 0; j < C; ++j)
        if (g[i & 1][j] && g[1 & ~i][j])
          p[find(comp[1 & ~i][j])] = find(comp[i & 1][j]);
      ++sid;
      for (int j = 0; j < C; ++j)
        if (g[i & 1][j]) seen[find(comp[1 & i][j])] = sid;
      for (int j = 0; j < C; ++j)
        if (g[1 & ~i][j] && seen[find(comp[1 & ~i][j])] != sid) {
          seen[find(comp[1 & ~i][j])] = sid;
          ++res;
        }
      ++sid;
      int nid = 0;
      for (int j = 0; j < C; ++j)
        if (g[i & 1][j]) {
          int x = find(comp[1 & i][j]);
          if (seen[x] != sid) {
            seen[x] = sid;
            mp[x] = nid++;
          }
          comp[i & 1][j] = mp[x];
        }
      last = nid;
    }
  }
  bool cur = (R - 1) & 1;
  ++sid;
  for (int i = 0; i < C; ++i)
    if (g[cur][i]) {
      int x = comp[cur][i];
      if (seen[x] != sid) {
        seen[x] = sid;
        ++res;
      }
    }
  printf("%d\n", res);
  return 0;
}
