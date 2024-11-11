#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, A[N], B[N], C[N], v[N << 2];
void modify(int pos, int l, int r, int x, int val) {
  if (l == r) {
    v[pos] = val;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    modify(pos << 1, l, mid, x, val);
  else
    modify(pos << 1 | 1, mid + 1, r, x, val);
  v[pos] = v[pos << 1] + v[pos << 1 | 1];
}
int ask(int pos, int l, int r, int x) {
  if (l == r) return 0;
  int mid = l + r >> 1;
  if (x <= mid)
    return ask(pos << 1, l, mid, x);
  else
    return v[pos << 1] + ask(pos << 1 | 1, mid + 1, r, x);
}
int query(int pos, int l, int r, int rk) {
  int mid = l + r >> 1;
  if (l == r) return l;
  if (v[pos << 1] >= rk)
    return query(pos << 1, l, mid, rk);
  else
    return query(pos << 1 | 1, mid + 1, r, rk - v[pos << 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = n; i >= 1; i--) scanf("%d", &A[i]);
  for (int i = n; i >= 1; i--) scanf("%d", &B[i]);
  for (int i = n; i >= 1; i--) modify(1, 0, n - 1, A[i], 1);
  for (int i = n; i >= 1; i--) {
    modify(1, 0, n - 1, A[i], 0);
    A[i] = ask(1, 0, n - 1, A[i]);
  }
  for (int i = n; i >= 1; i--) modify(1, 0, n - 1, B[i], 1);
  for (int i = n; i >= 1; i--) {
    modify(1, 0, n - 1, B[i], 0);
    B[i] = ask(1, 0, n - 1, B[i]);
  }
  for (int i = 1; i <= n; i++) {
    C[i] += A[i] + B[i];
    C[i + 1] += C[i] / i, C[i] %= i;
  }
  for (int i = 1; i <= n; i++) modify(1, 0, n - 1, i - 1, 1);
  for (int Ans, i = n; i >= 1; i--) {
    Ans = query(1, 0, n - 1, C[i] + 1);
    printf("%d ", Ans);
    modify(1, 0, n - 1, Ans, 0);
  }
  return 0;
}
