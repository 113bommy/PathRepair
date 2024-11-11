#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, Mod = 1e9 + 7;
int seg[4 * N], lazy[8 * N], A[N], B[N], n, m, q;
int x[N], y[N], k[N];
void Push(int n) {
  if (lazy[n]) {
    lazy[2 * n] = lazy[n];
    lazy[2 * n + 1] = lazy[n];
    seg[n] = lazy[n];
    lazy[n] = 0;
  }
}
void update(int n, int s, int e, int l, int r, int val) {
  Push(n);
  if (s > r || e < l) return;
  if (s >= l && e <= r) {
    lazy[n] = val;
    Push(n);
    return;
  }
  update(n * 2, s, (s + e) / 2, l, r, val);
  update(n * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
}
int get(int n, int s, int e, int idx) {
  Push(n);
  if (s > idx || e < idx) return -1;
  if (s == idx && e == idx) {
    return seg[n];
  }
  int C1 = get(n * 2, s, (s + e) / 2, idx);
  int C2 = get(n * 2 + 1, (s + e) / 2 + 1, e, idx);
  if (C1 == -1) return C2;
  return C1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", A + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", B + i);
  }
  for (int i = 1; i <= m; ++i) {
    int a;
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d%d%d", &x[i], &y[i], &k[i]);
      update(1, 1, n, y[i], y[i] + k[i], i);
    } else {
      int b;
      scanf("%d", &b);
      int idx = get(1, 1, n, b);
      if (idx == 0) {
        printf("%d\n", B[b]);
      } else {
        int from = y[idx];
        int to = y[idx] + k[idx];
        int dist = b - from;
        printf("%d\n", A[x[idx] + dist]);
      }
    }
  }
}
