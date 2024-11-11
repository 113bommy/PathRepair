#include <bits/stdc++.h>
using namespace std;
const int N = 100005, S = 1 << 21;
const double EPS = 1e-10;
char fl[S], *A = fl, *B = fl;
int n, p, q, a[N], b[N];
inline void read(int &x) {
  x = 0;
  char ch;
  while (!isdigit(
      ch = (A == B && (B = (A = fl) + fread(fl, 1, S, stdin), A == B) ? EOF
                                                                      : *A++)))
    ;
  while (x = (x << 3) + (x << 1) + (ch & 15),
         isdigit(ch = (A == B && (B = (A = fl) + fread(fl, 1, S, stdin), A == B)
                           ? EOF
                           : *A++)))
    ;
}
inline void miner(double &x, double y) {
  if (y - x < -EPS) x = y;
}
inline double calc(double x) {
  double y = 1;
  for (register int i = 1; i <= n; ++i) miner(y, (1.0 - a[i] * x) / b[i]);
  return x * p + y * q;
}
int main() {
  register int i;
  read(n);
  read(p);
  read(q);
  double l = 0, r = 1, lmid, rmid;
  for (i = 1; i <= n; ++i) read(a[i]), read(b[i]), miner(r, 1.0 / a[i]);
  while (r - l > EPS) {
    lmid = l + (r - l) / 3.0;
    rmid = r - (r - l) / 3.0;
    if (calc(lmid) - calc(rmid) > EPS)
      r = rmid;
    else
      l = lmid;
  }
  return printf("%.20lf", calc((l + r) / 2.0)), 0;
}
