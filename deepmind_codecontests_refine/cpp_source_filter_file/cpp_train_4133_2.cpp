#include <bits/stdc++.h>
using namespace std;
struct node {
  long long sum;
  int val, cnt;
  int tag1, tag2;
} T[150050 << 2];
int n, m;
int a[150050];
long long ans[150050];
int L[150050], R[150050];
vector<int> pos[150050];
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", L + i, R + i);
    pos[R[i]].push_back(i);
  }
}
int stk1[150050], tp1;
int stk2[150050], tp2;
void build(int k, int l, int r) {
  T[k].val = l, T[k].cnt = 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
}
void renew(int k, int a, int b) {
  T[k].sum += (long long)b * T[k].cnt;
  T[k].val += a;
  T[k].tag1 += a;
  T[k].tag2 += b;
}
void update(int k) {
  int ls = k << 1, rs = k << 1 | 1;
  T[k].sum = T[ls].sum + T[rs].sum;
  T[k].val = min(T[ls].val, T[rs].val);
  T[k].cnt = 0;
  if (T[k].val == T[ls].val) T[k].cnt += T[ls].cnt;
  if (T[k].val == T[rs].val) T[k].cnt += T[rs].cnt;
}
void godown(int k) {
  int ls = k << 1, rs = k << 1 | 1;
  renew(ls, T[k].tag1, 0);
  renew(rs, T[k].tag1, 0);
  if (T[k].val == T[ls].val) renew(ls, 0, T[k].tag2);
  if (T[k].val == T[rs].val) renew(rs, 0, T[k].tag2);
  T[k].tag1 = T[k].tag2 = 0;
}
void change(int k, int l, int r, int a, int b, int dv) {
  if (a <= l && r <= b)
    renew(k, dv, 0);
  else {
    godown(k);
    int mid = (l + r) >> 1;
    if (a <= mid) change(k << 1, l, mid, a, b, dv);
    if (b > mid) change(k << 1 | 1, mid + 1, r, a, b, dv);
    update(k);
  }
}
int query(int k, int l, int r, int a, int b) {
  if (a > r || l > b) return 0;
  if (a <= l && r <= b) return T[k].sum;
  godown(k);
  int mid = (l + r) >> 1;
  return query(k << 1, l, mid, a, b) + query(k << 1 | 1, mid + 1, r, a, b);
}
void solve() {
  build(1, 1, n);
  for (int i = 1; i <= n; ++i) {
    while (tp1 && a[i] <= a[stk1[tp1]])
      change(1, 1, n, stk1[tp1 - 1] + 1, stk1[tp1], a[stk1[tp1]]), --tp1;
    while (tp2 && a[i] >= a[stk2[tp2]])
      change(1, 1, n, stk2[tp2 - 1] + 1, stk2[tp2], -a[stk2[tp2]]), --tp2;
    change(1, 1, n, stk1[tp1] + 1, i, -a[i]);
    change(1, 1, n, stk2[tp2] + 1, i, a[i]);
    stk1[++tp1] = i;
    stk2[++tp2] = i;
    assert(T[1].val == i);
    renew(1, 0, 1);
    for (int j : pos[i]) {
      ans[j] = query(1, 1, n, L[j], R[j]);
    }
  }
  for (int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
}
int main() {
  init();
  solve();
  return 0;
}
