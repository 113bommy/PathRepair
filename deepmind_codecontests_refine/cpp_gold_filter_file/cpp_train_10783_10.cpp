#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9, N = 10010, MAXN = 1000000;
const double eps = 1e-8;
inline void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
inline void read(unsigned long long &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
unsigned long long n, m, ans;
int main() {
  read(n);
  read(m);
  m = min(n, m);
  if (n == m) {
    printf("%I64d\n", m);
    return 0;
  };
  unsigned long long l = 0, r = sqrt(2 * (n - m)) + 1;
  bool f = 0;
  while (l <= r) {
    unsigned long long mid = (l + r) >> 1;
    unsigned long long tmp = 0;
    if (mid & 1)
      tmp = (mid + 1) / 2 * mid;
    else
      tmp = mid / 2 * (mid + 1);
    if (l == r) f = 1;
    if (tmp >= n - m) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
    if (f) break;
  }
  printf("%I64d\n", ans + m);
  return 0;
}
