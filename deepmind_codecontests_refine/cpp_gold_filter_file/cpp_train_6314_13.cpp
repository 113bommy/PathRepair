#include <bits/stdc++.h>
using namespace std;
long long kano() {
  char ch = getchar();
  long long w = 0, u = 1;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') u = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) w = w * 10 + ch - '0';
  return w * u;
}
long long n, q;
long long work(long long tar, long long p, int u, int y) {
  y = p & 1;
  if (u == 0) {
    if (tar & 1)
      return (tar >> 1) + 1;
    else
      return work(tar >> 1, p - (p >> 1) - (p & 1), u ^ y, y) + (p >> 1) +
             (p & 1);
  } else {
    if (!(tar & 1))
      return ((tar - 1) >> 1) + 1;
    else
      return work(((tar - 1) >> 1) + 1, p - ((p - 1) >> 1) - ((p - 1) & 1),
                  u ^ y, y) +
             ((p - 1) >> 1) + ((p - 1) & 1);
  }
}
int main() {
  n = kano();
  q = kano();
  for (int i = 1; i <= q; i++) {
    printf("%I64d\n", work(kano(), n, 0, 0));
  }
}
