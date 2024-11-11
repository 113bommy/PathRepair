#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int i, j, k, n, m, ch, ff, nx, ny, tmp, x, y, nn;
long long ans[N];
int num[N << 1], Lsx[N << 1], Lsy[N << 1];
struct cc {
  int l, r, x, fg;
} A[N << 1];
void R(int &x) {
  ff = x = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') ff = 1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (ff) x = -x;
}
bool cmp(const cc &a, const cc &b) { return a.x < b.x; }
int findy(int x) {
  int l = 1, r = ny, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (Lsy[mid] == x) return mid;
    if (Lsy[mid] < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return l;
}
void W(long long x) {
  if (x >= 10) W(x / 10);
  putchar(x % 10 + '0');
}
int main() {
  R(n);
  R(m);
  for (i = 1; i <= n; i++) {
    R(x);
    R(y);
    A[++nn].l = y - m + 1;
    A[nn].r = y + 1;
    A[nn].x = x - m + 1;
    A[nn].fg = 1;
    A[++nn].l = y - m + 1;
    A[nn].r = y + 1;
    A[nn].x = x + 1;
    A[nn].fg = -1;
    Lsx[++nx] = x - m + 1;
    Lsx[++nx] = x + 1;
    Lsy[++ny] = y - m + 1;
    Lsy[++ny] = y + 1;
  }
  sort(Lsx + 1, Lsx + nx + 1);
  sort(Lsy + 1, Lsy + ny + 1);
  tmp = nx;
  Lsx[nx + 1] = Lsx[nx] + 1;
  nx = 0;
  for (i = 1; i <= tmp; i++)
    if (Lsx[i] != Lsx[i + 1]) Lsx[++nx] = Lsx[i];
  tmp = ny;
  Lsy[ny + 1] = Lsy[ny] + 1;
  ny = 0;
  for (i = 1; i <= tmp; i++)
    if (Lsy[i] != Lsy[i + 1]) Lsy[++ny] = Lsy[i];
  sort(A + 1, A + nn + 1, cmp);
  for (i = 1; i <= nn; i++) {
    A[i].l = findy(A[i].l);
    A[i].r = findy(A[i].r);
    for (j = A[i].l; j < A[i].r; j++) {
      if (num[j])
        ans[num[j]] -= (long long)(Lsx[nx] - A[i].x) * (Lsy[j + 1] - Lsy[j]);
      num[j] += A[i].fg;
      if (num[j])
        ans[num[j]] += (long long)(Lsx[nx] - A[i].x) * (Lsy[j + 1] - Lsy[j]);
    }
  }
  for (i = 1; i <= n; i++) W(ans[i]), putchar(' ');
  puts("");
}
