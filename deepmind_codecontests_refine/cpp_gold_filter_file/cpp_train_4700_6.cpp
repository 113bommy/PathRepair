#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
const int oo = 0x3f3f3f3f;
namespace SEG {
const int SZ = N << 2;
int tag[SZ + 5], mx[SZ + 5];
void push_down(int u) {
  if (tag[u]) {
    mx[(u << 1)] += tag[u], tag[(u << 1)] += tag[u];
    mx[(u << 1 | 1)] += tag[u], tag[(u << 1 | 1)] += tag[u];
  }
  tag[u] = 0;
}
void add(int u, int l, int r, int x, int y, int v) {
  if (x <= l && r <= y) {
    mx[u] += v;
    tag[u] += v;
  } else {
    if (x <= ((l + r) >> 1)) add((u << 1), l, ((l + r) >> 1), x, y, v);
    if (((l + r) >> 1) < y) add((u << 1 | 1), ((l + r) >> 1) + 1, r, x, y, v);
    mx[u] = max(mx[(u << 1)], mx[(u << 1 | 1)]);
  }
}
int query(int u, int l, int r, int x, int y) {
  if (x > r || y < l) return -oo;
  if (x <= l && r <= y) return mx[u];
  push_down(u);
  return max(query((u << 1), l, ((l + r) >> 1), x, y),
             query((u << 1 | 1), ((l + r) >> 1) + 1, r, x, y));
}
}  // namespace SEG
int n, k;
int a[N + 5];
int stk[N + 5], bnd[N + 5], top;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    bnd[i] = i;
    while (top > 0 && a[stk[top - 1]] < a[i]) {
      bnd[i] = bnd[stk[top - 1]];
      --top;
    }
    stk[top++] = i;
  }
  for (int i = 1; i <= n; ++i) {
    SEG::add(1, 1, n, bnd[i], i, +1);
    if (i - k + 1 > 0) {
      printf("%d ", SEG::query(1, 1, n, i - k + 1, i));
    }
  }
  return 0;
}
