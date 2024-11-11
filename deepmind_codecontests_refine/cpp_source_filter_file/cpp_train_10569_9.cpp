#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
inline long long read() {
  register long long x = 0, f = 0;
  register char c = getchar();
  while (c < '0' || c > '9') f |= c == '-', c = getchar();
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return f ? -x : x;
}
long long n, T;
struct node {
  long long p, t, sum, ltime, rtime;
} s[N];
inline bool cmp1(const node &A, const node &B) { return A.p * B.t > A.t * B.p; }
inline bool cmp2(const node &A, const node &B) { return A.p < B.p; }
bool check(double c) {
  double mx1 = 0, mx2 = 0;
  for (long long i = 1; i <= n; ++i) {
    if (s[i].p != s[i - 1].p) mx2 = mx1;
    if (s[i].p * (1.0 - c * s[i].rtime / T) < mx2) return false;
    mx1 = max(mx1, s[i].p * (1.0 - c * s[i].ltime / T));
  }
  return true;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; ++i) s[i].p = read();
  for (long long i = 1; i <= n; ++i) T += (s[i].t = read());
  sort(s + 1, s + 1 + n, cmp1);
  for (long long i = 1; i <= n; ++i) s[i].sum = s[i - 1].sum + s[i].t;
  for (long long i = 1, j = 1; i <= n; ++i) {
    j = i;
    while (j < n && s[i].p * s[j].t == s[i].t * s[j].p) j++;
    for (long long k = i; k <= j; ++k)
      s[k].ltime = s[i - 1].sum + s[k].t, s[k].rtime = s[j].sum;
    i = j;
  }
  sort(s + 1, s + 1 + n, cmp2);
  double l = 0, r = 1, mid, ans;
  while (r - l > 1e-7) {
    mid = (l + r) / 2;
    if (check(mid))
      l = mid, ans = mid;
    else
      r = mid;
  }
  printf("%.11f\n", ans);
  return 0;
}
