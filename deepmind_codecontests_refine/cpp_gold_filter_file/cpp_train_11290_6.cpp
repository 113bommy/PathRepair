#include <bits/stdc++.h>
using namespace std;
const int seed = 131;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  return x * f;
}
struct node {
  int l, r;
  unsigned long long hash1, hash2;
} tree[300000 * 4 + 10];
int n, a[300000 + 10];
unsigned long long Bit[300000 + 10];
inline void up(int t) {
  tree[t].hash1 = tree[t << 1].hash1 * Bit[tree[t].r - tree[t << 1].r] +
                  tree[t << 1 | 1].hash1;
  tree[t].hash2 = tree[t << 1 | 1].hash2 * Bit[tree[t << 1].r - tree[t].l + 1] +
                  tree[t << 1].hash2;
}
inline void build(int t, int l, int r) {
  tree[t].l = l;
  tree[t].r = r;
  tree[t].hash1 = tree[t].hash2 = 0;
  if (l == r) return;
  int mid = l + r >> 1;
  build(t << 1, l, mid);
  build(t << 1 | 1, mid + 1, r);
  up(t);
}
inline void update(int t, int k, int x) {
  if (tree[t].l > k || tree[t].r < k) return;
  if (tree[t].l == k && tree[t].r == k) {
    if (x)
      tree[t].hash1 = tree[t].hash2 = 1;
    else
      tree[t].hash1 = tree[t].hash2 = 0;
    return;
  }
  update(t << 1, k, x);
  update(t << 1 | 1, k, x);
  up(t);
}
inline unsigned long long query1(int t, int l, int r) {
  if (l > r) return 0;
  if (l == tree[t].l && tree[t].r == r) return tree[t].hash1;
  int mid = tree[t << 1].r;
  if (r <= mid)
    return query1(t << 1, l, r);
  else if (l > mid)
    return query1(t << 1 | 1, l, r);
  else
    return query1(t << 1, l, mid) * Bit[r - mid] +
           query1(t << 1 | 1, mid + 1, r);
}
inline unsigned long long query2(int t, int l, int r) {
  if (l > r) return 0;
  if (l == tree[t].l && tree[t].r == r) return tree[t].hash2;
  int mid = tree[t << 1].r;
  if (r <= mid)
    return query2(t << 1, l, r);
  else if (l > mid)
    return query2(t << 1 | 1, l, r);
  else
    return query2(t << 1 | 1, mid + 1, r) * Bit[mid - l + 1] +
           query2(t << 1, l, mid);
}
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i) a[i] = read();
  Bit[0] = 1;
  for (register int i = 1; i <= n; ++i) Bit[i] = Bit[i - 1] * seed;
  build(1, 1, n);
  for (register int i = 1; i <= n; ++i) {
    update(1, a[i], 1);
    int d = min(a[i] - 1, n - a[i]);
    if (!d) continue;
    if (query2(1, a[i] - d, a[i] - 1) ^ query1(1, a[i] + 1, a[i] + d)) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
