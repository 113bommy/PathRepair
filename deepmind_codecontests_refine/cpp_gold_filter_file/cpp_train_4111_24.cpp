#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int INF = 1e9;
int N, p[MAXN], tag[MAXN << 2];
long long ans;
struct node {
  int mn, cnt;
  node(int mn = 0, int cnt = 0) : mn(mn), cnt(cnt) {}
  friend node operator+(const node& l, const node& r) {
    if (l.mn < r.mn)
      return l;
    else if (l.mn > r.mn)
      return r;
    else
      return node(l.mn, l.cnt + r.cnt);
  }
} t[MAXN << 2];
void pushup(int o) { t[o] = t[(o << 1)] + t[(o << 1 | 1)]; }
void add(int o, int k) { t[o].mn += k, tag[o] += k; }
void pushdown(int o) {
  if (tag[o]) add((o << 1), tag[o]), add((o << 1 | 1), tag[o]), tag[o] = 0;
}
void build(int o, int l, int r) {
  if (l == r)
    t[o] = node(0, 1);
  else
    build((o << 1), l, ((l + r) >> 1)),
        build((o << 1 | 1), ((l + r) >> 1) + 1, r), pushup(o);
}
void ins(int o, int l, int r, int L, int R, int K) {
  if (r < L || l > R) return;
  if (L <= l && r <= R) return add(o, K);
  pushdown(o);
  ins((o << 1), l, ((l + r) >> 1), L, R, K),
      ins((o << 1 | 1), ((l + r) >> 1) + 1, r, L, R, K);
  pushup(o);
}
node qry(int o, int l, int r, int L, int R) {
  if (r < L || l > R) return node(INF, 0);
  if (L <= l && r <= R) return t[o];
  pushdown(o);
  return qry((o << 1), l, ((l + r) >> 1), L, R) +
         qry((o << 1 | 1), ((l + r) >> 1) + 1, r, L, R);
}
int s1[MAXN], l1, s2[MAXN], l2;
int main() {
  scanf("%d", &N);
  int x, y;
  for (int i = 1; i <= N; ++i) scanf("%d%d", &x, &y), p[x] = y;
  build(1, 1, N);
  s1[0] = s2[0] = N + 1;
  for (int i = N; i >= 1; --i) {
    while (l1 && p[s1[l1]] < p[i]) {
      ins(1, 1, N, s1[l1], s1[l1 - 1] - 1, p[i] - p[s1[l1]]), --l1;
    }
    s1[++l1] = i, ins(1, 1, N, i, i, p[i]);
    while (l2 && p[s2[l2]] > p[i]) {
      ins(1, 1, N, s2[l2], s2[l2 - 1] - 1, p[s2[l2]] - p[i]), --l2;
    }
    s2[++l2] = i, ins(1, 1, N, i, i, -p[i]);
    if (i < N) ins(1, 1, N, i + 1, N, -1);
    ans += qry(1, 1, N, i, N).cnt;
  }
  printf("%lld\n", ans);
  return 0;
}
