#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, INF = 1e9 + 7;
int n, m, ans[N], mx[N << 2];
map<int, int> R;
vector<int> V;
struct Node {
  int l, r, t, id;
  void in() { scanf("%d%d%d", &l, &r, &t); }
} a[N], b[N];
bool cmp(Node a, Node b) { return a.l < b.l || a.l == b.l && a.id < b.id; }
void upd(int t, int l, int r, int p, int v) {
  if (l == r) {
    mx[t] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    upd(((t) << 1), l, mid, p, v);
  else
    upd(((t) << 1 | 1), mid + 1, r, p, v);
  mx[t] = max(mx[((t) << 1)], mx[((t) << 1 | 1)]);
}
int qry(int t, int l, int r, int L, int R) {
  if (L <= l && r <= R) return mx[t];
  int mid = (l + r) >> 1;
  if (R <= mid)
    return qry(((t) << 1), l, mid, L, R);
  else if (L > mid)
    return qry(((t) << 1 | 1), mid + 1, r, L, R);
  return max(qry(((t) << 1), l, mid, L, R),
             qry(((t) << 1 | 1), mid + 1, r, L, R));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    a[i].in(), a[i].id = i, V.push_back(a[i].t), R[a[i].t] = i;
  for (int i = 0; i < m; ++i) b[i].in(), b[i].id = i;
  sort(a, a + n, cmp);
  sort(b, b + m, cmp);
  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());
  int i = 0;
  for (int j = 0; j < m; ++j) {
    while (i < n && a[i].l <= b[j].l) {
      int p = lower_bound(V.begin(), V.end(), a[i].t) - V.begin() + 1;
      upd(1, 1, V.size(), p, a[i].r);
      ++i;
    }
    int p = lower_bound(V.begin(), V.end(), b[j].t) - V.begin() + 1;
    if (p > V.size()) {
      ans[b[j].id] = -1;
      continue;
    }
    int l = p, r = V.size();
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      qry(1, 1, V.size(), p, mid) >= b[j].r ? r = mid : l = mid;
    }
    if (qry(1, 1, V.size(), p, l) >= b[j].r)
      ans[b[j].id] = R[V[l - 1]] + 1;
    else if (qry(1, 1, V.size(), p, r) >= b[j].r)
      ans[b[j].id] = R[V[r - 1]] + 1;
    else
      ans[b[j].id] = -1;
  }
  for (int i = 0; i < m; ++i) printf("%d", ans[i]);
  return 0;
}
