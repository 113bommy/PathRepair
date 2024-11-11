#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const double eps = 1e-8;
const long long inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
inline long long rd() {
  register long long res = 0, flag = 0;
  char ch;
  if ((ch = getchar()) == '-')
    flag = 1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9')
    res = (res << 1) + (res << 3) + (ch - '0');
  return flag ? -res : res;
}
void out(long long a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) out(a / 10);
  putchar(a % 10 + '0');
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve() {
  long long m = rd(), d = rd(), w = rd();
  if (d == 1) {
    cout << "0\n";
    return;
  }
  long long c = w / gcd(w, d - 1);
  long long T = min(d, m);
  long long k = ceil(T * 1. / c);
  while (k & T - k * c <= 0) k--;
  cout << T * k - (1 + k) * k * c / 2 << '\n';
}
signed main() {
  for (long long tt = rd(); tt--;) solve();
  return 0;
}
