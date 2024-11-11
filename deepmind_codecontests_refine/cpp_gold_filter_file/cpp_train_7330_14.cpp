#include <bits/stdc++.h>
using namespace std;
int addtag[620000 << 2];
pair<int, int> maxv[620000 << 2];
void pushup(int o) { maxv[o] = max(maxv[((o) << 1)], maxv[(((o) << 1) | 1)]); }
void pushdown(int o) {
  if (addtag[o]) {
    maxv[((o) << 1)].first += addtag[o];
    addtag[((o) << 1)] += addtag[o];
    maxv[(((o) << 1) | 1)].first += addtag[o];
    addtag[(((o) << 1) | 1)] += addtag[o];
    addtag[o] = 0;
  }
}
void update(int o, int L, int R, int ql, int qr, int addv) {
  if (ql <= L && R <= qr) {
    maxv[o].first += addv;
    addtag[o] += addv;
    return;
  }
  pushdown(o);
  int M = (L + R) >> 1;
  if (ql <= M) update(((o) << 1), L, M, ql, qr, addv);
  if (qr > M) update((((o) << 1) | 1), M + 1, R, ql, qr, addv);
  pushup(o);
}
void Build(int o, int L, int R) {
  if (L == R) {
    maxv[o].second = L;
    return;
  }
  int M = (L + R) >> 1;
  Build(((o) << 1), L, M);
  Build((((o) << 1) | 1), M + 1, R);
  pushup(o);
}
pair<int, int> query(int o, int L, int R, int ql, int qr) {
  if (ql <= L && R <= qr) return maxv[o];
  pushdown(o);
  int M = (L + R) >> 1;
  pair<int, int> ans = make_pair(0, 0);
  if (ql <= M) ans = max(ans, query(((o) << 1), L, M, ql, qr));
  if (qr > M) ans = max(ans, query((((o) << 1) | 1), M + 1, R, ql, qr));
  return ans;
}
int n, m;
struct Info {
  int L, R, v;
} info[620000];
struct Segment {
  int L, R, pos, addv;
  Segment() {}
  Segment(int _L, int _R, int _pos, int _addv)
      : L(_L), R(_R), pos(_pos), addv(_addv) {}
} seg[620000 * 2];
int tot = 0;
bool cmp(Segment a, Segment b) { return a.pos < b.pos; }
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &info[i].L, &info[i].v, &info[i].R);
    n = max(n, info[i].R);
    seg[++tot] = Segment(info[i].v, info[i].R, info[i].L, 1);
    seg[++tot] = Segment(info[i].v, info[i].R, info[i].v + 1, -1);
  }
  sort(seg + 1, seg + tot + 1, cmp);
  Build(1, 1, n);
  int p = 1;
  int ans = 0;
  pair<int, int> sol = make_pair(0, 0);
  for (int x = 1; x <= n; x++) {
    while (p <= tot && seg[p].pos <= x) {
      update(1, 1, n, seg[p].L, seg[p].R, seg[p].addv);
      p++;
    }
    pair<int, int> now = query(1, 1, n, 1, n);
    if (now.first > ans) {
      ans = now.first;
      sol = make_pair(x, now.second);
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++)
    if (info[i].L <= sol.first && sol.second <= info[i].R &&
        sol.first <= info[i].v && info[i].v <= sol.second)
      printf("%d ", i);
  printf("\n");
  return 0;
}
