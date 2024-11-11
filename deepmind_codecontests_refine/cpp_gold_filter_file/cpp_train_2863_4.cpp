#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
const int maxn = 2e5 + 7;
const long long mod = 1e9 + 7;
inline long long read() {
  long long x = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || '9' < ch) f |= ch == '-', ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
void out(long long x) {
  int stackk[20];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  int top = 0;
  while (x) stackk[++top] = x % 10, x /= 10;
  while (top) putchar(stackk[top--] + '0');
}
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long n, m, k, a[maxn];
long long p = 233, base[maxn];
long long base2[maxn];
char ss[maxn];
void init() {
  base2[0] = base[0] = 1;
  for (int i = (1); i <= (200002); ++i)
    base[i] = (base[i - 1] * p) % mod, base2[i] = (base2[i - 1] * p + 1) % mod;
}
struct Node {
  long long l, r, sum, lz;
} t[maxn * 4];
void push_up(int st) {
  int len = t[st * 2 + 1].r - t[st * 2 + 1].l + 1;
  t[st].sum = (base[len] * t[st * 2].sum % mod + t[st * 2 + 1].sum) % mod;
}
void push_down(int st) {
  if (t[st].lz != -1) {
    t[st * 2].lz = t[st].lz, t[st * 2 + 1].lz = t[st].lz;
    t[st * 2].sum = base2[t[st * 2].r - t[st * 2].l] * t[st].lz % mod;
    t[st * 2 + 1].sum =
        base2[t[st * 2 + 1].r - t[st * 2 + 1].l] * t[st].lz % mod;
    t[st].lz = -1;
  }
}
void build(int st, int l, int r) {
  t[st].l = l, t[st].r = r, t[st].lz = -1;
  if (l == r) {
    t[st].sum = ss[l] - '0' + 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(st * 2, l, mid), build(st * 2 + 1, mid + 1, r);
  push_up(st);
}
void update(int st, int l, int r, int ql, int qr, long long num) {
  if (ql <= l && qr >= r) {
    t[st].lz = num;
    t[st].sum = base2[(r - l)] * num % mod;
    return;
  }
  push_down(st);
  int mid = (l + r) >> 1;
  if (ql <= mid) update(st * 2, l, mid, ql, qr, num);
  if (qr > mid) update(st * 2 + 1, mid + 1, r, ql, qr, num);
  push_up(st);
}
long long query(int st, int l, int r, int ql, int qr) {
  if (ql > qr) return 0;
  if (ql <= l && qr >= r) return t[st].sum;
  push_down(st);
  int mid = (l + r) >> 1;
  if (qr <= mid)
    return query(st * 2, l, mid, ql, qr);
  else if (ql > mid)
    return query(st * 2 + 1, mid + 1, r, ql, qr);
  else
    return (query(st * 2, l, mid, ql, mid) * base[qr - (mid + 1) + 1] +
            query(st * 2 + 1, mid + 1, r, mid + 1, qr)) %
           mod;
  push_up(st);
}
int main() {
  n = read(), m = read(), k = read();
  init();
  scanf("%s", ss + 1);
  build(1, 1, n);
  for (int ii = (1); ii <= (m + k); ++ii) {
    int op, x, y, z;
    op = read(), x = read(), y = read(), z = read();
    if (op == 1)
      update(1, 1, n, x, y, z + 1);
    else {
      if (y - x + 1 == z) {
        puts("YES");
        continue;
      }
      long long t1 = query(1, 1, n, x + z, y);
      long long t2 = query(1, 1, n, x, y - z);
      if (t1 % mod == t2 % mod)
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
