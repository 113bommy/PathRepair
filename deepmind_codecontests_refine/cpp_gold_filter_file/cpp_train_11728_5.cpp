#include <bits/stdc++.h>
int n, m;
long long b, d;
long long a[200000];
long long left[200000], right[200000];
int ans;
int lv, rv;
int getlv() {
  int j = 0;
  long long sum = 0;
  int re = 0;
  long long k;
  for (int i = 0; i < n; ++i) {
    if (i >= m) break;
    k = i + (i + 1) * d;
    if (k >= n - 1) k = n - 1;
    while (j <= k) {
      sum += left[j];
      ++j;
    }
    if (sum >= b)
      sum -= b;
    else
      re += 1;
  }
  return re;
}
int getrv() {
  int j = n - 1;
  long long sum = 0;
  int re = 0;
  long long k;
  for (int i = n - 1; i >= 0; --i) {
    if (i < m) break;
    k = i - (n - i) * d;
    if (k < 0) k = 0;
    while (j >= k) {
      sum += right[j];
      --j;
    }
    if (sum >= b)
      sum -= b;
    else
      re += 1;
  }
  return re;
}
int check(int c) {
  for (int i = 0; i < n; ++i) {
    if (c < a[i]) {
      left[i] = c;
      right[i] = a[i] - c;
      c = 0;
    } else {
      left[i] = a[i];
      right[i] = 0;
      c = c - a[i];
    }
  }
  lv = getlv();
  rv = getrv();
  if (lv >= rv && lv < ans) ans = lv;
  if (rv >= lv && rv < ans) ans = rv;
  if (lv > rv) return 0;
  return 1;
}
int main() {
  scanf("%d %I64d %I64d", &n, &d, &b);
  for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
  m = (n + 1) / 2;
  long long l = 0, r = n * b, mid, lv, rv, c;
  ans = n;
  while (r - l > 1) {
    mid = (l + r) / 2;
    c = mid;
    if (check(c) == 0)
      l = mid;
    else
      r = mid;
  }
  check(l);
  check(r);
  printf("%d\n", ans);
  return 0;
}
