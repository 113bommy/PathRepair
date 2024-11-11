#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
template <typename _T>
inline void read(_T &f) {
  f = 0;
  _T fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      fu = -1;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  f *= fu;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + 48);
  else
    print(x / 10), putchar(x % 10 + 48);
}
template <typename T>
void print(T x, char t) {
  print(x);
  putchar(t);
}
const int N = 1e5 + 5;
int a[N], pre[N];
int T, n, m, maxn;
long long ans;
int main() {
  read(T);
  while (T--) {
    read(n);
    read(m);
    maxn = ans = 0;
    for (int i = 1; i <= n; i++) read(a[i]), pre[a[i]] = i;
    for (int i = 1; i <= m; i++) {
      int x;
      read(x);
      x = pre[x];
      if (x <= maxn)
        ++ans;
      else {
        ans += (x - maxn) * 2 - 1;
        maxn = x;
      }
    }
    print(ans, '\n');
  }
  return 0;
}
