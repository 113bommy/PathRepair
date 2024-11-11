#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = false;
  for (; !isdigit(c); c = getchar()) f |= c == '-';
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  if (f) x = -x;
}
template <typename T, typename... Arg>
inline void read(T &x, Arg &...args) {
  read(x);
  read(args...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int t, n, m, k;
signed main() {
  read(t);
  while (t--) {
    read(n, m, k);
    if (n % 2 == 0) {
      int up = ((m / 2) * 2) * n;
      if (k <= up && k % 2 == 0)
        puts("YES");
      else
        puts("NO");
    } else {
      if (k >= m / 2 && (k - m / 2) % 2 == 0)
        puts("YES");
      else
        puts("NO");
    }
  }
}
