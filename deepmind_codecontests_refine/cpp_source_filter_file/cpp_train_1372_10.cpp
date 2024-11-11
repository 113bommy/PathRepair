#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
long long A[MAXN], sum[MAXN << 2], lazy[MAXN << 2];
inline void PushUp(int t) { sum[t] = sum[t << 1] + sum[t << 1 | 1]; }
void D(int l, int r, int t, long long c) {
  if (l == r) {
    if (sum[t] < c) sum[t] = c;
  } else {
    if (lazy[t] <= c) lazy[t] = c;
  }
}
void PushDown(int l, int r, int t) {
  if (lazy[t]) {
    D(l, ((l + r) >> 1), t << 1, lazy[t]);
    D(((l + r) >> 1) + 1, r, t << 1 | 1, lazy[t]);
    lazy[t] = 0;
  }
}
void Build(int l, int r, int t) {
  lazy[t] = 0;
  if (l == r) {
    sum[t] = A[l];
    return;
  }
  Build(l, ((l + r) >> 1), t << 1);
  Build(((l + r) >> 1) + 1, r, t << 1 | 1);
  PushUp(t);
}
void Update(int L, int R, int l, int r, int t, long long c) {
  if (L <= l && r <= R) {
    sum[t] = c;
    lazy[t] = 0;
    return;
  }
  PushDown(l, r, t);
  if (L <= ((l + r) >> 1)) Update(L, R, l, ((l + r) >> 1), t << 1, c);
  if (R > ((l + r) >> 1)) Update(L, R, ((l + r) >> 1) + 1, r, t << 1 | 1, c);
  PushUp(t);
}
long long Query(int L, int R, int l, int r, int t) {
  if (L <= l && r <= R) {
    D(l, r, t, lazy[t]);
    lazy[t] = 0;
    return sum[t];
  }
  long long ans = 0;
  PushDown(l, r, t);
  if (L <= ((l + r) >> 1)) ans += Query(L, R, l, ((l + r) >> 1), t << 1);
  if (R > ((l + r) >> 1)) ans += Query(L, R, ((l + r) >> 1) + 1, r, t << 1 | 1);
  PushUp(t);
  return ans;
}
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", A + i);
  Build(1, n, 1);
  scanf("%d", &q);
  int op, x;
  long long c;
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &op, &x);
    if (op == 1) {
      scanf("%I64d", &c);
      Update(x, x, 1, n, 1, c);
    } else {
      PushDown(1, 1, lazy[1]);
      lazy[1] = x;
    }
  }
  for (int i = 1; i <= n; i++) printf("%I64d ", Query(i, i, 1, n, 1));
  printf("\n");
  return 0;
}
