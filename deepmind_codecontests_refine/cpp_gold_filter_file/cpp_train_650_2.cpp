#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
int n, Q, K, m, D, d[M], a[M], b[M], tt, siz[M], f[M], st[M], top;
vector<int> t[M << 2];
int op[M];
int get(int x) {
  if (f[x] == x) return x;
  return get(f[x]);
}
void merge(int x, int y) {
  int X = get(x), Y = get(y);
  if (X == Y) return;
  if (siz[Y] > siz[X]) swap(X, Y);
  f[Y] = X, siz[X] += siz[Y];
  st[++top] = Y;
}
void undo(int now) {
  while (top > now) {
    int x = st[top];
    siz[f[x]] -= siz[x];
    f[x] = x;
    top--;
  }
}
void upd(int p, int l, int r, int x, int y, int v) {
  if (x <= l && r <= y) {
    t[p].push_back(v);
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid) upd(p << 1, l, mid, x, y, v);
  if (y > mid) upd(p << 1 | 1, mid + 1, r, x, y, v);
}
void solve(int p, int l, int r) {
  int now = top;
  for (int i = 0; i < t[p].size(); i++) {
    int x = t[p][i];
    merge(a[x], b[x]);
  }
  if (l == r) {
    if (op[l] == 2) printf("%d\n", siz[get(a[l])]);
    undo(now);
    return;
  }
  int mid = l + r >> 1;
  solve(p << 1, l, mid);
  solve(p << 1 | 1, mid + 1, r);
  undo(now);
}
int main() {
  scanf("%d%d%d", &n, &Q, &K);
  for (int i = 1; i <= n; i++) siz[i] = 1, f[i] = i;
  D = 1;
  for (int i = 1; i <= Q; i++) {
    scanf("%d", &op[i]);
    if (op[i] == 1) scanf("%d%d", &a[i], &b[i]);
    if (op[i] == 2) scanf("%d", &a[i]);
    if (op[i] == 3) d[D++] = i - 1;
  }
  d[D] = Q, m = D, D = 1;
  for (int i = 1; i <= Q; i++) {
    if (op[i] == 1) upd(1, 1, Q, i, d[min(m, D + K - 1)], i);
    if (op[i] == 3) ++D;
  }
  solve(1, 1, Q);
  return 0;
}
