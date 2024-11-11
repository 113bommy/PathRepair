#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, f = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar())
    sum = ((sum << 1) + (sum << 3) + (ch ^ 48));
  return f ? -sum : sum;
}
void write(const long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
char getc() {
  char c = getchar();
  while (!isalpha(c)) c = getchar();
  return c;
}
long long n, m, a[440000], x, y;
long long sum[440000 << 2], lmx[440000 << 2], rmx[440000 << 2],
    lmn[440000 << 2], rmn[440000 << 2], la[440000 << 2], ra[440000 << 2],
    ans[440000 << 2], aaa[440000 << 2];
void pushup(long long rt) {
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
  lmx[rt] = max(lmx[rt << 1], sum[rt << 1] + lmx[rt << 1 | 1]),
  rmx[rt] = max(rmx[rt << 1 | 1], sum[rt << 1 | 1] + rmx[rt << 1]);
  lmn[rt] = min(lmn[rt << 1], sum[rt << 1] + lmn[rt << 1 | 1]),
  rmn[rt] = min(rmn[rt << 1 | 1], sum[rt << 1 | 1] + rmn[rt << 1]);
  la[rt] = max(max(la[rt << 1], la[rt << 1 | 1] - sum[rt << 1]),
               ans[rt << 1] + lmx[rt << 1 | 1]);
  ra[rt] = max(max(ra[rt << 1 | 1], ra[rt << 1] + sum[rt << 1 | 1]),
               ans[rt << 1 | 1] - rmn[rt << 1]);
  ans[rt] =
      max(ans[rt << 1] + sum[rt << 1 | 1], ans[rt << 1 | 1] - sum[rt << 1]);
  aaa[rt] =
      max(max(aaa[rt << 1], aaa[rt << 1 | 1]),
          max(la[rt << 1 | 1] - rmn[rt << 1], ra[rt << 1] + lmx[rt << 1 | 1]));
}
void build(long long rt, long long l, long long r) {
  if (l == r)
    return sum[rt] = a[l], lmx[rt] = rmx[rt] = max(a[l], 0ll),
           lmn[rt] = rmn[rt] = min(a[l], 0ll),
           la[rt] = ra[rt] = ans[rt] = aaa[rt] = 1, void();
  long long mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  pushup(rt);
}
void updata(long long rt, long long l, long long r, long long pos,
            long long k) {
  if (l == r)
    return sum[rt] = k, lmx[rt] = rmx[rt] = max(k, 0ll),
           lmn[rt] = rmn[rt] = min(k, 0ll),
           la[rt] = ra[rt] = ans[rt] = aaa[rt] = 1, void();
  long long mid = (l + r) >> 1;
  if (pos <= mid)
    updata(rt << 1, l, mid, pos, k);
  else
    updata(rt << 1 | 1, mid + 1, r, pos, k);
  pushup(rt);
}
int main() {
  n = read() * 2 - 2, m = read();
  for (register long long i = (1); i <= (n); i++)
    a[i] = getchar() == '(' ? 1 : -1;
  build(1, 1, n);
  write(aaa[1]), puts("");
  for (register long long i = (1); i <= (m); i++) {
    x = read(), y = read();
    if (a[x] ^ a[y]) {
      swap(a[x], a[y]);
      updata(1, 1, n, x, a[x]);
      updata(1, 1, n, y, a[y]);
    }
    write(aaa[1]), puts("");
  }
}
