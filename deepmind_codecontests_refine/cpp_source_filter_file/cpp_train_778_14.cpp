#include <bits/stdc++.h>
using namespace std;
int read() {
  int s = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * t;
}
struct Edge {
  int x, y, c, v;
} p[501000];
int n, m;
struct edge {
  int to, lt;
} e[501000 << 1];
int in[501000], cnt, poi;
void add(int x, int y) {
  e[++cnt].to = y;
  e[cnt].lt = in[x];
  in[x] = cnt;
}
stack<int> st;
int dfn[501000], tms, low[501000];
bool ins[501000];
int col[501000], cl;
vector<int> v[501000], tmp;
void tarjan(int x) {
  st.push(x);
  dfn[x] = low[x] = ++tms;
  ins[x] = 1;
  for (int i = in[x]; i; i = e[i].lt) {
    int y = e[i].to;
    if (dfn[y]) {
      if (ins[y]) low[x] = min(dfn[y], low[y]);
    } else {
      tarjan(y);
      low[x] = min(low[x], low[y]);
    }
  }
  if (low[x] == dfn[x]) {
    int w;
    ++cl;
    do {
      w = st.top();
      col[w] = cl;
      ins[w] = 0;
      st.pop();
    } while (w != x);
  }
}
void workp(vector<int> tmp) {
  int ls, lcs;
  for (int i = 0; i < tmp.size(); i++) {
    int x = tmp[i], cx = tmp[i] + m, s = ++poi, cs = ++poi;
    add(x, s);
    add(cs, cx);
    if (i) add(ls, cx), add(x, lcs), add(ls, s), add(cs, lcs);
    ls = s, lcs = cs;
  }
}
void workc(vector<int> tmp) {
  int ls, lcs;
  for (int i = 0; i < tmp.size(); i++) {
    int x = tmp[i], cx = tmp[i] + m, s = ++poi, cs = ++poi;
    add(s, x);
    add(cx, cs);
    if (i) add(cx, ls), add(lcs, x), add(s, ls), add(lcs, cs);
    ls = s, lcs = cs;
  }
}
bool cmp(int x, int y) { return p[x].c < p[y].c; }
int remin[501000], remcnt;
void redo(int val) {
  cnt = remcnt;
  for (int i = 1; i <= m; i++)
    if (p[i].v > val) in[i] = remin[i];
}
bool check(int val) {
  remcnt = cnt;
  for (int i = 1; i <= m; i++)
    if (p[i].v > val) remin[i] = in[i], add(i, i + m);
  memset(dfn, 0, poi + 1 << 2);
  tms = 0;
  cl = 0;
  for (int i = 1; i <= poi; i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= m; i++)
    if (col[i] == col[i + m]) return redo(val), 0;
  return redo(val), 1;
}
vector<int> ans;
int main() {
  n = read(), m = read();
  poi = 2 * m;
  for (int i = 1; i <= m; i++)
    p[i].x = read(), p[i].y = read(), p[i].c = read(), p[i].v = read(),
    v[p[i].x].push_back(i), v[p[i].y].push_back(i);
  for (int i = 1; i <= n; i++) {
    sort(v[i].begin(), v[i].end(), cmp);
    workp(v[i]);
    for (int j = 0, k; j < v[i].size(); j = k) {
      tmp.clear();
      for (k = j; k < v[i].size() && p[v[i][k]].c == p[v[i][j]].c; k++)
        tmp.push_back(v[i][k]);
      workc(tmp);
    }
  }
  if (!check(1e9)) return puts("No"), 0;
  int l = 1, r = 1e9;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  check(l);
  for (int i = 1; i <= m; i++)
    if (col[i] < col[i + m]) ans.push_back(i);
  puts("Yes");
  printf("%d %d\n", l, ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  return 0;
}
