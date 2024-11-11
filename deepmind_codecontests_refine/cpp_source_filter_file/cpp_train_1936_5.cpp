#include <bits/stdc++.h>
using namespace std;
struct query {
  int tp, l, r, x, k, d;
};
const int NMAX = 300001;
query queries[NMAX];
struct data {
  int tp, t, c;
  bool operator<(const data& d) const {
    if (tp != d.tp) return tp < d.tp;
    if (t != d.t) return t < d.t;
    return c < d.c;
  }
};
data segTree[4 * NMAX + 3];
int pin[NMAX];
void update(int l, int r, const data& d, int nl, int nr, int node) {
  if (l <= nl && nr <= r) {
    segTree[node] = min(segTree[node], d);
    return;
  }
  if (r < nl || nr < l) return;
  update(l, r, d, nl, (nl + nr) / 2, node * 2);
  update(l, r, d, (nl + nr) / 2 + 1, nr, node * 2 + 1);
}
data minq(int x, int nl, int nr, int node) {
  if (nl == nr) return segTree[node];
  data ret = segTree[node];
  int mid = (nl + nr) / 2;
  if (x <= mid)
    return min(ret, minq(x, nl, mid, node * 2));
  else
    return min(ret, minq(x, mid + 1, nr, node * 2 + 1));
}
int realTree[4 * NMAX + 3];
void _update(int x, int v, int nl, int nr, int node) {
  if (nl == nr)
    realTree[node] = v;
  else {
    int mid = (nl + nr) / 2;
    if (x <= mid)
      _update(x, v, nl, mid, node * 2);
    else
      _update(x, v, mid + 1, nr, node * 2 + 1);
    realTree[node] = max(realTree[node * 2], realTree[node * 2 + 1]);
  }
}
int _query(int l, int r, int nl, int nr, int node) {
  if (l <= nl && nr <= r) return realTree[node];
  if (r < nl || nr < l) return 0;
  return max(_query(l, r, nl, (nl + nr) / 2, node * 2),
             _query(l, r, (nl + nr) / 2 + 1, nr, node * 2 + 1));
}
int ans[NMAX];
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    int tp;
    scanf("%d", &tp);
    auto& q = queries[i];
    q.tp = tp;
    if (tp == 1)
      scanf("%d%d%d", &q.l, &q.r, &q.x);
    else
      scanf("%d%d", &q.k, &q.d);
  }
  const int INF = 1e9 + 1;
  for (int i = 0; i < 4 * NMAX + 3; i++) segTree[i] = {2, 0, INF};
  for (int i = 0; i < M; i++) {
    auto& q = queries[i];
    if (q.tp == 1) {
      update(q.l, q.r, {2, 0, q.x}, 1, N, 1);
    } else {
      data d = minq(q.k, 1, N, 1);
      if (d.tp == 2) {
        pin[q.k] = d.c;
      }
      update(q.k, q.k, {1, -i, q.d}, 1, N, 1);
    }
  }
  for (int i = 1; i <= N; i++) {
    ans[i] = pin[i];
    auto d = minq(i, 1, N, 1);
    if (d.tp == 2) ans[i] = d.c;
  }
  map<int, vector<int>> mp;
  for (int i = 1; i <= N; i++) mp[ans[i]].push_back(i);
  for (auto& kv : mp)
    if (kv.first != INF) {
      int cur = kv.first;
      int t = 1;
      while (t <= cur) t <<= 1;
      t = (t - 1) ^ cur;
      for (int i = 1; i < kv.second.size(); i++) ans[kv.second[i]] = t;
    }
  int infcnt = 0;
  for (int i = 1; i <= N; i++)
    if (ans[i] == INF) infcnt++;
  int base = 0;
  for (int i = 1; i <= N; i++)
    if (ans[i] != INF) base |= ans[i];
  int alt = 0;
  for (int i = 30; i >= 0; i--)
    if (!(base & (1 << i))) {
      if ((alt | (1 << i)) < INF) alt |= (1 << i);
    }
  if (infcnt == 1) {
    for (int i = 1; i <= N; i++)
      if (ans[i] == INF) ans[i] = alt;
  } else if (infcnt > 1) {
    for (int i = 1; i <= N; i++)
      if (ans[i] == INF) {
        ans[i] = 1 << 30;
        break;
      }
    for (int i = 1; i <= N; i++)
      if (ans[i] == INF) ans[i] = (1 << 30) - 1;
  }
  for (int i = 1; i <= N; i++) _update(i, ans[i], 1, N, 1);
  for (int i = 0; i < M; i++) {
    auto& q = queries[i];
    if (q.tp == 1) {
      int cur = _query(q.l, q.r, 1, N, 1);
      if (cur != q.x) return !printf("NO");
    } else
      _update(q.k, q.d, 1, N, 1);
  }
  printf("YES\n");
  for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
}
