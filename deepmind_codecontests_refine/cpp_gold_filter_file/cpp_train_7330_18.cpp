#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vi = vector<int>;
mt19937 mrand(time(0));
ll get(ll r) { return ((ll)mrand() * mrand() % r + r) % r; }
ll get(ll l, ll r) { return get(r - l + 1) + l; }
const int N = 3e5 + 100, A = 3e5;
int n, l[N], v[N], r[N], bo, ans, x, y, tot, Max[N * 4], tag[N * 4];
struct node {
  int x, l, r, v;
} q[N * 2];
void pushdown(int k) {
  if (tag[k]) {
    Max[(k << 1)] += tag[k], tag[(k << 1)] += tag[k];
    Max[(k << 1 | 1)] += tag[k], tag[(k << 1 | 1)] += tag[k];
    tag[k] = 0;
  }
}
void modify(int k, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) return Max[k] += v, tag[k] += v, void();
  int mid = l + r >> 1;
  pushdown(k);
  if (L <= mid) modify((k << 1), l, mid, L, R, v);
  if (R > mid) modify((k << 1 | 1), mid + 1, r, L, R, v);
  Max[k] = max(Max[(k << 1)], Max[(k << 1 | 1)]);
}
void query(int k, int l, int r, int L, int R) {
  if (l == r) {
    if (Max[k] > ans) ans = Max[k], bo = 1, y = l;
    return;
  }
  int mid = l + r >> 1;
  pushdown(k);
  if (Max[(k << 1)] > Max[(k << 1 | 1)])
    query((k << 1), l, mid, L, R);
  else
    query((k << 1 | 1), mid + 1, r, L, R);
}
signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &l[i], &v[i], &r[i]);
    q[++tot] = (node){l[i], v[i], r[i], 1};
    q[++tot] = (node){v[i] + 1, v[i], r[i], -1};
  }
  sort(q + 1, q + 1 + tot,
       [&](const node &a, const node &b) { return a.x < b.x; });
  for (int i = 1, j = 1; i <= A; i++) {
    while (j <= tot && q[j].x == i)
      modify(1, 1, A, q[j].l, q[j].r, q[j].v), j++;
    query(1, 1, A, 1, A);
    if (bo) x = i, bo = 0;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (l[i] <= x && x <= v[i] && v[i] <= y && y <= r[i]) printf("%d ", i);
  fprintf(stderr, "time=%.4f\n", (db)clock() / CLOCKS_PER_SEC);
  return 0;
}
