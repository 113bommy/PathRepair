#include <bits/stdc++.h>
using namespace std;
int m;
inline void A(int &x, int y) {
  x += y;
  if (x >= m) x -= m;
}
inline int M(int x, int y) {
  x = x * 1ll * y % m;
  return x;
}
struct ww {
  int a[2][2];
  inline ww operator*(const ww &b) const {
    ww c;
    memset(c.a, 0, sizeof c.a);
    for (long long k = (0); k <= (1); k++)
      for (long long i = (0); i <= (1); i++)
        for (long long j = (0); j <= (1); j++)
          A(c.a[i][j], M(a[i][k], b.a[k][j]));
    return c;
  }
};
int getF(long long x) {
  if (x == 1) return 1;
  ww a, c;
  x -= 2ll;
  memset(a.a, 0, sizeof a.a);
  memset(c.a, 0, sizeof c.a);
  c.a[0][0] = c.a[1][1] = 1;
  a.a[0][1] = a.a[1][1] = a.a[1][0] = 1;
  for (; x; x >>= 1, a = a * a)
    if (x & 1) c = c * a;
  int res = c.a[1][1];
  A(res, c.a[0][1]);
  return res;
}
long long l, r, k;
bool check(long long x) { return r / x - (l + x - 1) / x + 1 >= k; }
int main() {
  scanf("%d", &m);
  scanf("%I64d%I64d%I64d", &l, &r, &k);
  long long ress = 1;
  long long st = max((long long)sqrt(r), 1ll);
  for (long long i = (1); i <= (st); i++) ress = max(ress, i * check(i));
  for (long long i = (1); i <= (r / st); i++)
    ress = max(ress, (r / i) * check(r / i));
  printf("%d\n", getF(ress) % m);
  return 0;
}
