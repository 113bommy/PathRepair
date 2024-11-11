#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  bool p = 0;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') p = 1;
  for (; c >= '0' && c <= '9'; c = getchar())
    x = (x << 3) + (x << 1) + (c ^ 48);
  if (p) x = -x;
}
unordered_map<int, int> mp;
const int N = 100005;
int a[N], f[105][N << 1], g[105][N << 1];
int val[N << 1], cnt, blk[N];
int st[505], ed[505];
int n, m;
int sz, tot;
int find(int x) {
  if (!mp[x]) {
    ++cnt;
    mp[x] = cnt;
    val[cnt] = x;
  }
  return mp[x];
}
int main() {
  read(n);
  sz = 1000;
  for (int i = 1, x; i <= n; ++i) {
    blk[i] = (i - 1) / sz + 1;
    if (blk[i] != blk[i - 1]) {
      st[blk[i]] = i;
      ed[blk[i] - 1] = i - 1;
    }
    read(x);
    a[i] = find(x);
  }
  ed[blk[n]] = n;
  tot = blk[n];
  st[tot + 1] = n + 1;
  for (int i = 1; i <= tot; ++i) {
    for (int j = 0; j < (N << 1); ++j) {
      f[i][j] = f[i - 1][j];
      g[i][j] = g[i - 1][j];
    }
    for (int j = st[i]; j <= ed[i]; ++j) {
      ++f[i][a[j]];
      ++g[i][f[i][a[j]]];
    }
  }
  read(m);
  for (int i = 1, opt, x, y; i <= m; ++i) {
    read(opt);
    read(x);
    read(y);
    if (opt == 2) {
      if (x == 1) {
        printf("%d\n", val[a[y]]);
      } else {
        int pos = upper_bound(ed + 1, ed + tot + 1, y) - ed - 1;
        for (int j = st[pos + 1]; j <= y; ++j) {
          ++f[pos][a[j]];
          ++g[pos][f[pos][a[j]]];
        }
        if (x & 1)
          printf("%d\n", g[pos][f[pos][a[y]]]);
        else
          printf("%d\n", f[pos][a[y]]);
        for (int j = st[pos + 1]; j <= y; ++j) {
          --g[pos][f[pos][a[j]]];
          --f[pos][a[j]];
        }
      }
    } else {
      swap(x, y);
      for (int j = blk[x]; j <= tot; ++j) {
        --g[j][f[j][a[x]]];
        --f[j][a[x]];
      }
      a[x] = find(y);
      for (int j = blk[x]; j <= tot; ++j) {
        ++f[j][a[x]];
        ++g[j][f[j][a[x]]];
      }
    }
  }
  return 0;
}
