#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
A convert(B x) {
  stringstream ss;
  ss << x;
  A ret;
  ss >> ret;
  return ret;
}
const int oo = ~0u >> 3;
const double eps = 1e-10, pi = acos(-1);
const int ml = 20, mo = 1000000007;
const int fx[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                      {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
long long e[ml];
long long a, l, b(0);
int calc(long long x) {
  long long ret(0);
  for (long long i = x; i; i /= 10)
    if ((i % 10) == 4 || (i % 10) == 7) ++ret;
  return ret;
}
long long Prev(long long x) {
  for (long long m = 1;; m *= 10)
    if (((x / m) % 10) == 4 || ((x / m) % 10) == 7)
      return (long long)x + m - (x % m);
  return x;
}
long long Succ(long long x) {
  int m = 0, l = 1;
  do {
    if (e[m] > x)
      if (m >= l)
        return e[m] + (e[l] - 1) / 9 * 4;
      else
        return (e[l] - 1) / 9 * 4;
    if (x / e[m] % 10 < 3 && m >= l)
      return x + e[m] - x % e[m] + (e[l] - 1) / 9 * 4;
    if (x / e[m] % 10 < 4 && m + 1 >= l)
      return x + (4 - x / e[m] % 10) * e[m] - x % e[m] + (e[l - 1] - 1) / 9 * 4;
    if (x / e[m] % 10 < 4 && m >= l)
      return x + (4 - x / e[m] % 10) * e[m] - x % e[m] + (e[l - 1] - 1) / 9 * 4;
    if (x / e[m] % 10 == 4 && m >= l + 1)
      return x + e[m] - x % e[m] + (e[l + 1] - 1) / 9 * 4;
    if (x / e[m] % 10 == 4 && m >= l)
      return x + 3 * e[m] - x % e[m] + (e[l] - 1) / 9 * 4;
    if (x / e[m] % 10 < 7 && m + 1 >= l)
      return x + (7 - x / e[m] % 10) * e[m] - x % e[m] + (e[l - 1] - 1) / 9 * 4;
    if (x / e[m] % 10 == 7)
      if (m >= l + 1)
        return x + e[m] - x % e[m] + (e[l + 1] - 1) / 9 * 4;
      else {
        ++l;
        continue;
      }
    if (x / e[m] % 10 < 9 && m >= l)
      return x + e[m] - x % e[m] + (e[l] - 1) / 9 * 4;
  } while (++m);
}
int main() {
  e[0] = 1;
  for (int i = 1; i <= ml - 1; ++i) e[i] = (long long)e[i - 1] * 10;
  cin >> a >> l;
  int d, m;
  for (d = a + l - 1, m = 1; l >= 10; l /= 10, a /= 10, d /= 10, m *= 10)
    b += (a % 10) * m;
  long long i = a + 1;
  if (calc(i) > calc(a)) i = Prev(i);
  if (calc(i) < calc(a)) i = Succ(i);
  while (1) {
    long long I = i;
    for (long long k = 0; a + k <= d; ++k) {
      int n1 = calc(a + k);
      int n2 = calc(i + k);
      for (int j = 1; j <= n2 - n1; ++j) i = Prev(i + k) - k;
      for (int j = 1; j <= n1 - n2; ++j) i = Succ(i + k) - k;
    }
    if (i == I) {
      b += i * m;
      break;
    }
  }
  cout << b << endl;
}
