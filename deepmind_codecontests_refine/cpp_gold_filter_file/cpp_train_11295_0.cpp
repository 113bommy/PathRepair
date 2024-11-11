#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0;
  register char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return x;
}
const int N = 1e6 + 5;
const int M = 1e4 + 5;
struct each {
  int x, y, z, ty;
  each(int xx = 0, int yy = 0, int zz = 0, int t = 0) {
    x = xx, y = yy, z = zz, ty = t;
  }
} a[N], tmp[N];
struct bit {
  int a[N], lim;
  void add(int x, int y) {
    if (x < 1) return;
    while (x <= lim) {
      a[x] += y;
      x += x & -x;
    }
  }
  int query(int x) {
    int ans = 0;
    while (x) {
      ans += a[x];
      x -= x & -x;
    }
    return ans;
  }
} b[3];
int n, q, cnt, t[N], ans[N];
void solve(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  int L = l, R = mid + 1, cnt = l;
  solve(l, mid), solve(mid + 1, r);
  while (L <= mid && R <= r)
    if (a[L].x <= a[R].x) {
      if (a[L].ty < 3) b[a[L].ty].add(a[L].y, a[L].z);
      tmp[cnt++] = a[L++];
    } else {
      if (a[R].ty > 2) ans[a[R].z] += b[a[R].ty - 3].query(a[R].y);
      tmp[cnt++] = a[R++];
    }
  while (R <= r) {
    if (a[R].ty > 2) ans[a[R].z] += b[a[R].ty - 3].query(a[R].y);
    tmp[cnt++] = a[R++];
  }
  for (int i = l; i < L; i++)
    if (a[i].ty < 3) b[a[i].ty].add(a[i].y, -a[i].z);
  while (L <= mid) tmp[cnt++] = a[L++];
  for (int i = l; i <= r; i++) a[i] = tmp[i];
}
int main() {
  n = read(), q = read();
  for (int i = 1; i <= q; i++) {
    int ty = read();
    if (ty == 1) {
      int di = read(), x = read(), y = read(), len = read();
      if (di == 1) {
        a[++cnt] = each(x, y, 1, 0);
        a[++cnt] = each(x + len + 1, y, -1, 0);
        a[++cnt] = each(x, x + y + len + 1, -1, 1);
        a[++cnt] = each(x + len + 1, x + y + len + 1, 1, 1);
      }
      if (di == 2) {
        a[++cnt] = each(x, y + 1, -1, 0);
        a[++cnt] = each(x + len + 1, y + 1, 1, 0);
        a[++cnt] = each(x, y - x - len + n, 1, 2);
        a[++cnt] = each(x + len + 1, y - x - len + n, -1, 2);
      }
      if (di == 3) {
        a[++cnt] = each(x + 1, y, -1, 0);
        a[++cnt] = each(x - len, y, 1, 0);
        a[++cnt] = each(x + 1, y - x + len + 1 + n, 1, 2);
        a[++cnt] = each(x - len, y - x + len + 1 + n, -1, 2);
      }
      if (di == 4) {
        a[++cnt] = each(x + 1, y + 1, 1, 0);
        a[++cnt] = each(x - len, y + 1, -1, 0);
        a[++cnt] = each(x + 1, y + x - len, -1, 1);
        a[++cnt] = each(x - len, y + x - len, 1, 1);
      }
    } else {
      int x = read(), y = read();
      a[++cnt] = each(x, y, i, 3);
      a[++cnt] = each(x, x + y, i, 4);
      a[++cnt] = each(x, y - x + n, i, 5);
      t[i] = 1;
    }
  }
  b[0].lim = n;
  b[1].lim = b[2].lim = n * 2;
  solve(1, cnt);
  for (int i = 1; i <= q; i++)
    if (t[i]) printf("%d\n", ans[i]);
  return 0;
}
