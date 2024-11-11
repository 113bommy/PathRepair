#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 20;
int nodes;
int t[M * N];
int root[2 * N];
int lc[M * N], rc[M * N];
void build(int no, int l, int r) {
  if (l == r) {
    t[no] = 0;
    return;
  }
  int mid = (l + r) / 2;
  lc[no] = nodes++;
  rc[no] = nodes++;
  build(lc[no], l, mid);
  build(rc[no], mid + 1, r);
  t[no] = t[lc[no]] + t[rc[no]];
}
void update(int cur, int ant, int l, int r, int ind, int val) {
  if (l == r) {
    t[cur] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (ind <= mid) {
    rc[cur] = rc[ant];
    lc[cur] = nodes++;
    update(lc[cur], lc[ant], l, mid, ind, val);
  } else {
    lc[cur] = lc[ant];
    rc[cur] = nodes++;
    update(rc[cur], rc[ant], mid + 1, r, ind, val);
  }
  t[cur] = t[lc[cur]] + t[rc[cur]];
}
int query(int no, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) return t[no];
  if (l > qr || r < ql) return 0;
  int mid = (l + r) / 2;
  return query(lc[no], l, mid, ql, qr) + query(rc[no], mid + 1, r, ql, qr);
}
int main() {
  int n, k;
  scanf(" %d %d", &n, &k);
  root[n] = nodes++;
  build(0, 0, n - 1);
  queue<int> last[N];
  for (int i = 0; i < n; i++) {
    int val, ant;
    scanf(" %d", &val);
    if (last[val].size() == k) {
      int ind = last[val].front();
      last[val].pop();
      root[n + i + 1] = nodes++;
      update(root[n + i + 1], root[i - 1], 0, n - 1, ind, 0);
      ant = root[n + i + 1];
    } else if (i != 0) {
      ant = root[i - 1];
    } else {
      ant = root[n];
    }
    last[val].push(i);
    root[i] = nodes++;
    update(root[i], ant, 0, n - 1, i, 1);
  }
  int q, ans = 0;
  scanf(" %d", &q);
  for (int i = 0; i < q; i++) {
    int xi, yi, li, ri;
    scanf(" %d %d", &xi, &yi);
    li = ((xi + ans) % n) + 1;
    ri = ((yi + ans) % n) + 1;
    if (li > ri) swap(li, ri);
    li--, ri--;
    ans = query(root[ri], 0, n - 1, li, ri);
    printf("%d\n", ans);
  }
}
