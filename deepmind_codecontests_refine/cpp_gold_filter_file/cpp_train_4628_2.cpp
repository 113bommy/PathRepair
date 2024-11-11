#include <bits/stdc++.h>
using namespace std;
long long sum[102400 << 2], sub[102400 << 2], mark[102400 << 2];
int lp[102400 << 2], rp[102400 << 2];
void build(int u, int l, int r) {
  lp[u] = l;
  rp[u] = r;
  if (l < r) {
    build(u << 1, l, (l + r) >> 1);
    build(u << 1 | 1, ((l + r) >> 1) + 1, r);
  } else
    mark[u] = l;
}
void update(int u) {
  sum[u] =
      sum[u << 1] + sum[u << 1 | 1] + (long long)(rp[u] - lp[u] + 1) * sub[u];
}
long long query(int u, int l, int r) {
  if (rp[u] < l || lp[u] > r) return 0;
  if (l <= lp[u] && rp[u] <= r) return sum[u];
  int m = (lp[u] + rp[u]) >> 1;
  return query(u << 1, l, r) + query(u << 1 | 1, l, r) +
         max(min(r, rp[u]) - max(l, lp[u]) + 1, 0) * sub[u];
}
void clear(int u, int x) {
  if (mark[u]) {
    sub[u] += abs(mark[u] - (long long)x);
    sum[u] += (long long)(rp[u] - lp[u] + 1) * abs(mark[u] - (long long)x);
    mark[u] = 0;
  } else {
    if (lp[u] == rp[u]) return;
    clear(u << 1, x);
    clear(u << 1 | 1, x);
    update(u);
  }
}
void change(int u, int l, int r, int x) {
  if (r < lp[u] || l > rp[u]) return;
  if (l <= lp[u] && rp[u] <= r) {
    clear(u, x);
    mark[u] = x;
    return;
  }
  if (mark[u]) {
    mark[u << 1] = mark[u << 1 | 1] = mark[u];
    mark[u] = 0;
  }
  change(u << 1, l, r, x);
  change(u << 1 | 1, l, r, x);
  update(u);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  build(1, 1, n);
  for (int i = 0; i < m; i++) {
    int tp, l, r, c;
    scanf("%d%d%d", &tp, &l, &r);
    if (tp - 1)
      cout << query(1, l, r) << endl;
    else {
      scanf("%d", &c);
      change(1, l, r, c);
    }
  }
  return 0;
}
