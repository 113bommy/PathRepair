#include <bits/stdc++.h>
using namespace std;
const long long mos = 0x7FFFFFFF;
const long long nmos = 0x80000000;
const int inf = 0x3f3f3f3f;
const long long inff = 0x3f3f3f3f3f3f3f3f;
const double esp = 1e-8;
const double PI = acos(-1.0);
const double PHI = 0.61803399;
const double tPHI = 0.38196601;
template <typename T>
inline T read(T& x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x = f ? -x : x;
}
int main() {
  long long n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1) {
    long long tmp = m % 6;
    if (tmp <= 3)
      m -= tmp;
    else
      m += (tmp - 6);
  } else if (n == 2) {
    if (m == 2)
      m = 0;
    else if (m == 3)
      m = 4;
    else if (m == 7)
      m = 12;
    else
      m = 2ll * m;
  } else {
    if (1ll * n * m % 2 == 0)
      m = 1ll * n * m;
    else
      m = 1ll * n * m - 1;
  }
  cout << m << endl;
  return 0;
}
