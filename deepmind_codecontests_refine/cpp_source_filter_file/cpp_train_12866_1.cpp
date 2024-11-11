#include <bits/stdc++.h>
using namespace std;
char *fs, *ft, buf[1 << 15];
inline char gc() {
  return (fs == ft &&
          (ft = (fs = buf) + fread(buf, 1, 1 << 15, stdin), fs == ft))
             ? 0
             : *fs++;
}
inline int read() {
  register int x = 0, f = 1;
  register char ch = gc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = gc();
  }
  return x * f;
}
const int MAXN = 400010;
int n, k, ans;
int vis[MAXN], c[MAXN], nex[MAXN];
int a[MAXN];
set<pair<int, int> > s;
set<pair<int, int> >::iterator it;
int main() {
  n = read();
  k = read();
  for (register int i = 1; i <= n; ++i) a[i] = read(), c[i] = n + 1;
  for (register int i = 1; i <= n; ++i) {
    nex[i] = c[a[i]];
    c[a[i]] = i;
  }
  for (register int i = 1; i <= n; ++i) {
    if (vis[a[i]]) {
      s.erase(make_pair(i, a[i]));
      s.insert(make_pair(nex[i], a[i]));
      continue;
    }
    if (s.size() >= k) {
      it = (--s.end());
      vis[(*it).second] = 0;
      s.erase(it);
    }
    s.insert(make_pair(nex[i], a[i]));
    vis[a[i]] = 1;
    ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
