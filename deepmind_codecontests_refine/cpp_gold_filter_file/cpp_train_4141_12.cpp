#include <bits/stdc++.h>
using namespace std;
inline pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
  if (!x.second) return y;
  if (!y.second) return x;
  if (x.first == y.first) return pair<int, int>(x.first, x.second + y.second);
  return (x.first < y.first) ? x : y;
}
namespace SGT {
long long sumv[500000], addv[500000];
pair<int, int> minv[500000], tag[500000];
void pushdown(int o) {
  if (tag[o].second) {
    if (minv[o * 2].first + tag[o].first == 0)
      sumv[o * 2] += (long long)minv[o * 2].second * tag[o].second;
    if (minv[o * 2 + 1].first + tag[o].first == 0)
      sumv[o * 2 + 1] += (long long)minv[o * 2 + 1].second * tag[o].second;
    tag[o * 2] = merge(
        tag[o * 2], pair<int, int>(tag[o].first + addv[o * 2], tag[o].second));
    tag[o * 2 + 1] =
        merge(tag[o * 2 + 1],
              pair<int, int>(tag[o].first + addv[o * 2 + 1], tag[o].second));
    minv[o * 2].first += addv[o];
    minv[o * 2 + 1].first += addv[o];
    addv[o * 2] += addv[o];
    addv[o * 2 + 1] += addv[o];
    addv[o] = 0;
    tag[o] = pair<int, int>(0, 0);
  }
}
void pushup(int o) {
  minv[o] = merge(minv[o * 2], minv[o * 2 + 1]);
  sumv[o] = sumv[o * 2] + sumv[o * 2 + 1];
}
void build(int l, int r, int o) {
  if (l == r)
    minv[o] = pair<int, int>(l, 1);
  else {
    int m = ((l + r) >> 1);
    build(l, m, o * 2);
    build(m + 1, r, o * 2 + 1);
    pushup(o);
  }
}
void update(int l, int r, int o, int lx, int rx, int p) {
  if (l >= lx && r <= rx) {
    if (minv[o].first + p == 0) sumv[o] += minv[o].second;
    tag[o] = merge(tag[o], pair<int, int>(p + addv[o], 1));
    minv[o].first += p;
    addv[o] += p;
  } else {
    pushdown(o);
    int m = ((l + r) >> 1);
    if (m >= lx) update(l, m, o * 2, lx, rx, p);
    if (m < rx) update(m + 1, r, o * 2 + 1, lx, rx, p);
    pushup(o);
  }
}
long long query(int l, int r, int o, int lx, int rx) {
  if (l >= lx && r <= rx)
    return sumv[o];
  else {
    pushdown(o);
    int m = ((l + r) >> 1);
    if (m >= rx) return query(l, m, o * 2, lx, rx);
    if (m < lx) return query(m + 1, r, o * 2 + 1, lx, rx);
    return query(l, m, o * 2, lx, rx) + query(m + 1, r, o * 2 + 1, lx, rx);
  }
}
}  // namespace SGT
struct Query {
  int l, r, id;
  Query() {}
  Query(int a, int b, int c) : l(a), r(b), id(c) {}
  bool operator<(const Query& b) const { return r < b.r; }
};
Query q[150000];
int num[150000];
long long ans[150000];
int st1[150000], st2[150000];
int top1, top2;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    q[i] = Query(x, y, i);
  }
  sort(q + 1, q + m + 1);
  SGT::build(1, n, 1);
  int lx = 1;
  for (int i = 1; i <= n; i++) {
    while (top1 && num[i] >= num[st1[top1]]) {
      SGT::update(1, n, 1, st1[top1 - 1] + 1, st1[top1],
                  num[i] - num[st1[top1]]);
      top1--;
    }
    st1[++top1] = i;
    while (top2 && num[i] <= num[st2[top2]]) {
      SGT::update(1, n, 1, st2[top2 - 1] + 1, st2[top2],
                  num[st2[top2]] - num[i]);
      top2--;
    }
    st2[++top2] = i;
    SGT::update(1, n, 1, 1, n, -1);
    while (lx <= m && q[lx].r <= i) {
      ans[q[lx].id] = SGT::query(1, n, 1, q[lx].l, q[lx].r);
      lx++;
    }
  }
  for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
  return 0;
}
