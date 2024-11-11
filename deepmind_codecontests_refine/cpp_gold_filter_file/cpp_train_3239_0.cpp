#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const int INF = 0x3f3f3f3f3f, mod = 1e9 + 7;
const double eps = 1e-6, PI = acos(-1);
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do x = x * 10 + ch - '0', ch = getchar();
  while (ch <= '9' && ch >= '0');
  x *= f;
}
long long n, m;
int main() {
  read(n), read(m);
  long long min1 = max(0LL, n - m * 2);
  if (m == 0) {
    printf("%lld %lld\n", n, n);
    return 0;
  }
  long long max1 = 0;
  for (int i = 2; i <= n; i++) {
    long long now = 1LL * i * (i - 1) / 2;
    if (m <= now) {
      max1 = n - i;
      break;
    }
  }
  printf("%lld %lld\n", min1, max1);
  return 0;
}
