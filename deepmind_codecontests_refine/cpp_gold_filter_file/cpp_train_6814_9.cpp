#include <bits/stdc++.h>
using namespace std;
clock_t start;
void Time(bool timeIt) {
  if (!timeIt) return;
  clock_t end = clock();
  double elapsed_time = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
  printf("Time elapsed = %0.4lf\n", elapsed_time);
}
long long multiply(long long a, long long b, long long mod) {
  long long ret = 0, pw = a;
  for (int i = 0; (1ll << i) <= b; ++i) {
    if (b & (1ll << i)) ret = (ret + pw) % mod;
    pw = (pw + pw) % mod;
  }
  return ret;
}
long long lg = 1, p[19];
long long calc(long long b, long long mod) {
  long long ret = multiply(p[lg - 1], lg * 45ll, mod);
  return ret;
}
bool check(long long l, long long r, long long a) {
  long long res = 0;
  for (long long i = l; i <= r; ++i) {
    long long j = i;
    while (j > 0) {
      res += j % 10;
      if (res >= a) res -= a;
      j /= 10;
    }
  }
  return (res == 0);
}
int main() {
  start = clock();
  long long a;
  cin >> a;
  long long b;
  p[0] = 1;
  for (int i = 1; i < 19; ++i) p[i] = (p[i - 1] * 10ll);
  for (int i = 1; i <= 18; ++i) {
    if (a <= p[i]) {
      b = p[i];
      lg = i;
      break;
    }
  }
  long long off = calc(b, a), l = a - off, r = b + a - off - 1;
  cout << l << " " << r << endl;
  Time(false);
  return 0;
}
