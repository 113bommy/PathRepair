#include <bits/stdc++.h>
using namespace std;
bool Handsome;
inline int rd() {
  register int x = 0;
  register char o = getchar();
  register bool O = 0;
  for (; o < 48 || 57 < o; o = getchar())
    if (o == '-') O = 1;
  for (; 48 <= o && o <= 57; o = getchar()) x = (x << 1) + (x << 3) + (o ^ 48);
  return O ? -x : x;
}
inline void Mi(int &x, int y) {
  if (x > y && (x = y))
    ;
}
inline void Mx(int &x, int y) {
  if (x < y && (x = y))
    ;
}
const int M = 3e4 + 5;
int n, P, sn, m, bl[M], a[M], c[M], f[M], f1[M][2], f2[M][2], l, r, ans[M],
    tot[M];
struct node {
  int x, y, id;
} A[M];
bool cmp(node a, node b) {
  if (bl[a.x] == bl[b.x]) return bl[a.x] & 1 ? a.y < b.y : a.y > b.y;
  return a.x < b.x;
}
int Mod(int x) {
  if (x >= P) x -= P;
  if (x < 0) x += P;
  return x;
}
int s[M << 2], t[M << 2], tp[M << 2], k[M << 2];
void calc(int p, int s) {
  int x, y;
  if (s > 0) {
    x = (1ll * f1[1 + s][0] * tp[p] + f1[1 + s][1] * t[p]) % P;
    y = (1ll * f1[2 + s][0] * tp[p] + f1[2 + s][1] * t[p]) % P;
  } else {
    x = (1ll * f2[1 - s][0] * tp[p] + f2[1 - s][1] * t[p]) % P;
    y = (1ll * f2[2 - s][0] * tp[p] + f2[2 - s][1] * t[p]) % P;
  }
  tp[p] = x;
  t[p] = y;
}
void down(int p) {
  if (!k[p]) return;
  calc(p << 1, k[p]);
  k[p << 1] += k[p];
  calc(p << 1 | 1, k[p]);
  k[p << 1 | 1] += k[p];
  k[p] = 0;
}
void chg(int x, int y, int z = 1, int l = 1, int r = n, int p = 1) {
  s[p] += y;
  if (l == r) {
    if (y == 1) {
      tp[p] = 1ll * f[z - 1] * c[l] % P;
      t[p] = 1ll * f[z] * c[l] % P;
    } else
      t[p] = tp[p] = 0;
    return;
  }
  down(p);
  int mid = (l + r) >> 1;
  if (x <= mid)
    chg(x, y, z, l, mid, p << 1), calc(p << 1 | 1, y), k[p << 1 | 1] += y;
  else
    chg(x, y, z + s[p << 1], mid + 1, r, p << 1 | 1);
  t[p] = Mod(t[p << 1] + t[p << 1 | 1]);
  tp[p] = Mod(tp[p << 1] + tp[p << 1 | 1]);
}
bool Most;
int main() {
  n = rd();
  P = rd();
  sn = sqrt(n);
  for (int i = 1, iend = n; i <= iend; ++i) bl[i] = (i - 1) / sn + 1;
  for (int i = 1, iend = n; i <= iend; ++i) a[i] = c[i] = rd();
  sort(c + 1, c + n + 1);
  for (int i = 1, iend = n; i <= iend; ++i)
    a[i] = lower_bound(c + 1, c + n + 1, a[i]) - c;
  f[1] = f[2] = 1;
  for (int i = 3, iend = n; i <= iend; ++i) f[i] = Mod(f[i - 2] + f[i - 1]);
  f1[1][0] = f1[2][1] = 1;
  for (int i = 3, iend = n; i <= iend; ++i) {
    f1[i][0] = Mod(f1[i - 2][0] + f1[i - 1][0]);
    f1[i][1] = Mod(f1[i - 2][1] + f1[i - 1][1]);
  }
  f2[1][1] = f2[2][0] = 1;
  for (int i = 3, iend = n; i <= iend; ++i) {
    f2[i][0] = Mod(f2[i - 2][0] - f2[i - 1][0]);
    f2[i][1] = Mod(f2[i - 2][1] - f2[i - 1][1]);
  }
  m = rd();
  for (int i = 1, iend = m; i <= iend; ++i)
    A[i].x = rd(), A[i].y = rd(), A[i].id = i;
  sort(A + 1, A + m + 1, cmp);
  l = 1;
  for (int i = 1, iend = m; i <= iend; ++i) {
    while (r < A[i].y) {
      ++r;
      if (++tot[a[r]] == 1) chg(a[r], 1);
    }
    while (l > A[i].x) {
      --l;
      if (++tot[a[l]] == 1) chg(a[l], 1);
    }
    while (r > A[i].y) {
      if (!--tot[a[r]]) chg(a[r], -1);
      --r;
    }
    while (l < A[i].x) {
      if (!--tot[a[l]]) chg(a[l], -1);
      ++l;
    }
    ans[A[i].id] = Mod(t[1]);
  }
  for (int i = 1, iend = m; i <= iend; ++i) printf("%d\n", ans[i]);
  return 0;
}
