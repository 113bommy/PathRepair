#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void upmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void upmin(T &a, T b) {
  if (a > b) a = b;
}
const int maxn = 200007;
const int maxm = 200007;
const int mod = 1000000007;
const int inf = 0x7fffffff;
const double eps = 1e-7;
typedef int arr[maxn];
typedef int adj[maxm];
inline int fcmp(double a, double b) {
  if (fabs(a - b) <= eps) return 0;
  if (a < b - eps) return -1;
  return 1;
}
inline int add(int a, int b) { return ((long long)a + b) % mod; }
inline int mul(int a, int b) { return ((long long)a * b) % mod; }
inline int dec(int a, int b) { return add(a, mod - b % mod); }
inline int Pow(int a, int b) {
  int t = 1;
  while (b) {
    if (b & 1) t = mul(t, a);
    a = mul(a, a), b >>= 1;
  }
  return t;
}
template <typename Type>
inline Type RD() {
  char c = getchar();
  Type x = 0, flag = 1;
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    flag = -1;
  else
    x = c - '0';
  while (isdigit(c = getchar())) x = x * 10 + c - '0';
  return x * flag;
}
inline char rdch() {
  char c = getchar();
  while (!isalpha(c)) c = getchar();
  return c;
}
int n;
arr a, b, c;
void input() {
  n = RD<int>();
  for (int i = 1, _ = n; i <= _; i++) a[i] = RD<int>() + 1;
  for (int i = 1, _ = n; i <= _; i++) b[i] = RD<int>() + 1;
}
namespace BIT {
arr val;
int n;
inline void init(int N) {
  n = N;
  for (int i = 0, _ = n; i <= _; i++) val[i] = 0;
}
inline void add(int p, int v) {
  while (p <= n) val[p] += v, p += (p & (-p));
}
inline int sum(int p) {
  int t = 0;
  while (p) t += val[p], p -= (p & (-p));
  return t;
}
}  // namespace BIT
inline void get() {
  int x = 0;
  for (int i = n - 1, _ = 1; i >= _; i--) {
    int cut = n - i + 1;
    c[i] = a[i] + b[i] + x;
    x = c[i] / cut;
    c[i] %= cut;
  }
}
inline void trans(int *a) {
  BIT::init(n);
  for (int i = 1, _ = n; i <= _; i++) {
    BIT::add(a[i], 1);
    a[i] = a[i] - 1 - BIT::sum(a[i] - 1);
  }
}
namespace ST {
const int maxs = 524288;
int cnt[maxs];
void B(int u = 1, int l = 1, int r = n) {
  cnt[u] = r - l + 1;
  if (l == r) return;
  int m = (l + r) >> 1;
  B((u << 1), l, m), B((u << 1 | 1), m + 1, r);
}
inline int K(int k, int u = 1, int l = 1, int r = n) {
  while (l != r) {
    cnt[u]--;
    int m = (l + r) >> 1;
    if (k > cnt[(u << 1)])
      k -= cnt[(u << 1)], u = (u << 1 | 1), l = m + 1;
    else
      u = (u << 1), r = m;
  }
  cnt[u]--;
  return l;
}
}  // namespace ST
inline void itrans(int *a) {
  ST::B();
  for (int i = 1, _ = n; i <= _; i++) a[i] = ST::K(a[i] + 1);
}
void solve() {
  trans(a);
  trans(b);
  get();
  itrans(c);
  for (int i = 1, _ = n; i <= _; i++) printf("%d ", c[i] - 1);
  puts("");
}
int main() {
  input();
  solve();
  return 0;
}
