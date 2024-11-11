#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct data {
  int l, r, id;
  long long ans;
} q[N];
int a[N], n, m, k, size, tot, blk[N], L, R, sum[N], cnt[N * 20] = {1};
long long res;
inline char tc(void) {
  static char fl[100000], *A = fl, *B = fl;
  return A == B && (B = (A = fl) + fread(fl, 1, 100000, stdin), A == B) ? EOF
                                                                        : *A++;
}
inline void read(int &x) {
  x = 0;
  char ch;
  while (!isdigit(ch = tc()))
    ;
  while (x = (x << 3) + (x << 1) + ch - '0', isdigit(ch = tc()))
    ;
}
inline void write(long long x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline bool cmp1(data a, data b) {
  return blk[a.l] < blk[b.l] ||
         (blk[a.l] == blk[b.l] && (blk[a.l] & 1 ? a.r < b.r : a.r > b.r));
}
inline bool cmp2(data a, data b) { return a.id < b.id; }
inline void add(int x) {
  res += cnt[k ^ sum[x]];
  ++cnt[sum[x]];
}
inline void del(int x) {
  --cnt[sum[x]];
  res -= cnt[k ^ sum[x]];
}
int main() {
  register int i;
  read(n);
  read(m);
  read(k);
  size = sqrt(n);
  for (i = 1; i <= n; ++i)
    read(a[i]), blk[i] = (i - 1) / size + 1, sum[i] = sum[i - 1] ^ a[i];
  for (i = 1; i <= m; ++i) read(q[i].l), read(q[i].r), q[i].id = i;
  sort(q + 1, q + m + 1, cmp1);
  L = 1;
  R = 0;
  for (i = 1; i <= m; ++i) {
    while (L > q[i].l) add(--L - 1);
    while (L < q[i].l) del(-1 + L++);
    while (R < q[i].r) add(++R);
    while (R > q[i].r) del(R--);
    q[i].ans = res;
  }
  for (sort(q + 1, q + m + 1, cmp2), i = 1; i <= m; ++i)
    write(q[i].ans), putchar('\n');
  return 0;
}
