#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
set<int> g[N];
bool fl[N];
int n, m, sum, w[N], pot[N], siz[N], ch[N][2], lt[N], rt[N], val[N], tag[N],
    pos[N], opt[N], ans[N];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
inline void build(int l, int r, int t) {
  lt[t] = l, rt[t] = r;
  if (l == r) {
    ch[t][0] = ch[t][1] = l, pot[l] = t;
    return;
  }
  int d = (l + r) >> 1;
  build(l, d, t << 1), build(d + 1, r, t << 1 | 1);
}
inline void pushdown(int u) {
  tag[u << 1] += tag[u], tag[u << 1 | 1] += tag[u];
  opt[u << 1] += tag[u], opt[u << 1 | 1] += tag[u], tag[u] = 0;
}
inline void update(int u) {
  u = u >> 1;
  while (u > 0) val[u] = max(val[u << 1], val[u << 1 | 1]), u = u >> 1;
}
inline void getmax(int l, int r, int t) {
  if (l > r) return;
  if (lt[t] == l && rt[t] == r) {
    sum = max(sum, val[t]);
    return;
  }
  int d = (lt[t] + rt[t]) >> 1;
  if (l <= d) getmax(l, min(d, r), t << 1);
  if (d + 1 <= r) getmax(max(d + 1, l), r, t << 1 | 1);
}
inline void updatex(int t) {
  if (opt[t << 1] < opt[t << 1 | 1]) {
    opt[t] = opt[t << 1], ch[t][0] = ch[t << 1][0];
    ch[t][1] = ch[t << 1][1], ans[t] = ans[t << 1];
  }
  if (opt[t << 1] > opt[t << 1 | 1]) {
    opt[t] = opt[t << 1 | 1], ch[t][0] = ch[t << 1 | 1][0];
    ch[t][1] = ch[t << 1 | 1][1], ans[t] = ans[t << 1 | 1];
  }
  if (opt[t << 1] == opt[t << 1 | 1]) {
    opt[t] = opt[t << 1], ch[t][0] = ch[t << 1][0],
    ch[t][1] = ch[t << 1 | 1][1];
    sum = 0, getmax(ch[t << 1][1] + 1, ch[t << 1 | 1][0], 1);
    ans[t] = ans[t << 1] + ans[t << 1 | 1] + sum;
  }
}
inline void adds(int l, int r, int t, int c) {
  if (l > r) return;
  pushdown(t);
  if (l == lt[t] && r == rt[t]) {
    opt[t] += c, tag[t] += c;
    return;
  }
  int d = (lt[t] + rt[t]) >> 1;
  if (l <= d) adds(l, min(d, r), t << 1, c);
  if (d + 1 <= r) adds(max(d + 1, l), r, t << 1 | 1, c);
  updatex(t);
}
inline void updatec(int u, int t) {
  pushdown(t);
  int d = (lt[t] + rt[t]) >> 1;
  if (lt[t] == rt[t]) return;
  if (u <= d)
    updatec(u, t << 1);
  else
    updatec(u, t << 1 | 1);
  updatex(t);
}
inline void print_ans() {
  int a = ch[1][0], b = ch[1][1], opt = ans[1];
  sum = 0, getmax(1, a, 1), opt += sum;
  sum = 0, getmax(b + 1, n, 1), opt += sum;
  printf("%d\n", n - opt);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) w[i] = read(), g[w[i]].insert(i), siz[w[i]]++;
  build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    if (fl[w[i]]) continue;
    fl[w[i]] = 1;
    val[pot[*g[w[i]].begin()]] = siz[w[i]];
    update(pot[*g[w[i]].begin()]);
    adds(*g[w[i]].begin(), (*g[w[i]].rbegin()) - 1, 1, 1);
  }
  for (int i = 1; i <= n; i++) updatec(i, 1);
  print_ans();
  int u, t;
  for (int i = 1; i <= m; i++) {
    u = read(), t = read();
    val[pot[*g[w[u]].begin()]] = 0;
    update(pot[*g[w[u]].begin()]);
    adds(*g[w[u]].begin(), (*g[w[u]].rbegin()) - 1, 1, -1);
    updatec(*g[w[u]].begin(), 1);
    g[w[u]].erase(u), siz[w[u]]--;
    if (siz[w[u]]) {
      val[pot[*g[w[u]].begin()]] = siz[w[u]];
      update(pot[*g[w[u]].begin()]);
      adds(*g[w[u]].begin(), (*g[w[u]].rbegin()) - 1, 1, 1);
      updatec(*g[w[u]].begin(), 1);
    }
    w[u] = t;
    if (siz[w[u]]) {
      val[pot[*g[w[u]].begin()]] = 0;
      update(pot[*g[w[u]].begin()]);
      adds(*g[w[u]].begin(), (*g[w[u]].rbegin()) - 1, 1, -1);
      updatec(*g[w[u]].begin(), 1);
    }
    g[w[u]].insert(u), siz[w[u]]++;
    val[pot[*g[w[u]].begin()]] = siz[w[u]];
    update(pot[*g[w[u]].begin()]);
    adds(*g[w[u]].begin(), (*g[w[u]].rbegin()) - 1, 1, 1);
    updatec(*g[w[u]].begin(), 1);
    print_ans();
  }
  return 0;
}
