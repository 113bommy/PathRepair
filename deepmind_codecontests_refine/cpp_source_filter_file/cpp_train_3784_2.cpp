#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7;
const int INF = 0x3f3f3f3f;
int a[maxn], pos[maxn];
int sum1[maxn << 2], sum2[maxn << 2], min1[maxn << 2], min2[maxn << 2],
    lazy[maxn << 2];
long long ans;
void solve(int i, int v, int s) {
  if (v < min1[i]) {
    min2[i] = min1[i];
    sum2[i] = sum1[i];
    min1[i] = v;
    sum1[i] = s;
  } else if (v == min1[i])
    sum1[i] += s;
  else if (v < min2[i]) {
    min2[i] = v;
    sum2[i] = s;
  } else if (v == min2[i])
    sum2[i] += s;
}
void pushup(int i) {
  sum1[i] = sum1[i * 2];
  min1[i] = min1[i * 2];
  sum2[i] = sum2[i * 2];
  min2[i] = min2[i * 2];
  solve(i, min2[i * 2 + 1], sum2[i * 2 + 1]);
  solve(i, min1[i * 2 + 1], sum1[i * 2 + 1]);
}
void pushdown(int i) {
  if (lazy[i]) {
    min1[i * 2] += lazy[i];
    min1[i * 2 + 1] += lazy[i];
    min2[i * 2] += lazy[i];
    min2[i * 2 + 1] += lazy[i];
    lazy[i * 2] = lazy[i];
    lazy[i * 2 + 1] = lazy[i];
    lazy[i] = 0;
  }
}
void build(int i, int l, int r) {
  min1[i] = 0;
  min2[i] = INF;
  sum1[i] = (r - l + 1);
  sum2[i] = 0;
  if (l == r) return;
  int m = (l + r) >> 1;
  build(i * 2, l, m);
  build(i * 2 + 1, m + 1, r);
  pushup(i);
}
void update(int i, int l, int r, int x, int y, int v) {
  if (x <= l && r <= y) {
    min1[i] += v;
    min2[i] += v;
    lazy[i] += v;
    return;
  }
  pushdown(i);
  int m = (l + r) >> 1;
  if (x <= m) update(i * 2, l, m, x, y, v);
  if (y > m) update(i * 2 + 1, m + 1, r, x, y, v);
  pushup(i);
}
void query(int i, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    if (min1[i] <= 2) ans += sum1[i];
    if (min2[i] <= 2) ans += sum2[i];
    return;
  }
  pushdown(i);
  int m = (l + r) >> 1;
  if (x <= m) query(i * 2, l, m, x, y);
  if (y > m) query(i * 2 + 1, m + 1, r, x, y);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    update(1, 1, n, 1, i, 1);
    int x = a[pos[a[i]] - 1], y = a[pos[a[i]] + 1];
    if (x && x < i) update(1, 1, n, 1, x, -1);
    if (y && y < i) update(1, 1, n, 1, y, -1);
    query(1, 1, n, 1, i);
  }
  printf("%lld\n", ans - n);
}
