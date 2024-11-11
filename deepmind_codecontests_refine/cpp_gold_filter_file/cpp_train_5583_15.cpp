#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;
int n, m, last;
int f[maxn], mx[maxn][11], mn[maxn][11], siz[maxn], nxt[maxn], v[11];
set<pair<int, int> > s[11];
set<pair<int, int> >::iterator it;
inline int rd() {
  int ret = 0, f = 1;
  char gc = getchar();
  while (gc < '0' || gc > '9') {
    if (gc == '-') f = -f;
    gc = getchar();
  }
  while (gc >= '0' && gc <= '9') ret = ret * 10 + (gc ^ '0'), gc = getchar();
  return ret * f;
}
int find(int x) { return (f[x] == x) ? x : (f[x] = find(f[x])); }
inline void merge(int a, int b) {
  for (int i = 1; i <= m; i++)
    mx[b][i] = max(mx[b][i], mx[a][i]), mn[b][i] = min(mn[b][i], mn[a][i]);
  siz[b] += siz[a], f[a] = b;
}
int main() {
  n = rd(), m = rd();
  int i, j, a, b, t;
  for (j = 1; j <= m; j++)
    s[j].insert(make_pair(mx[1][j] = mn[1][j] = rd(), 1));
  f[1] = siz[1] = last = 1;
  puts("1");
  for (i = 2; i <= n; i++) {
    a = b = 0;
    for (j = 1; j <= m; j++) {
      v[j] = rd();
      it = s[j].upper_bound(make_pair(v[j], i));
      if (it != s[j].end()) {
        t = find((*it).second);
        if (!b || mx[t][j] < mx[b][j]) b = t;
      }
      if (it != s[j].begin()) {
        it--, t = find((*it).second);
        if (!a || mx[t][j] > mx[a][j]) a = t;
      }
      s[j].insert(make_pair(v[j], i));
    }
    f[i] = i, siz[i] = 1;
    for (j = 1; j <= m; j++) mx[i][j] = mn[i][j] = v[j];
    if (!a)
      nxt[i] = b;
    else if (!b)
      last = i, nxt[a] = i;
    else if (a == b)
      merge(i, a);
    else if (mx[a][1] < mx[b][1])
      nxt[a] = i, nxt[i] = b;
    else {
      for (t = b; t != a; t = nxt[t], merge(t, b))
        ;
      merge(i, b);
      nxt[b] = nxt[a];
      if (a == last) last = b;
    }
    printf("%d\n", siz[last]);
  }
  return 0;
}
