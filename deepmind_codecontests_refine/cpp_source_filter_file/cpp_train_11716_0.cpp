#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool fs(T &x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
int sat(int n, int pos) { return n = n | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool cak(int n, int pos) { return (bool)(n & (1 << pos)); }
long long int binPow(long long int a, long long int q, long long int mud) {
  a %= mud;
  if (q == 0) return 1;
  return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, mud)) % mud;
}
template <class T>
double dif(T a, T b) {
  long long int ans = (a.first - b.first) * (a.first - b.first) +
                      (a.second - b.second) * (a.second - b.second);
  return sqrt(ans);
}
double r[100000 + 5];
double a[100000 + 5];
double b[100000 + 5], ara[100000 + 6], mara[100000 + 5];
double lef[100000 + 5], rit[100000 + 6];
int main() {
  pair<long long int, long long int> x, y, z;
  long long int n, aa, bb;
  fs(x.first);
  fs(x.second);
  fs(y.first);
  fs(y.second);
  fs(z.first);
  fs(z.second);
  fs(n);
  double total = 0;
  for (int i = 0; i < n; i++) {
    fs(aa);
    fs(bb);
    a[i] = dif(pair<long long int, long long int>(aa, bb), x);
    b[i] = dif(pair<long long int, long long int>(aa, bb), y);
    r[i] = dif(pair<long long int, long long int>(aa, bb), z);
    total += r[i];
  }
  total *= 2;
  for (int i = 0; i < n; i++) {
    ara[i] = a[i] - r[i];
    mara[i] = b[i] - r[i];
  }
  lef[0] = mara[0];
  for (int i = 1; i < n; i++) lef[i] = min(mara[i], lef[i - 1]);
  rit[n - 1] = mara[n - 1];
  for (int i = n - 2; i >= 0; i--) rit[i] = min(mara[i], rit[i + 1]);
  double mn = 1e13;
  for (int i = 0; i < n; i++)
    mn = min(mn, min(total + ara[i], total + mara[i]));
  for (int i = 0; i < n; i++) {
    if (i == 0)
      mn = min(mn, total + ara[i] + rit[1]);
    else if (i == n - 1)
      mn = min(mn, total + ara[i] + lef[n - 2]);
    else
      mn = min(mn, total + ara[i] + min(lef[i - 1], rit[i + 1]));
  }
  printf("%.10f\n", mn);
  return 0;
}
