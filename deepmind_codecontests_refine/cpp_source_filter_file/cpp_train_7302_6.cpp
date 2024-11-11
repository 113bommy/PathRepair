#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
struct node {
  int fst, val;
} a[MAXN];
int n;
long long sum;
long long val[MAXN], mask[MAXN];
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(val[i]);
    read(mask[i]);
    sum += (long long)val[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 61; ++j) {
      if (mask[i] >> j & 1) a[i].fst = j;
    }
    a[i].val = val[i];
  }
  if (sum < 0) {
    for (int i = 1; i <= n; ++i) a[i].val *= -1;
  }
  long long ans = 0;
  for (int bit = 0; bit <= 61; ++bit) {
    long long all = 0;
    for (int i = 1; i <= n; ++i)
      if (a[i].fst == bit) all += (long long)a[i].val;
    if (all > 0) {
      ans |= 1 << bit;
      for (int i = 1; i <= n; ++i)
        if (mask[i] >> bit & 1) a[i].val *= -1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
