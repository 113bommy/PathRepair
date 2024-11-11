#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  do {
    s = s * 10 + c - '0';
  } while ((c = getchar()) >= '0' && c <= '9');
  return s;
}
const int N = 200010, W = 1000010, MO = 1000000007;
int n, m, k, tot, cx, cy, lx, bt;
struct eg {
  int x, b, t, l;
} e[N];
int lit, l2t;
pair<int, int> li[N], l2[N];
multiset<pair<int, int> > st;
namespace sg {
struct tn {
  int ls, rs, dt, cl;
} t[W + W];
int tot = 1, rt = 1, ql, qr, qv;
inline void pd(tn &o) {
  if (o.cl) o.cl = 0, t[o.ls].cl = t[o.rs].cl = 1, t[o.ls].dt = t[o.rs].dt = 0;
}
void change(int &p, int l, int r) {
  if (!p)
    p = ++tot;
  else
    pd(t[p]);
  if (l == r) {
    t[p].dt = qv;
    return;
  }
  int m = (l + r) >> 1;
  if (ql <= m)
    change(t[p].ls, l, m);
  else
    change(t[p].rs, m + 1, r);
  t[p].dt = (t[t[p].ls].dt + t[t[p].rs].dt) % MO;
}
void clr(int p, int l, int r) {
  if (!p) return;
  pd(t[p]);
  if (ql <= l && r <= qr) {
    t[p].dt = 0;
    t[p].cl = 1;
    return;
  }
  int m = (l + r) >> 1;
  if (ql <= m) clr(t[p].ls, l, m);
  if (qr > m) clr(t[p].rs, m + 1, r);
  t[p].dt = (t[t[p].ls].dt + t[t[p].rs].dt) % MO;
}
int query(int p, int l, int r) {
  if (!p) return 0;
  pd(t[p]);
  if (ql <= l && r <= qr) return t[p].dt;
  int m = (l + r) >> 1, s = 0;
  if (ql <= m) s += query(t[p].ls, l, m);
  if (qr > m) s += query(t[p].rs, m + 1, r);
  return s % MO;
}
inline int query(int l, int r) {
  if (l > r) return 0;
  ql = l, qr = r;
  return query(rt, 1, m);
}
inline void change(int l, int v) {
  ql = l, qv = v;
  change(rt, 1, m);
}
inline void clr(int l, int r) {
  ql = l, qr = r;
  clr(rt, 1, m);
}
}  // namespace sg
bool cmp(const eg &a, const eg &b) {
  if (a.x != b.x) return a.x < b.x;
  if (a.l != b.l) return a.l < b.l;
  return a.b < b.b;
}
void printst() {
  printf("[%d]: ", st.size());
  for (multiset<pair<int, int> >::iterator it = st.begin(); it != st.end();
       it++)
    printf("(%d,%d) ", it->first, it->second);
  puts("");
}
int main() {
  int i, cnt;
  n = read();
  m = read();
  k = read();
  for (i = 1; i <= k; i++) {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();
    e[++tot].x = x1, e[tot].b = y1, e[tot].t = y2, e[tot].l = 0;
    e[++tot].x = x2 + 1, e[tot].b = y1, e[tot].t = y2, e[tot].l = 1;
  }
  sort(e + 1, e + 1 + tot, cmp);
  sg::change(1, 1);
  st.insert(make_pair(0, 0));
  for (i = 1; i <= tot; i++) {
    if (e[i].x != cx) {
      for (int i = 1; i <= l2t; i++)
        sg::change(l2[i].first,
                   (sg::query(l2[i].first, l2[i].first) + l2[i].second) % MO);
      for (int i = 1; i <= lit; i++)
        sg::clr(li[i].first, li[i].second), st.insert(li[i]);
      cx = e[i].x, lit = l2t = 0;
      if (cx > n) break;
    }
    cy = e[i].t;
    if (e[i].l == 0) {
      if (cy < m && (e[i + 1].x != cx || e[i + 1].b != cy + 1 || e[i + 1].l)) {
        multiset<pair<int, int> >::iterator it =
            st.upper_bound(make_pair(cy + 1, m));
        it--;
        cnt = (cx == 1) ? 0 : sg::query(it->first + 1, cy);
        l2[++l2t] = make_pair(cy + 1, cnt);
      }
      li[++lit] = make_pair(e[i].b, e[i].t);
    } else
      st.erase(st.find(make_pair(e[i].b, e[i].t)));
  }
  multiset<pair<int, int> >::iterator it = st.end();
  it--;
  printf("%d\n", sg::query(it->first + 1, m));
  return 0;
}
