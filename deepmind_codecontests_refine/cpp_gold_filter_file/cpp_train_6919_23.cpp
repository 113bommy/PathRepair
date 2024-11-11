#include <bits/stdc++.h>
using namespace std;
int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
  return f * s;
}
struct node {
  int son[2], v, tag, s;
} t[100010 * 40];
int poi, n, m, k;
int calc(int l, int r) {
  int v = 0;
  for (int i = 1; i <= k; i <<= 1)
    v |= (((r / i - (l - 1) / i) -
           (i * 2 <= k ? r / i / 2 - (l - 1) / i / 2 : 0)) &
          1) *
         i;
  return v;
}
void pushup(int x) {
  if (t[x].tag)
    t[x].s = t[x].v;
  else
    t[x].s = t[t[x].son[0]].s ^ t[t[x].son[1]].s;
}
void modify(int &x, int l, int r, int LL, int RR, int v) {
  if (!x) x = ++poi;
  t[x].v = calc(l, r);
  if (LL <= l && r <= RR) return t[x].tag += v, pushup(x);
  if (LL <= (l + r >> 1)) modify(t[x].son[0], l, (l + r >> 1), LL, RR, v);
  if (RR > (l + r >> 1)) modify(t[x].son[1], (l + r >> 1) + 1, r, LL, RR, v);
  pushup(x);
}
struct opt {
  int x, l, r, v;
} a[100010 << 1];
int cnt, wei[100010];
bool operator<(opt x, opt y) { return x.x < y.x; }
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= m; i++) {
    int xl = read(), yl = read(), xr = read(), yr = read();
    a[++cnt] = (opt){xl, yl, yr, 1}, a[++cnt] = (opt){xr + 1, yl, yr, -1};
  }
  sort(a + 1, a + cnt + 1);
  int lim = 1, l = 0, rt = 0;
  while (lim <= k) lim <<= 1, l++;
  for (int i = 1, j; i <= cnt; i = j) {
    int vn = t[rt].s, vm = calc(a[i - 1].x, a[i].x - 1), s1 = 0, s2 = 0;
    for (int b = l; ~b; b--)
      s1 ^= (vn >> b & 1), s2 ^= (vm >> b & 1), wei[b] ^= s1 & s2;
    for (j = i; j <= cnt && a[i].x == a[j].x; j++)
      modify(rt, 1, n, a[j].l, a[j].r, a[j].v);
  }
  int fin = 0;
  for (int i = 0; i < l; i++)
    if (wei[i] ^ wei[i + 1]) fin = 1;
  if (fin)
    puts("Hamed");
  else
    puts("Malek");
  return 0;
}
