#include <bits/stdc++.h>
using namespace std;
const long long S = (long long)1e18;
long long n, L, p[2005], ansl[2005], ansr[2005], s1[2005], s2[2005], s3[2005];
long long rd() {
  long long x = 0, tp = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') tp = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x * 10 + c - '0');
    c = getchar();
  }
  return x * tp;
}
long long query(long long id, long long x) {
  printf("? %lld %lld\n", id, x);
  fflush(stdout);
  return rd();
}
long long getpos(long long id, long long x) {
  long long l = 0, r = S, mid, pos = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (query(id, mid) >= x)
      r = mid - 1;
    else
      l = mid + 1, pos = mid;
  }
  return pos + 1;
}
long long get_kth(long long l, long long r, long long k) {
  long long val, pos = rand() % (r - l + 1) + l, W = L / n * k, t1 = 0, t2 = 0,
                 t3 = 0, Top = l - 1;
  val = getpos(p[pos], W);
  for (int i = l; i <= r; i++) {
    long long tmp = query(p[i], val);
    if (tmp > W)
      s1[++t1] = p[i];
    else if (tmp == W)
      s2[++t2] = p[i];
    else
      s3[++t3] = p[i];
  }
  for (int i = 1; i <= t1; i++) p[++Top] = s1[i];
  for (int i = 1; i <= t2; i++) p[++Top] = s2[i];
  for (int i = 1; i <= t3; i++) p[++Top] = s3[i];
  if (t1 > k - l)
    return get_kth(l, l + t1 - 1, k);
  else if (t3 > r - k)
    return get_kth(r - t3 + 1, r, k);
  return val;
}
void solve(long long l, long long r, long long sl, long long sr) {
  if (l == r) {
    ansl[p[l]] = sl, ansr[p[r]] = sr;
    return;
  }
  long long k = (l + r) >> 1, mid;
  mid = get_kth(l, r, k);
  solve(l, k, sl, mid), solve(k + 1, r, mid, sr);
}
int main() {
  n = rd(), L = rd();
  for (int i = 1; i <= n; i++) p[i] = i;
  solve(1, n, 0, S);
  printf("!\n");
  for (int i = 1; i <= n; i++) printf("%lld %lld\n", ansl[i], ansr[i]);
  fflush(stdout);
  return 0;
}
