#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, inf = 2e9 + 10;
int n, Q, C, cnt;
int ans[N], cro[N], len[N];
pair<int, int> q[N];
set<int> st;
map<int, int> mp[N];
int read() {
  int ret = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) ret = ret * 10 + (c ^ 48), c = getchar();
  return ret;
}
void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}
void writeln(int x) {
  write(x);
  putchar('\n');
}
struct cloud {
  int l, r, c;
  cloud(int _l = 0, int _r = 0, int _c = 0) : l(_l), r(_r), c(_c) {}
  bool operator<(const cloud &rhs) const { return c < rhs.c; }
} cl[N];
struct node {
  int t, op, id;
  node(int _t = 0, int _o = 0, int _i = 0) : t(_t), op(_o), id(_i) {}
  bool operator<(const node &rhs) const { return t < rhs.t; }
} a[N];
void gmax(int &x, int y) { x = max(x, y); }
int calc(int x, int y) {
  if (x > y) swap(x, y);
  return len[x] + len[y] + mp[x][y];
}
struct Segment {
  int t[N << 2];
  void pushup(int x) { t[x] = max(t[(x << 1)], t[(x << 1 | 1)]); }
  void update(int x, int l, int r, int p, int w) {
    if (l == r) {
      t[x] = w;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      update((x << 1), l, mid, p, w);
    else
      update((x << 1 | 1), mid + 1, r, p, w);
    pushup(x);
  }
  int getpos(int x, int l, int r) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    return t[(x << 1)] > t[(x << 1 | 1)] ? getpos((x << 1), l, mid)
                                         : getpos((x << 1 | 1), mid + 1, r);
  }
  int cmax(int x, int y) { return len[x] > len[y] ? x : y; }
  int query(int x, int l, int r, int L, int R) {
    if (L <= l && r <= R) return getpos(x, l, r);
    int mid = (l + r) >> 1, res = 0;
    if (L <= mid) res = cmax(res, query((x << 1), l, mid, L, R));
    if (R > mid) res = cmax(res, query((x << 1 | 1), mid + 1, r, L, R));
    return res;
  }
} tr;
int main() {
  n = read();
  C = read();
  for (int i = 1; i <= n; ++i)
    cl[i].l = read(), cl[i].r = read(), cl[i].c = read();
  sort(cl + 1, cl + n + 1);
  cl[n + 1] = (cloud){0, 0, inf};
  for (int i = 1; i <= n; ++i)
    a[++cnt] = node(cl[i].l, 1, i), a[++cnt] = node(cl[i].r, -1, i);
  sort(a + 1, a + cnt + 1);
  a[++cnt] = node(inf, 1, n + 1);
  Q = read();
  for (int i = 1; i <= Q; ++i) q[i].first = read(), q[i].second = i;
  sort(q + 1, q + Q + 1);
  for (int i = 1, las = 0, pos = 1, sum = 0, del = 0; i <= cnt; ++i) {
    int L = a[i].t - las;
    las = a[i].t;
    if (st.empty())
      sum += L;
    else if (st.size() == 1) {
      int x = *st.begin();
      len[x] += L;
      cro[x] += L;
      tr.update(1, 1, n, x, len[x]);
      if (cl[x].c <= C) {
        int l = 1,
            r = upper_bound(cl + 1, cl + n + 1, cloud(0, 0, C - cl[x].c)) - cl -
                1,
            val = len[x];
        if (l <= x && x <= r) {
          if (l <= x - 1) gmax(val, calc(x, tr.query(1, 1, n, l, x - 1)));
          if (x + 1 <= r) gmax(val, calc(x, tr.query(1, 1, n, x + 1, r)));
        } else if (l <= r)
          gmax(val, calc(x, tr.query(1, 1, n, l, r)));
        gmax(cro[x], val);
        gmax(del, cro[x]);
      }
    } else if (st.size() == 2) {
      int x = *st.begin(), y = *st.rbegin();
      mp[x][y] += L;
      if (cl[x].c + cl[y].c <= C) {
        int tmp = calc(x, y);
        gmax(cro[x], tmp);
        gmax(cro[y], tmp);
        gmax(del, max(cro[x], cro[y]));
      }
    }
    for (; pos <= Q && del + sum >= q[pos].first; ++pos)
      ans[q[pos].second] = las - (del + sum - q[pos].first);
    if (a[i].op == 1)
      st.insert(a[i].id);
    else
      st.erase(a[i].id);
  }
  for (int i = 1; i <= Q; ++i) writeln(ans[i]);
  return 0;
}
