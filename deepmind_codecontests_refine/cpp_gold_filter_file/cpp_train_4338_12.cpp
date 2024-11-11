#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, m, cl, ce, v;
  scanf("%lld %lld %lld %lld %lld", &n, &m, &cl, &ce, &v);
  long long l[cl + 2], e[ce + 2];
  for (long long i = 1; i <= cl; i++) scanf("%lld", &l[i]);
  for (long long i = 1; i <= ce; i++) scanf("%lld", &e[i]);
  l[0] = e[0] = l[cl + 1] = e[ce + 1] = 1000000000000;
  if (cl > 0) sort(l + 1, l + cl + 1);
  if (ce > 0) sort(e + 1, e + ce + 1);
  long long q;
  scanf("%lld", &q);
  while (q--) {
    long long x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    long long res = 1000000000000000000;
    if (x1 == x2) {
      printf("%d\n", abs(y1 - y2));
      continue;
    }
    if (cl > 0) {
      long long left = 1;
      long long right = cl;
      long long ans = 0;
      while (left <= right) {
        long long mid = (left + right) / 2;
        if (l[mid] <= y1)
          left = mid + 1;
        else
          right = mid - 1;
      }
      long long firstPos = right;
      left = 1;
      right = cl;
      while (left <= right) {
        long long mid = (left + right) / 2;
        if (l[mid] > y1)
          right = mid - 1;
        else
          left = mid + 1;
      }
      long long secondPos = left;
      long long realpos = firstPos;
      ans = abs(y1 - l[realpos]);
      ans = ans + abs(x2 - x1);
      ans = ans + abs(y2 - l[realpos]);
      res = min(res, ans);
      realpos = secondPos;
      ans = 0;
      ans = abs(y1 - l[realpos]);
      ans = ans + abs(x2 - x1);
      ans = ans + abs(y2 - l[realpos]);
      res = min(res, ans);
    }
    if (ce > 0) {
      long long ans = 0;
      long long left = 1;
      long long right = ce;
      while (left <= right) {
        long long mid = (left + right) / 2;
        if (e[mid] <= y1)
          left = mid + 1;
        else
          right = mid - 1;
      }
      long long firstPos = right;
      left = 1;
      right = ce;
      while (left <= right) {
        long long mid = (left + right) / 2;
        if (e[mid] > y1)
          right = mid - 1;
        else
          left = mid + 1;
      }
      long long secondPos = left;
      long long realpos;
      realpos = firstPos;
      ans = abs(y1 - e[realpos]);
      if (abs(x2 - x1) % v == 0)
        ans = ans + abs(x2 - x1) / v;
      else
        ans = ans + abs(x2 - x1) / v + 1;
      ans = ans + abs(y2 - e[realpos]);
      res = min(res, ans);
      ans = 0;
      realpos = secondPos;
      ans = abs(y1 - e[realpos]);
      if (abs(x2 - x1) % v == 0)
        ans = ans + abs(x2 - x1) / v;
      else
        ans = ans + abs(x2 - x1) / v + 1;
      ans = ans + abs(y2 - e[realpos]);
      res = min(res, ans);
    }
    printf("%lld\n", res);
  }
  return 0;
}
