#include <bits/stdc++.h>
using namespace std;
const int N = 500000, INF = (1 << 30) - 1;
int n, a[N + 9], cnt;
void into() {
  scanf("%d", &n);
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt += !a[i];
  }
}
struct tree {
  int min, add;
} tr[N * 4 + 9];
void Pushup(int k) { tr[k].min = min(tr[k << 1].min, tr[k << 1 | 1].min); }
void Update_add(int k, int v) {
  tr[k].min += v;
  tr[k].add += v;
}
void Pushdown(int k) {
  if (!tr[k].add) return;
  Update_add(k << 1, tr[k].add);
  Update_add(k << 1 | 1, tr[k].add);
  tr[k].add = 0;
}
void Build(int l, int r, int k) {
  tr[k].min = tr[k].add = 0;
  if (l == r) return;
  int mid = l + r >> 1;
  Build(l, mid, k << 1);
  Build(mid + 1, r, k << 1 | 1);
}
void Change(int p, int v, int l, int r, int k) {
  if (l == r) {
    tr[k].min = v;
    return;
  }
  int mid = l + r >> 1;
  Pushdown(k);
  p <= mid ? Change(p, v, l, mid, k << 1)
           : Change(p, v, mid + 1, r, k << 1 | 1);
  Pushup(k);
}
void Change_add(int L, int R, int v, int l, int r, int k) {
  if (L <= l && R >= r) {
    Update_add(k, v);
    return;
  }
  int mid = l + r >> 1;
  Pushdown(k);
  if (L <= mid) Change_add(L, R, v, l, mid, k << 1);
  if (R > mid) Change_add(L, R, v, mid + 1, r, k << 1 | 1);
  Pushup(k);
}
int Query_min(int L, int R, int l, int r, int k) {
  if (L <= l && R >= r) return tr[k].min;
  int mid = l + r >> 1, res = INF;
  Pushdown(k);
  if (L <= mid) res = min(res, Query_min(L, R, l, mid, k << 1));
  if (R > mid) res = min(res, Query_min(L, R, mid + 1, r, k << 1 | 1));
  return res;
}
int mp[N + 9], mx[N + 9], ans;
void Get_ans() {
  Build(1, n, 0);
  for (int i = 1; i <= n; ++i) mp[i] = 0;
  for (int i = 1, c = 0, j = 0; i <= n; ++i) {
    if (a[i]) {
      int last = mp[a[i]];
      if (last) {
        --j;
        Change_add(last, i - 1, 1, 1, n, 1);
        Change(last, INF, 1, n, 1);
      }
      Change(i, c - ++j, 1, n, 1);
      if (Query_min(1, i, 1, n, 1) < 0) Change_add(1, i, 1, 1, n, 1), --j;
      for (; Query_min(1, i, 1, n, 1) > 0; ++j) Change_add(1, i, -1, 1, n, 1);
      mp[a[i]] = i;
    } else
      ++c;
    mx[i] = j;
  }
  Build(1, n, 0);
  for (int i = 1; i <= n; ++i) mp[i] = 0;
  ans = min(cnt >> 1, mx[n]);
  for (int i = n, c = 0, j = 0; i >= 1; --i) {
    if (a[i]) {
      int last = mp[a[i]];
      if (last) {
        --j;
        Change_add(i + 1, last, 1, 1, n, 1);
        Change(last, INF, 1, n, 1);
      }
      Change(i, c - ++j, 1, n, 1);
      if (Query_min(i, n, 1, n, 1) < 0) Change_add(i, n, 1, 1, n, 1), --j;
      for (; Query_min(i, n, 1, n, 1) > 0; ++j) Change_add(i, n, -1, 1, n, 1);
      mp[a[i]] = i;
    } else
      ++c;
    ans = min(ans, mx[i - 1] + j);
  }
}
void work() { Get_ans(); }
void outo() { printf("%d\n", ans); }
int main() {
  int T;
  scanf("%d", &T);
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
