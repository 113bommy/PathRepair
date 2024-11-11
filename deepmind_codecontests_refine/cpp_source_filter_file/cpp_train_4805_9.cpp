#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 500;
int n, m;
char s[N];
int gti(void) {
  char c = getchar();
  int ret = 0, st = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') st = -1;
  for (; isdigit(c); c = getchar()) ret = ret * 10 + c - '0';
  return ret * st;
}
struct segt {
  int lab, lba, rab, rba, lmx, rmx, mx, a, b;
  void set(int v) {
    if (v == 1)
      lab = 1, lba = 0, rab = 1, rba = 0, lmx = rmx = mx = a = 1, b = 0;
    else
      lba = 1, lab = 0, rba = 1, rab = 0, lmx = rmx = mx = b = 1, a = 0;
  }
} t[N << 2];
void pu(int v) {
  t[v].a = t[v << 1].a + max(t[v << 1 | 1].a - t[v << 1].b, 0);
  t[v].b = t[v << 1 | 1].b + max(t[v << 1].b - t[v << 1 | 1].a, 0);
  t[v].mx = max(t[v << 1].mx, t[v << 1 | 1].mx);
  t[v].mx = max(t[v].mx, max(t[v << 1].rmx + t[v << 1 | 1].lba,
                             t[v << 1 | 1].lmx + t[v << 1].rab));
  t[v].lmx = max(t[v << 1].lmx, t[v << 1].a + t[v << 1].b + t[v << 1 | 1].lba);
  t[v].lmx = max(t[v].lmx, t[v << 1 | 1].lmx - t[v << 1].b + t[v << 1].a);
  t[v].rmx =
      max(t[v << 1 | 1].rmx, t[v << 1 | 1].a + t[v << 1 | 1].b + t[v << 1].rab);
  t[v].rmx = max(t[v].rmx, t[v << 1].rmx - t[v << 1 | 1].a + t[v << 1 | 1].b);
  t[v].lab = max(t[v << 1].lab, t[v << 1].a - t[v << 1].b + t[v << 1 | 1].lab);
  t[v].rab =
      max(t[v << 1 | 1].rab, t[v << 1 | 1].a - t[v << 1 | 1].b + t[v << 1].rab);
  t[v].lba = max(t[v << 1].lba, t[v << 1].b - t[v << 1].a + t[v << 1 | 1].lba);
  t[v].rba =
      max(t[v << 1 | 1].rba, t[v << 1 | 1].b - t[v << 1 | 1].a + t[v << 1].rba);
}
void build(int v = 1, int l = 1, int r = n) {
  if (l == r)
    t[v].set(s[l] == ')');
  else {
    build(v << 1, l, ((l + r) >> 1));
    build(v << 1 | 1, ((l + r) >> 1) + 1, r);
    pu(v);
  }
}
void change(int loc, int v = 1, int l = 1, int r = n) {
  if (l == r)
    t[v].set(s[l] == ')');
  else {
    if (loc <= ((l + r) >> 1))
      change(loc, v << 1, l, ((l + r) >> 1));
    else
      change(loc, v << 1 | 1, ((l + r) >> 1) + 1, r);
    pu(v);
  }
}
int main(void) {
  n = gti(), m = gti();
  scanf("%s", s + 1);
  build();
  printf("%d\n", t[1].mx);
  for (int i = 1; i <= m; i++) {
    int a = gti(), b = gti();
    swap(s[a], s[b]);
    change(a);
    change(b);
    printf("%d\n", t[1].mx);
  }
  return 0;
}
