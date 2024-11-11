#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 1000010, P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int INF = 0xcfcfcfcf;
const double eps = 1e-6, pi = asin(1) * 2;
inline long long read();
inline int ADD(int a, int b) { return a + b >= P ? a + b - P : a + b; }
inline int MINUS(int a, int b) { return a - b < 0 ? a - b + P : a - b; }
inline int quickmi(int x, int n) {
  int res = 1;
  for (; n; n >>= 1) {
    if (n & 1) res = 1ll * res * x % P;
    x = 1ll * x * x % P;
  }
  return res;
}
inline long long read() {
  long long s = 0;
  bool flag = false;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') flag = true;
  for (; '0' <= ch && ch <= '9'; ch = getchar())
    s = (s << 3) + (s << 1) + (ch ^ '0');
  if (flag) return -s;
  return s;
}
int main() {
  int n = read(), m = read();
  if (m == 1)
    printf("%d\n", n + 1);
  else
    printf("%d\n", ADD(quickmi(m, n),
                       1ll * m * quickmi(m - 1, P - 2) % P *
                           MINUS(quickmi(m + m - 1, n), quickmi(m, n)) % P));
  return 0;
}
