#include <bits/stdc++.h>
using namespace std;
long long max(long long x, long long y) { return x > y ? x : y; }
long long min(long long x, long long y) { return x > y ? y : x; }
inline long long read() {
  long long a = 0;
  long long f = 0;
  char p = getchar();
  while (!isdigit(p)) {
    f |= p == '-';
    p = getchar();
  }
  while (isdigit(p)) {
    a = (a << 3) + (a << 1) + (p ^ 48);
    p = getchar();
  }
  return f ? -a : a;
}
inline void print(long long x) {
  if (!x) return;
  if (x) print(x / 10);
  putchar(x % 10 + '0');
}
long long T, n, num[100010];
vector<long long> a[100010];
inline bool check(long long x, long long id) {
  for (long long j = 0; j < num[id]; ++j) {
    if (x > a[id][j])
      x++;
    else
      return false;
  }
  return true;
}
struct node {
  long long loc, w;
} use[100010];
inline bool cmp(node x, node y) { return x.w < y.w; }
inline bool check2(long long x) {
  for (long long i = 1; i <= n; ++i) {
    if (x < use[i].w)
      return false;
    else
      x += num[use[i].loc];
  }
  return true;
}
signed main() {
  T = read();
  while (T--) {
    n = read();
    for (long long i = 1; i <= n; ++i) {
      num[i] = read();
      a[i].clear();
      for (long long k = 1; k <= num[i]; ++k) {
        long long x = read();
        a[i].push_back(x);
      }
      long long l = 1, r = 1e11;
      while (l < r) {
        long long mid = l + r >> 1;
        if (check(mid, i))
          r = mid;
        else
          l = mid + 1;
      }
      use[i].w = l;
      use[i].loc = i;
    }
    sort(use + 1, use + 1 + n, cmp);
    long long l = 1, r = 1e11;
    while (l < r) {
      long long mid = l + r >> 1;
      if (check2(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%lld\n", l);
  }
  return 0;
}
