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
template <class o>
inline void cmax(o &a, o b) {
  a = a < b ? b : a;
}
template <class o>
inline void cmin(o &a, o b) {
  a = a > b ? b : a;
}
namespace zkw {
const int K = 1 << 17;
int mx[K << 1];
vector<int> sta;
void clear() {
  for (int x : sta) mx[x] = 0;
  sta.clear();
}
void upd(int a, int b, int x) {
  for (a += K - 1, b += K; a < b; a >>= 1, b >>= 1) {
    if (a & 1) sta.push_back(a), cmax(mx[a++], x);
    if (b & 1) cmax(mx[--b], x), sta.push_back(b);
  }
}
int ask(int a) {
  int ans = 0;
  for (a += K; a; a >>= 1) cmax(ans, mx[a]);
  return ans;
}
}  // namespace zkw
int R[N], a[N];
int solve() {
  int n;
  qr(n);
  int mx = 0;
  for (int i = 1; i <= n; ++i) qr(a[i]);
  mx = a[n];
  a[0] = mx + 1;
  for (int i = 0; i <= n - 1; ++i) R[i] = n;
  for (int d = 1;; ++d) {
    zkw::clear();
    for (int i = n - 1; i >= 0; --i) {
      if (!R[i]) continue;
      int z = zkw::ask(a[i]);
      if (!i && !z) return d;
      int l = max(1, 2 * a[i] - a[R[i]] + 1);
      int r = min(mx + 1, 2 * a[i] - a[z]);
      if (!z) r = mx + 1;
      R[i] = min(R[i], z);
      zkw::upd(l, r, i);
    }
  }
}
int main() {
  int ans = 0;
  int T;
  qr(T);
  while (T--) {
    ans ^= solve();
  }
  if (ans)
    puts("YES");
  else
    puts("NO");
  return 0;
}
