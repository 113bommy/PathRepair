#include <bits/stdc++.h>
using namespace std;
const long long N = 2050, S = (long long)1e18;
long long n, L;
long long p[N], hl[N], hr[N], s1[N], s2[N], s3[N];
long long qry(long long id, long long x) {
  long long ras;
  printf("? %I64d %I64d\n", id, x);
  fflush(stdout);
  scanf("%I64d", &ras);
  return ras;
}
long long gval(long long id, long long w) {
  long long sl, sr, mid;
  sl = 0;
  sr = S;
  while (sl < sr) {
    mid = (sl + sr) >> 1;
    if (qry(id, mid) >= w)
      sr = mid;
    else
      sl = mid + 1;
  }
  return sl;
}
long long getkth(long long l, long long r, long long K) {
  long long pos, val, i, W, nvl, t1, t2, t3, top;
  pos = rand() % (r - l + 1) + l;
  W = (L / n * (K));
  val = gval(p[pos], W);
  t1 = t2 = t3 = 0;
  for (i = l; i <= r; i++) {
    nvl = qry(p[i], val);
    if (nvl < W)
      s1[++t1] = p[i];
    else if (nvl == W)
      s2[++t2] = p[i];
    else
      s3[++t3] = p[i];
  }
  top = l;
  for (i = 1; i <= t1; i++) p[top++] = s1[i];
  for (i = 1; i <= t2; i++) p[top++] = s2[i];
  for (i = 1; i <= t3; i++) p[top++] = s3[i];
  if (t1 > K - l)
    return getkth(l, l + t1 - 1, K);
  else if (t3 > r - K)
    return getkth(r - t3 + 1, r, K);
  else
    return val;
}
void Solve(long long l, long long r, long long wl, long long wr) {
  if (l == r) {
    hl[p[l]] = wl;
    hr[p[r]] = wr;
    return;
  }
  long long mid, W;
  mid = (l + r) >> 1;
  W = getkth(l, r, mid);
  Solve(l, mid, wl, W);
  Solve(mid + 1, r, W, wr);
}
int main() {
  long long i;
  scanf("%I64d%I64d", &n, &L);
  for (i = 1; i <= n; i++) p[i] = i;
  Solve(1, n, 0, S);
  puts("!");
  for (i = 1; i <= n; i++) printf("%I64d\n%I64d\n", hl[i], hr[i]);
  fflush(stdout);
  return 0;
}
