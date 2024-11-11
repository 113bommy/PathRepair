#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &n) {
  n = 0;
  register int f(1);
  register char c(getchar());
  while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
  while (c <= '9' && c >= '0') n = n * 10 + c - 48, c = getchar();
  n *= f;
}
template <typename T>
inline void print(T x) {
  if (x > 9) print(x / 10);
  putchar(x % 10 + 48);
}
const int N = 2e5 + 5;
int a[N];
int main() {
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) {
    int t;
    read(t);
    ++a[t];
  }
  int ans = 0, s = 0, l, r, last = -1;
  for (int i = 1; i <= 2e5 + 1; ++i) {
    if (a[i]) {
      if (s == 0) last = i;
      if (a[i] == 1) {
        s += a[i];
        if (s > ans) {
          ans = s;
          l = last;
          r = i;
        }
        s = a[i], last = i;
      } else
        s += a[i];
    } else if (s) {
      if (s > ans) {
        ans = s;
        l = last;
        r = i - 1;
      }
      s = 0;
    }
  }
  print(ans);
  puts("");
  for (int i = l; i <= r; ++i) {
    print(i);
    putchar(' ');
  }
  for (int i = r; i >= l; --i)
    for (int j = 1; j < a[i]; ++j) {
      print(i);
      putchar(' ');
    }
  puts("");
  return 0;
}
