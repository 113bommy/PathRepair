#include <bits/stdc++.h>
using namespace std;
inline void scf(int &x) { scanf("%d", &x); }
inline void scf(long long &x) { scanf("%I64d", &x); }
inline void scf(unsigned long long &x) { scanf("%I64u", &x); }
inline void scf(double &x) { scanf("%lf", &x); }
inline void scf(char &x) { scanf("%c", &x); }
inline void scf(char *x) { scanf("%s", x); }
const int N = 100000 + 7;
const int mars = 0x3c3c3c3c;
typedef int Arr[N];
typedef char Err[N];
typedef bool Brr[N];
typedef long long Lrr[N];
int m, n, k, w, a, b, c, d, t, p, q, x, y, cnt, l, s;
Arr A;
int main() {
  int i, u, v;
  scf(n), scf(a);
  t = max(1 + (int)round(a / 180.0 * n), 2);
  if (t >= n) t = n - 1;
  printf("1 %d %d\n", t + 1, t);
}
