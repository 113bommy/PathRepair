#include <bits/stdc++.h>
using namespace std;
const int maxn = 333333, maxm = 1111111, mod = 998244353;
template <typename T>
inline void read(T &x) {
  x = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (f) x = -x;
}
int n, m, q, a[maxn], pr[maxn], pl, mn[maxm], fa[maxn], id[maxn], at[maxm];
bool vis[maxm];
map<pair<int, int>, bool> mp;
inline int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
inline void unite(int x, int y) {
  x = getfa(x);
  y = getfa(y);
  if (x != y) fa[x] = y;
}
inline bool check(int x, int y) {
  x = getfa(x);
  y = getfa(y);
  return x == y;
}
int main() {
  read(n);
  read(q);
  for (int i = (1); i <= (n); i++) read(a[i]), m = max(m, a[i] + 1);
  for (int i = (2); i <= (m); i++) {
    if (!vis[i]) pr[++pl] = i, at[i] = pl + n, mn[i] = i;
    for (int j = (1); j <= (pl); j++) {
      if (i * pr[j] > m) break;
      vis[i * pr[j]] = true;
      mn[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) break;
    }
  }
  for (int i = (1); i <= (n + pl); i++) fa[i] = i;
  for (int i = (1); i <= (n); i++) {
    int x = a[i];
    while (x != 1) unite(i, at[mn[x]]), x /= mn[x];
  }
  for (int i = (1); i <= (n + pl); i++) id[i] = getfa(i);
  for (int i = (1); i <= (n); i++) {
    int x = a[i], tmp[111], tl = 0;
    while (x != 1) tmp[++tl] = id[at[mn[x]]], x /= mn[x];
    x = a[i] + 1;
    while (x != 1) tmp[++tl] = id[at[mn[x]]], x /= mn[x];
    sort(tmp + 1, tmp + tl + 1);
    tl = unique(tmp + 1, tmp + tl + 1) - tmp - 1;
    for (int j = (1); j <= (tl); j++)
      for (int k = (1); k <= (tl); k++) mp[make_pair(tmp[j], tmp[k])] = true;
  }
  while (q--) {
    int s, t;
    read(s);
    read(t);
    s = id[s];
    t = id[t];
    if (s == t)
      puts("0");
    else if (mp[make_pair(s, t)])
      puts("1");
    else
      puts("2");
  }
}
