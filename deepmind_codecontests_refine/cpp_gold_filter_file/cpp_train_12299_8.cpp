#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, mod = 998244353;
template <class o>
inline void qr(o &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  x *= f;
}
template <class o>
void qw(o x) {
  if (x / 10) qw(x / 10);
  putchar(x % 10 + 48);
}
template <class o>
void pr1(o x) {
  if (x < 0) putchar('-'), x = -x;
  qw(x);
  putchar(' ');
}
template <class o>
void pr2(o x) {
  if (x < 0) putchar('-'), x = -x;
  qw(x);
  puts("");
}
inline int ksm(int a, int b = mod - 2) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
inline int add(int a, int b) { return a += b, a >= mod ? a - mod : a; }
inline int sub(int a, int b) { return a -= b, a < 0 ? a + mod : a; }
int a[N];
char s[N];
void solve() {
  int n, c, d;
  qr(n);
  qr(c), qr(d);
  for (int i = 0; i <= n - 1; ++i) qr(a[i]), s[i] = getchar();
  qr(a[n]);
  s[n] = 'X';
  long long sum = 0;
  int lst = n;
  long long ans = 1ll * n * d;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == s[i + 1])
      sum += min(1ll * d, 1ll * c * (lst - a[i + 1]));
    else
      lst = a[i + 1];
    ans = min(ans, 1ll * i * d + sum + 1ll * c * (a[n] - a[i]));
  }
  pr2(ans);
}
int main() {
  solve();
  return 0;
}
