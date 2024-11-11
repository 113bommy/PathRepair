#include <bits/stdc++.h>
using namespace std;
const long long N = 1000010, M = 1000000;
inline long long read() {
  long long s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long n, m, Q, a[N], b[N], c[N];
long long sum[N << 2], flag[N << 2];
void Build(long long x, long long l, long long r) {
  if (l == r) {
    sum[x] = c[l];
    return;
  }
  long long mid = (l + r) / 2;
  Build((x << 1), l, mid), Build((x << 1 | 1), mid + 1, r);
  sum[x] = max(sum[(x << 1)], sum[(x << 1 | 1)]);
}
inline void Push_Down(long long x) {
  sum[(x << 1)] += flag[x];
  sum[(x << 1 | 1)] += flag[x];
  flag[(x << 1)] += flag[x];
  flag[(x << 1 | 1)] += flag[x];
  flag[x] = 0;
}
void UpDate(long long u, long long v, long long l, long long r, long long x,
            long long k) {
  if (l >= u && r <= v) {
    sum[x] += k;
    flag[x] += k;
    return;
  }
  if (flag[x]) Push_Down(x);
  long long mid = (l + r) / 2;
  if (u <= mid) UpDate(u, v, l, mid, (x << 1), k);
  if (v > mid) UpDate(u, v, mid + 1, r, (x << 1 | 1), k);
  sum[x] = max(sum[(x << 1)], sum[(x << 1 | 1)]);
}
long long Ask(long long x, long long l, long long r) {
  if (flag[x]) Push_Down(x);
  if (sum[x] <= 0) return -1;
  if (l == r) return l;
  long long mid = (l + r) / 2;
  if (sum[(x << 1 | 1)] > 0) return Ask((x << 1 | 1), mid + 1, r);
  return Ask((x << 1), l, mid);
}
signed main() {
  n = read(), m = read();
  for (register long long i = 1; i <= n; i++) a[i] = read(), c[a[i]]++;
  for (register long long i = 1; i <= m; i++) b[i] = read(), c[b[i]]--;
  for (register long long i = M; i; i--) c[i] += c[i + 1];
  Build(1, 1, M);
  Q = read();
  for (register long long i = 1; i <= Q; i++) {
    long long opt, x, y;
    opt = read(), x = read(), y = read();
    if (opt == 1) {
      UpDate(1, a[x], 1, M, 1, -1);
      UpDate(1, y, 1, M, 1, 1);
      a[x] = y;
    }
    if (opt == 2) {
      UpDate(1, b[x], 1, M, 1, 1);
      UpDate(1, y, 1, M, 1, -1);
      b[x] = y;
    }
    printf("%lld\n", Ask(1, 1, M));
  }
  return 0;
}
