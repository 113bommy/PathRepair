#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, size = 1 << 20, mod = 998244353, inf = 2e9;
const long long INF = 1e15;
template <class o>
void qr(o& x) {
  char c = getchar();
  x = 0;
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= f;
}
template <class o>
void qw(o x) {
  if (x / 10) qw(x / 10);
  putchar(x % 10 + '0');
}
template <class o>
void pr1(o x) {
  if (x < 0) x = -x, putchar('-');
  qw(x);
  putchar(' ');
}
template <class o>
void pr2(o x) {
  if (x < 0) x = -x, putchar('-');
  qw(x);
  putchar('\n');
}
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long power(long long a, long long b = mod - 2, long long p = mod) {
  long long c = 1;
  while (b) {
    if (b & 1) c = c * a % p;
    b /= 2;
    a = a * a % p;
  }
  return c;
}
template <class o>
void cmax(o& x, o y) {
  if (x < y) x = y;
}
void cmax(int& x, int y) {
  x = x - y >> 31 ? y : x;
  ;
}
template <class o>
void cmin(o& x, o y) {
  if (x > y) x = y;
}
void cmin(int& x, int y) { x = x - y >> 31 ? x : y; }
template <typename t1, typename t2>
void ad(t1& x, t2 y) {
  x += y;
  if (x >= mod) x -= mod;
}
template <typename t1, typename t2>
void dl(t1& x, t2 y) {
  x -= y;
  if (x < 0) x += mod;
}
int n, q, a[N], id[150];
char s[N];
struct BIT {
  int c[N], v;
  void add(int x, int d) {
    v += d;
    for (; x <= n; x += x & -x) c[x] += d;
  }
  int ask(int x) {
    int y = 0;
    for (; x; x &= x - 1) y += c[x];
    return y;
  }
  int ask(int l, int r) { return l <= r ? ask(r) - ask(l - 1) : 0; }
  int kth(int k) {
    int x = 0;
    for (int i = 18; i >= 0; i--)
      if ((1 << (i)) + x <= n && c[(1 << (i)) + x] < k) k -= c[x += (1 << (i))];
    return x + 1;
  }
  int begin() { return kth(1); }
  int end() { return kth(v); }
} tr[3];
int win[3], lose[3];
void ask() {
  int ans = 0;
  for (int i = 0; i <= 2; i++) {
    if (!tr[i].v) continue;
    if (!tr[lose[i]].v)
      ans += tr[i].v;
    else {
      if (!tr[win[i]].v) continue;
      int l = tr[win[i]].begin(), r = tr[win[i]].end();
      int L = tr[lose[i]].begin(), R = tr[lose[i]].end();
      ans += tr[i].ask(max(R, l), n);
      ans += tr[i].ask(max(L, l), min(R, r));
      ans += tr[i].ask(min(L, r));
    }
  }
  pr2(ans);
}
void solve() {
  qr(n);
  qr(q);
  scanf("%s", s + 1);
  id['R'] = 2;
  id['S'] = 1;
  for (int i = 0; i <= 2; i++) win[i] = (i + 2) % 3, lose[i] = (i + 1) % 3;
  for (int i = 1; i <= n; i++) s[i] = id[s[i]], tr[s[i]].add(i, 1);
  ask();
  int x;
  char op[3];
  while (q--) {
    qr(x);
    scanf("%s", op);
    tr[s[x]].add(x, -1);
    tr[s[x] = id[op[0]]].add(x, 1);
    ask();
  }
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
