#include <bits/stdc++.h>
using namespace std;
const int INF = (-1u) / 2;
const long long int INF2 = (-1ull) / 2;
long long int a, b, i, d[1011000], j, k, n, m, timer = 0, l, r, x, y, A, cf, cm;
long long int c[1011000], cnt = 0, fl = 0, a2, a3 = -1000000, ans = 0, L, R,
                          mid, M;
pair<long long int, long long int> p[100010];
int main() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &n, &A, &cf, &cm, &m);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &a);
    p[i] = make_pair(a, i);
  }
  sort(p, p + n);
  for (i = 0; i < n; i++) {
    if (i) d[i] = d[i - 1];
    d[i] += p[i].first;
    ans += (A - p[i].first);
  }
  if (ans <= m) {
    printf("%I64d\n", n * cf + A * cm);
    for (i = 0; i < n; i++) {
      printf("%I64d ", A);
    }
    return 0;
  }
  fl = -1;
  ans = 0;
  i = n;
  x = m - ans;
  l = p[0].first;
  r = A + 1;
  while (l < r) {
    mid = (l + r) / 2ll;
    L = 0;
    R = n;
    while (L < R) {
      M = (L + R) / 2ll;
      if (p[M].first > mid)
        R = M;
      else
        L = M + 1ll;
    }
    R--;
    if ((mid * (R + 1ll)) - d[R] <= x)
      l = mid + 1ll;
    else
      r = mid;
  }
  r--;
  if (fl < r * cm + (n - i) * cf) {
    fl = r * cm + (n - i) * cf;
    k = i;
    b = r;
  }
  for (i = n - 1; i > 0; i--) {
    ans += A - p[i].first;
    if (ans <= m) {
      x = m - ans;
      l = p[0].first;
      r = A + 1ll;
      while (l < r) {
        mid = (l + r) / 2ll;
        L = 0;
        R = i;
        while (L < R) {
          M = (L + R) / 2ll;
          if (p[M].first > mid)
            R = M;
          else
            L = M + 1ll;
        }
        R--;
        if ((mid * (R + 1ll)) - d[R] <= x)
          l = mid + 1ll;
        else
          r = mid;
      }
      r--;
      if (fl < r * cm + (n - i) * cf) {
        fl = r * cm + (n - i) * cf;
        k = i;
        b = r;
      }
    }
  }
  printf("%I64d\n", fl);
  ans = 0;
  for (i = n - 1; i >= k; i--) {
    p[i].first = A;
    ans += (A - p[i].first);
  }
  ans = m - ans;
  for (i = 0; i < k; i++) {
    if (p[i].first <= b && b - p[i].first <= ans) {
      p[i].first = b;
      ans -= b - p[i].first;
    } else
      break;
  }
  for (i = 0; i < n; i++) {
    c[p[i].second] = p[i].first;
  }
  for (i = 0; i < n; i++) {
    printf("%I64d ", c[i]);
  }
  return 0;
}
