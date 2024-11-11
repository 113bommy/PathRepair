#include <bits/stdc++.h>
using namespace std;
const int SIZE = 200010;
const long long INF = 1e17;
struct data {
  long long v, c;
  data(long long _v = 0, long long _c = 0) : v(_v), c(_c) {}
  bool operator<(const data& b) const {
    return c < b.c || (c == b.c && v > b.v);
  }
  void scan() { scanf("%I64d%I64d", &v, &c); }
} a[SIZE];
long long S;
struct Line {
  long long x, y;
  long long v;
  Line(long long _x = 0, long long _y = 0, int _v = 0) : x(_x), y(_y), v(_v) {}
  long long inter(const Line& b) {
    long long ll, rr;
    ll = b.x;
    rr = (INF - b.y) / b.v;
    while (ll < rr) {
      long long mm = (ll + rr) >> 1;
      if (b.y + (mm - b.x) * b.v >= y + (mm - x) * v)
        rr = mm;
      else
        ll = mm + 1;
    }
    return ll;
  }
} ss[SIZE];
long long over_pos[SIZE];
int sn;
void add_line(pair<long long, long long> st, int v) {
  if (st.second >= INF) return;
  if (sn == 0) {
    ss[sn++] = Line(st.first, st.second, v);
  } else {
    Line now = Line(st.first, st.second, v);
    while (sn > 1 && ss[sn - 1].inter(now) <= over_pos[sn - 1]) {
      sn--;
    }
    over_pos[sn] = ss[sn - 1].inter(now);
    if (over_pos[sn] < INF) ss[sn++] = now;
  }
}
pair<long long, long long> get_time(long long t) {
  int ll = 0, rr = sn - 1;
  while (ll < rr) {
    int mm = (ll + rr) >> 1;
    if (ss[mm].y + (over_pos[mm + 1] - 1 - ss[mm].x) * ss[mm].v < t)
      ll = mm + 1;
    else
      rr = mm;
  }
  if (ss[ll].y >= t) return make_pair(ss[ll].x, ss[ll].y - t);
  long long need = (t - ss[ll].y + ss[ll].v - 1) / ss[ll].v;
  return make_pair(ss[ll].x + need, ss[ll].y + ss[ll].v * need - t);
}
int main() {
  int n;
  scanf("%d%I64d", &n, &S);
  for (int i = 0; i < (n); ++i) {
    a[i].scan();
  }
  sort(a, a + n);
  int now = a[0].v;
  add_line(make_pair(0LL, 0LL), a[0].v);
  for (int i = 1; i < n; i++) {
    if (a[i].v <= now) continue;
    pair<long long, long long> t = get_time(a[i].c);
    add_line(t, a[i].v);
    now = max((long long)now, a[i].v);
  }
  pair<long long, long long> an = get_time(S);
  printf("%I64d\n", an.first);
  return 0;
}
