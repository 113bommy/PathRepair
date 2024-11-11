#include <bits/stdc++.h>
using namespace std;
int n, q, a[200005];
long long s, ans, t[800005], lz[800005];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = (x + (x << 2) << 1) + (ch ^ 48);
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}
void build(int i, int l, int r) {
  if (l == r) {
    s += a[l], t[i] = s;
    return;
  }
  int mid = l + r >> 1;
  build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r),
      t[i] = max(t[i << 1], t[i << 1 | 1]);
}
void psd(int i) {
  if (lz[i]) {
    int li = i << 1, ri = li | 1;
    t[li] += lz[i], t[ri] += lz[i], lz[li] += lz[i], lz[ri] += lz[i], lz[i] = 0;
  }
}
void add(int i, int l, int r, int x, int y, int z) {
  if (x <= l && y >= r) {
    t[i] += z, lz[i] += z;
    return;
  }
  psd(i);
  int mid = l + r >> 1;
  if (x <= mid) add(i << 1, l, mid, x, y, z);
  if (y > mid) add(i << 1 | 1, mid + 1, r, x, y, z);
  t[i] = max(t[i << 1], t[i << 1 | 1]);
}
int find(int i, int l, int r, long long x) {
  if (l == r) {
    ans = t[i];
    return l;
  }
  psd(i);
  int mid = l + r >> 1;
  if (t[i << 1] >= x) return find(i << 1, l, mid, x);
  return find(i << 1 | 1, mid + 1, r, x);
}
int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  build(1, 1, n);
  while (q--) {
    int x = read(), y = read();
    bool fl = 1;
    add(1, 1, n, x, n, y - a[x]), a[x] = y, x = 0, ans = a[1];
    if (!ans) {
      puts("1");
      continue;
    }
    while (x != n) {
      x = find(1, 1, n, ans << 1);
      if (ans == (a[x] << 1)) {
        write(x), putchar('\n'), fl = 0;
        break;
      }
    }
    if (fl) puts("-1");
  }
  return 0;
}
