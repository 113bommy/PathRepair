#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool isone(long long, int);
int count(long long);
long long exp(long long, long long, long long);
long long GCD(long long, long long);
int cmp(long long a, long long b, long long c, long long d) {
  if ((a * d) > (b * c))
    return 1;
  else if ((a * d) == (b * c))
    return 0;
  return -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long t1, t2, x1, x2, t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  if (t1 == t0 == t2) {
    cout << x1 << " " << x2 << endl;
    return 0;
  } else if (t1 == t0) {
    cout << x1 << " " << 0 << endl;
    return 0;
  } else if (t2 == t0) {
    cout << 0 << " " << x2 << endl;
    return 0;
  }
  long long y1 = 0LL, y2 = 0LL, a, b, c, d;
  if (t1 >= t0) {
    y1 = x1;
    y2 = 0;
  }
  if (t2 >= t0) {
    if (y1 && (t2 <= t1)) {
      y2 = x2;
      y1 = 0;
    } else if (!y1) {
      y2 = x2;
      y1 = 0;
    }
  }
  a = 10000000000LL;
  b = 1;
  for (long long i = 0; i <= x1; i++) {
    long long j = ((i * (t0 - t1)) % (t2 - t0))
                      ? (((i * (t0 - t1)) / (t2 - t0)) + 1)
                      : ((i * (t0 - t1)) / (t2 - t0));
    if (j > x2) continue;
    c = t1 * i + t2 * j;
    d = i + j;
    if (cmp(a, b, c, d) > 0) {
      a = c;
      b = d;
      y1 = i;
      y2 = j;
    } else if (cmp(a, b, c, d) == 0) {
      if (min(i, j) > min(y1, y2)) {
        y1 = i;
        y2 = j;
      }
    }
  }
  cout << y1 << " " << y2 << endl;
  return 0;
}
long long GCD(long long a, long long b) {
  if (!b)
    return a;
  else
    return GCD(b, a % b);
}
long long exp(long long a, long long b, long long c) {
  long long ret = 1LL;
  long long mult = a;
  while (b) {
    if (b & 1) ret = (ret * mult) % c;
    mult = (mult * mult) % c;
    b >>= 1;
  }
  return ret;
}
int count(long long x) {
  int ret = 0;
  while (x) {
    if (x & 1) ret++;
    x >>= 1LL;
  }
  return ret;
}
bool isone(long long x, int pos) { return x & (1 << pos); }
