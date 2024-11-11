#include <bits/stdc++.h>
const int oo = 2139063143;
const int N = 1010000;
const int P = 1000000007;
using namespace std;
template <typename T>
inline void sc(T &x) {
  x = 0;
  static int p;
  p = 1;
  static char c;
  c = getchar();
  while (!isdigit(c)) {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c - 48);
    c = getchar();
  }
  x *= p;
}
template <typename T>
inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void pr(T x) {
  print(x), putchar('\n');
}
vector<int> b;
int a[N];
int main() {
  int n;
  sc(n);
  for (int i = 1; i <= n; i++) sc(a[i]);
  long long las = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    while (a[i] % 3 && las) --las, a[i] -= 2, ++ans;
    las += a[i] % 3;
    ans += a[i] / 3;
  }
  pr(ans);
  return 0;
}
