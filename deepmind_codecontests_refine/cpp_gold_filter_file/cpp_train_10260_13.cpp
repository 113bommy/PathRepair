#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 7;
const long long linf = 1ll << 60;
const double dinf = 1e10;
template <typename T>
inline void scf(T &x) {
  bool f = 0;
  x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return;
}
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) {
  scf(x);
  return scf(y);
}
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) {
  scf(x);
  scf(y);
  return scf(z);
}
template <typename T1, typename T2, typename T3, typename T4>
void scf(T1 &x, T2 &y, T3 &z, T4 &w) {
  scf(x);
  scf(y);
  scf(z);
  return scf(w);
}
const int N = 1e5 + 100;
const int B = 350;
int n, q_n;
int a[N];
int cnt[N], apr[N], lst[N], nxt[N];
pair<int, int> qa[N], qb[N];
int fa, fb, ra, rb;
int ans[N];
struct Q {
  int i, l, r;
  Q() {}
  Q(int _I, int _L, int _R) : i(_I), l(_L), r(_R) {}
} q[N];
inline void link(const int &x, const int &l, const int &n) {
  lst[x] = l;
  nxt[x] = n;
  if (l != -1) nxt[l] = x;
  if (n != -1) lst[n] = x;
  return;
}
inline void ins(const int &x) {
  --cnt[apr[x]];
  int l = apr[x], n = nxt[l];
  if (!cnt[apr[x]]) {
    l = lst[l];
    if (l != -1) nxt[l] = n;
    if (n != -1) lst[n] = l;
  }
  ++apr[x];
  if (!cnt[apr[x]]) link(apr[x], l, n);
  ++cnt[apr[x]];
  return;
}
inline void del(const int &x) {
  --cnt[apr[x]];
  int n = apr[x], l = lst[n];
  if (!cnt[apr[x]]) {
    n = nxt[n];
    if (l != -1) nxt[l] = n;
    if (n != -1) lst[n] = l;
  }
  --apr[x];
  if (!cnt[apr[x]]) link(apr[x], l, n);
  ++cnt[apr[x]];
  return;
}
inline long long solve() {
  fa = fb = ra = rb = 0;
  for (int i = nxt[0]; ~i; i = nxt[i]) qa[ra++] = {i, cnt[i]};
  long long ret = 0;
  for (;;) {
    bool f1 = (fa == ra), f2 = (fb == rb);
    if (f1 && f2) break;
    if (f1) {
      pair<int, int> t = qb[fb];
      if (t.second == 1) {
        pair<int, int> tt = qb[++fb];
        if (fb == rb) break;
        ret += (long long)(t.first + tt.first);
        qb[fb].second--;
        if (!qb[fb].second) ++fb;
        qb[rb++] = {t.first + tt.first, 1};
      } else {
        if (~t.second & 1)
          ++fb;
        else
          qb[fb].second = 1;
        t.second >>= 1;
        ret += 2ll * t.second * t.first;
        qb[rb++] = {t.first + t.first, t.second};
      }
    } else if (f2) {
      pair<int, int> t = qa[fa];
      if (t.second == 1) {
        pair<int, int> tt = qa[++fa];
        if (fa == ra) break;
        ret += (long long)(t.first + tt.first);
        qa[fa].second--;
        if (!qa[fa].second) ++fa;
        qb[rb++] = {t.first + tt.first, 1};
      } else {
        if (~t.second & 1)
          ++fa;
        else
          qa[fa].second = 1;
        t.second >>= 1;
        ret += 2ll * t.second * t.first;
        qb[rb++] = {t.first + t.first, t.second};
      }
    } else {
      pair<int, int> ta = qa[fa], tb = qb[fb];
      if (ta.first < tb.first) {
        if (ta.second == 1) {
          pair<int, int> t = qa[++fa];
          if (fa == ra || t.first > tb.first) {
            ret += (long long)(ta.first + tb.first);
            qb[fb].second--;
            if (!qb[fb].second) ++fb;
            qb[rb++] = {ta.first + tb.first, 1};
          } else {
            ret += (long long)(ta.first + t.first);
            qa[fa].second--;
            if (!qa[fa].second) ++fa;
            qb[rb++] = {ta.first + t.first, 1};
          }
        } else {
          if (~ta.second & 1)
            fa++;
          else
            qa[fa].second = 1;
          ta.second >>= 1;
          ret += 2ll * ta.second * ta.first;
          qb[rb++] = {ta.first + ta.first, ta.second};
        }
      } else {
        if (tb.second == 1) {
          pair<int, int> t = qb[++fb];
          if (fb == rb || t.first > ta.first) {
            ret += (long long)(ta.first + tb.first);
            qa[fa].second--;
            if (!qa[fa].second) ++fa;
            qb[rb++] = {ta.first + tb.first, 1};
          } else {
            ret += (long long)(tb.first + t.first);
            qb[fb].second--;
            if (!qb[fb].second) ++fb;
            qb[rb++] = {tb.first + t.first, 1};
          }
        } else {
          if (~tb.second & 1)
            fb++;
          else
            qb[fb].second = 1;
          tb.second >>= 1;
          ret += 2ll * tb.second * tb.first;
          qb[rb++] = {tb.first + tb.first, tb.second};
        }
      }
    };
  }
  return ret;
}
int main() {
  scf(n);
  for (int i = (1); i <= (n); i++) scf(a[i]);
  scf(q_n);
  for (int i = (1); i <= (q_n); i++) {
    int l, r;
    scf(l, r);
    q[i] = Q{i, l, r};
  }
  sort(q + 1, q + q_n + 1,
       [&](Q a, Q b) { return a.l / B == b.l / B ? a.r < b.r : a.l < b.l; });
  cnt[0] = n;
  memset((lst), (-1), sizeof((lst)));
  memset((nxt), (-1), sizeof((nxt)));
  int l = q[1].l, r = q[1].r;
  ;
  ;
  for (int i = (l); i <= (r); i++) ins(a[i]);
  ans[q[1].i] = solve();
  for (int i = (2); i <= (q_n); i++) {
    int &tl = q[i].l, &tr = q[i].r;
    while (l < tl) del(a[l++]);
    while (r > tr) del(a[r--]);
    while (l > tl) ins(a[--l]);
    while (r < tr) ins(a[++r]);
    ;
    ;
    ans[q[i].i] = solve();
  }
  for (int i = (1); i <= (q_n); i++) printf("%d\n", ans[i]);
  return 0;
}
