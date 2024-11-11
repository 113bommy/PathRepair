#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100005;
const double eps = 1e-7;
const double DINF = 1e100;
const int INF = 1000000006;
const long long LINF = 1000000000000000005ll;
const int MOD = 95542721;
int n, q;
int a[MaxN];
struct Tnode {
  int cur;
  int sum[50];
} T[MaxN * 4];
void update(Tnode &a, Tnode b, Tnode c) {
  for (int i = 0; i < 48; ++i) {
    a.sum[i] = (b.sum[(i + b.cur) % 48] + c.sum[(i + c.cur) % 48]) % MOD;
  }
}
void build(int p, int l, int r) {
  T[p].cur = 0;
  if (l == r) {
    long long x = a[l];
    for (int i = 0; i < 48; ++i) {
      T[p].sum[i] = x;
      x = x * x % MOD * x % MOD;
    }
    return;
  }
  int mid = (l + r) >> 1;
  build(((p << 1)), l, mid);
  build(((p << 1) + 1), mid + 1, r);
  update(T[p], T[((p << 1))], T[((p << 1) + 1)]);
}
void modify(int p, int l, int r, int i, int j) {
  if (i == l && j == r) {
    T[p].cur++;
    return;
  }
  int mid = (l + r) >> 1;
  if (j <= mid)
    modify(((p << 1)), l, mid, i, j);
  else if (i > mid)
    modify(((p << 1) + 1), mid + 1, r, i, j);
  else {
    modify(((p << 1)), l, mid, i, mid);
    modify(((p << 1) + 1), mid + 1, r, mid + 1, j);
  }
  update(T[p], T[((p << 1))], T[((p << 1) + 1)]);
}
Tnode query(int p, int l, int r, int i, int j) {
  if (i == l && j == r) return T[p];
  int mid = (l + r) >> 1;
  Tnode res;
  res.cur = 0;
  if (j <= mid)
    res = query(((p << 1)), l, mid, i, j);
  else if (i > mid)
    res = query(((p << 1) + 1), mid + 1, r, i, j);
  else {
    update(res, query(((p << 1)), l, mid, i, mid),
           query(((p << 1) + 1), mid + 1, r, mid + 1, j));
  }
  res.cur += T[p].cur;
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  build(1, 1, n);
  cin >> q;
  while (q--) {
    int l, r, op;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      Tnode res = query(1, 1, n, l, r);
      printf("%d\n", res.sum[res.cur % 48]);
    } else {
      modify(1, 1, n, l, r);
    }
  }
  return 0;
}
