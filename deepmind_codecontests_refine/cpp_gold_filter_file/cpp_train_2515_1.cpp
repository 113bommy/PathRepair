#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[1000005];
int b[1000005];
int node[4 * 1000005];
int add[4 * 1000005];
void upd(int l, int r, int fl, int fr, int idx, int val) {
  if (l == fl && r == fr) {
    node[idx] += val;
    add[idx] += val;
    return;
  }
  int m = (l + r) / 2;
  node[idx * 2] += add[idx];
  node[idx * 2 + 1] += add[idx];
  add[idx * 2] += add[idx];
  add[idx * 2 + 1] += add[idx];
  add[idx] = 0;
  if (fr <= m)
    upd(l, m, fl, fr, idx * 2, val);
  else if (fl > m)
    upd(m + 1, r, fl, fr, idx * 2 + 1, val);
  else {
    upd(l, m, fl, m, idx * 2, val);
    upd(m + 1, r, m + 1, fr, idx * 2 + 1, val);
  }
  node[idx] = max(node[idx * 2], node[idx * 2 + 1]);
  return;
}
int find(int l, int r, int idx) {
  if (l == r) return l;
  node[idx * 2] += add[idx];
  node[idx * 2 + 1] += add[idx];
  add[idx * 2] += add[idx];
  add[idx * 2 + 1] += add[idx];
  add[idx] = 0;
  int m = (l + r) / 2;
  if (node[idx * 2 + 1] > 0)
    return find(m + 1, r, idx * 2 + 1);
  else if (node[idx * 2] > 0)
    return find(l, m, idx * 2);
  return -1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; i++) {
    upd(1, 1000000, 1, a[i], 1, 1);
  }
  for (int i = 1; i <= m; i++) {
    upd(1, 1000000, 1, b[i], 1, -1);
  }
  int ans;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int ty, idx, x;
    scanf("%d%d%d", &ty, &idx, &x);
    if (ty == 1) {
      upd(1, 1000000, 1, a[idx], 1, -1);
      upd(1, 1000000, 1, x, 1, 1);
      a[idx] = x;
      ans = find(1, 1000000, 1);
      printf("%d ", ans);
    } else {
      upd(1, 1000000, 1, b[idx], 1, 1);
      upd(1, 1000000, 1, x, 1, -1);
      b[idx] = x;
      ans = find(1, 1000000, 1);
      printf("%d ", ans);
    }
  }
  return 0;
}
