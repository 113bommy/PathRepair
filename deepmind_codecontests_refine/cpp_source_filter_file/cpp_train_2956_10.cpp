#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long Linf = 1e18 + 5;
template <class T>
inline void umax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void umin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
T abs(T a) {
  return a > 0 ? a : -a;
}
int read() {
  int res = 0;
  int neg;
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9' || ch == '-') {
      if (ch == '-')
        neg = -1;
      else
        neg = 1, res = ch - '0';
      break;
    }
  }
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9')
      res *= 10, res += ch - '0';
    else
      break;
  }
  return res * neg;
}
void write(int x) {
  static char buf[20];
  int nn = 0;
  if (x < 0) putchar('-'), x *= -1;
  while (x) {
    buf[++nn] = x % 10 + '0';
    x /= 10;
  }
  for (int(i) = (nn); (i) >= (1); (i)--) putchar(buf[i]);
  putchar('\n');
}
const int MAXN = 1e5 + 5;
int ar[MAXN];
int sum[MAXN];
int main() {
  int n = read(), m = read();
  for (int(i) = (1); (i) <= (n); (i)++) {
    ar[i] = read() * read();
    sum[i] = sum[i - 1] = ar[i];
  }
  for (int(i) = (1); (i) <= (m); (i)++)
    printf("%d\n", lower_bound(sum + 1, sum + 1 + n, read()) - sum);
  return 0;
}
