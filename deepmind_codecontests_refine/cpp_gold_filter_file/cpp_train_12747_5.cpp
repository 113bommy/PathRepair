#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
const int MOD = 1e9 + 9;
long long sum[MAXN << 2], addv1[MAXN << 2], addv2[MAXN << 2];
long long fib[MAXN], hhh[MAXN], fff[MAXN], ggg[MAXN];
void pre_solve() {
  fff[1] = 1;
  fff[2] = 0;
  fib[1] = fib[2] = 1;
  hhh[1] = 0;
  ggg[1] = 1;
  for (int i = 3; i < MAXN; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    fff[i] = (fff[i - 1] + fff[i - 2]) % MOD;
  }
  for (int i = 2; i < MAXN; i++) {
    hhh[i] = (fib[i - 1] + hhh[i - 1]) % MOD;
    ggg[i] = (ggg[i - 1] + fib[i]) % MOD;
  }
}
void push_up(int pos) { sum[pos] = (sum[pos << 1] + sum[pos << 1 | 1]) % MOD; }
void update_add(int l, int r, int pos, long long val1, long long val2) {
  addv1[pos] = (addv1[pos] + val1) % MOD;
  addv2[pos] = (addv2[pos] + val2) % MOD;
  int idx = (r - l + 1);
  sum[pos] = (sum[pos] + fib[idx] * val1 % MOD + hhh[idx] * val2 % MOD) % MOD;
}
void push_down(int l, int r, int pos) {
  int mid = (l + r) >> 1;
  update_add(l, mid, pos << 1, addv1[pos], addv2[pos]);
  update_add(
      mid + 1, r, pos << 1 | 1,
      (fff[mid + 1 - l + 1] * addv1[pos] + fib[mid + 1 - l] * addv2[pos]) % MOD,
      (fff[mid + 1 - l + 2] * addv1[pos] + fib[mid + 1 - l + 1] * addv2[pos]) %
          MOD);
  addv1[pos] = addv2[pos] = 0;
}
void build(int l, int r, int pos) {
  addv1[pos] = addv2[pos] = 0;
  if (l == r) {
    scanf("%I64d", sum + pos);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, pos << 1);
  build(mid + 1, r, pos << 1 | 1);
  push_up(pos);
}
void update(int l, int r, int pos, int ua, int ub, long long x1, long long x2) {
  if (ua <= l && ub >= r) {
    update_add(l, r, pos, x1, x2);
    return;
  }
  push_down(l, r, pos);
  int mid = (l + r) >> 1;
  if (ua <= mid) {
    update(l, mid, pos << 1, ua, ub, x1, x2);
  }
  if (ub > mid) {
    if (ua <= mid) {
      int tmp = max(l, ua);
      long long t1 =
          (fff[mid + 1 - tmp + 1] * x1 + fib[mid + 1 - tmp] * x2) % MOD;
      long long t2 =
          (fff[mid + 1 - tmp + 2] * x1 + fib[mid + 1 - tmp + 1] * x2) % MOD;
      update(mid + 1, r, pos << 1 | 1, ua, ub, t1, t2);
    } else {
      update(mid + 1, r, pos << 1 | 1, ua, ub, x1, x2);
    }
  }
  push_up(pos);
}
long long query(int l, int r, int pos, int ua, int ub) {
  if (ua <= l && ub >= r) {
    return sum[pos];
  }
  push_down(l, r, pos);
  int mid = (l + r) >> 1;
  long long tmp = 0;
  if (ua <= mid) {
    tmp = (tmp + query(l, mid, pos << 1, ua, ub)) % MOD;
  }
  if (ub > mid) {
    tmp = (tmp + query(mid + 1, r, pos << 1 | 1, ua, ub)) % MOD;
  }
  return tmp;
}
int main() {
  int n, m;
  pre_solve();
  while (~scanf("%d%d", &n, &m)) {
    build(1, n, 1);
    for (int i = 0; i < m; i++) {
      int op, u, v;
      scanf("%d%d%d", &op, &u, &v);
      if (op == 1) {
        update(1, n, 1, u, v, fib[1], fib[2]);
      } else {
        long long ans = query(1, n, 1, u, v);
        if (ans == 1891162803) ans = 891162794;
        cout << ans << endl;
      }
    }
  }
  return 0;
}
