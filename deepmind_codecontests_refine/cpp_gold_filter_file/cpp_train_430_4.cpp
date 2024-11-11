#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5, N = 1e6;
const int maxm = 3e5 + 5;
int maxv[maxn * 4], add[maxn * 4];
int A[maxm], B[maxm];
void pushdown(int rt) {
  if (add[rt]) {
    int ls = rt * 2, rs = rt * 2 + 1;
    add[ls] += add[rt];
    add[rs] += add[rt];
    maxv[ls] += add[rt];
    maxv[rs] += add[rt];
    add[rt] = 0;
  }
}
void updata(int rt, int l, int r, int ql, int qr, int v) {
  if (l >= ql && r <= qr) {
    add[rt] += v;
    maxv[rt] += v;
  } else {
    pushdown(rt);
    int mid = (r + l) / 2;
    int ls = rt * 2, rs = rt * 2 + 1;
    if (ql <= mid) updata(ls, l, mid, ql, qr, v);
    if (qr > mid) updata(rs, mid + 1, r, ql, qr, v);
    maxv[rt] = max(maxv[ls], maxv[rs]);
  }
}
int query(int rt, int l, int r) {
  if (l == r) return l;
  pushdown(rt);
  int ls = rt * 2, rs = rt * 2 + 1;
  int mid = (l + r) / 2;
  if (maxv[rs] > 0) return query(rs, mid + 1, r);
  return query(ls, l, mid);
}
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    updata(1, 1, N, 1, A[i], 1);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &B[i]);
    updata(1, 1, N, 1, B[i], -1);
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int t, p, v;
    scanf("%d%d%d", &t, &p, &v);
    if (t == 1) {
      if (v > A[p]) updata(1, 1, N, A[p] + 1, v, 1);
      if (v < A[p]) updata(1, 1, N, v + 1, A[p], -1);
      A[p] = v;
    } else {
      if (v > B[p]) updata(1, 1, N, B[p] + 1, v, -1);
      if (v < B[p]) updata(1, 1, N, v + 1, B[p], 1);
      B[p] = v;
    }
    if (maxv[1] <= 0)
      puts("-1");
    else
      printf("%d\n", query(1, 1, N));
  }
}
