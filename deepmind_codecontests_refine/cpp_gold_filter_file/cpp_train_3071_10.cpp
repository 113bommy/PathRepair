#include <bits/stdc++.h>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ') {
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
const int N = 5e5 + 5;
int n, m, f[N], g[N], fs[N], gs[N], ft[N], gt[N], cls[N];
vector<pair<int, long long> > s[N];
int find(int *p, int x) { return p[x] == x ? x : find(p, p[x]); }
void merge(int *p, int *s, int *t, int x, int y, int z) {
  x = find(p, x), y = find(p, y);
  if (s[x] > s[y]) swap(x, y);
  p[x] = y, s[y] += s[x], t[x] = z;
}
long long ask(vector<pair<int, long long> > &s, int t) {
  return s.back().second -
         (--lower_bound(s.begin(), s.end(), pair<int, long long>(t, 0)))
             ->second;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i)
    f[i] = g[i] = i, fs[i] = gs[i] = 1, s[i].emplace_back(-1, 0);
  for (int i = 1; i <= m; ++i) {
    char op[2];
    int x, y;
    scanf("%s", op);
    if (op[0] == 'U')
      x = read(), y = read(), merge(f, fs, ft, x, y, i);
    else if (op[0] == 'M')
      x = read(), y = read(), merge(g, gs, gt, x, y, i);
    else if (op[0] == 'A')
      x = read(), x = find(f, x),
      s[x].emplace_back(i, s[x].back().second + fs[x]);
    else if (op[0] == 'Z')
      x = read(), x = find(g, x), cls[x] = i;
    else {
      int x = read(), y, t = cls[x];
      for (y = x; g[y] != y; y = g[y])
        if (cls[g[y]] > gt[y]) t = max(t, cls[g[y]]);
      long long ans = ask(s[x], t);
      for (y = x; f[y] != y; y = f[y]) ans += ask(s[f[y]], max(t, ft[y]));
      printf("%lld\n", ans);
    }
  }
  return 0;
}
