#include <bits/stdc++.h>
using namespace std;
template <typename T>
void r1(T &x) {
  x = 0;
  char c(getchar());
  int f(1);
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) x = (x * 10) + (c ^ 48);
  x *= f;
}
template <typename T, typename... Args>
inline void r1(T &t, Args &...args) {
  r1(t);
  r1(args...);
}
const int maxn = 1e2 + 5;
const int maxm = maxn << 1;
const int mod = 1e9 + 7;
typedef int room[maxn];
template <int mod>
struct typemod {
  int z;
  typemod(int a = 0) : z(a) {}
  inline int inc(int a, int b) const {
    return a += b - mod, a + ((a >> 31) & mod);
  }
  inline int dec(int a, int b) const { return a -= b, a + ((a >> 31) & mod); }
  inline int mul(int a, int b) const { return 1ll * a * b % mod; }
  typemod<mod> operator+(const typemod<mod> &x) const {
    return typemod(inc(z, x.z));
  }
  typemod<mod> operator-(const typemod<mod> &x) const {
    return typemod(dec(z, x.z));
  }
  typemod<mod> operator*(const typemod<mod> &x) const {
    return typemod(mul(z, x.z));
  }
  typemod<mod> &operator+=(const typemod<mod> &x) {
    *this = *this + x;
    return *this;
  }
  typemod<mod> &operator-=(const typemod<mod> &x) {
    *this = *this - x;
    return *this;
  }
  typemod<mod> &operator*=(const typemod<mod> &x) {
    *this = *this * x;
    return *this;
  }
  int operator==(const typemod<mod> &x) const { return x.z == z; }
  int operator!=(const typemod<mod> &x) const { return x.z != z; }
};
int n, k;
int f[maxn][maxn];
struct Node {
  int a, b, id;
  int operator<(const Node &z) const { return b == z.b ? a > z.a : b < z.b; }
} a[maxn], tmp[maxn];
int pre[maxn][maxn], visin[maxn];
int qwq[maxn], qaq[maxn];
int ans1[maxn], ans2[maxn];
signed main() {
  int i, j, t;
  r1(t);
  while (t--) {
    int ans(0), last(0), C(0);
    r1(n), r1(k);
    for (i = 1; i <= n; ++i) r1(a[i].a), r1(a[i].b), a[i].id = i;
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; ++i) ans1[i] = ans2[i] = 0;
    for (int st = 1; st <= n; ++st) {
      memset(f, -0x3f, sizeof(f));
      for (i = 1; i <= n; ++i) visin[i] = 0;
      f[0][0] = 0;
      for (i = 1; i <= n; ++i) {
        for (j = 0; j <= k - 1; ++j) {
          if (!j || i == st) {
            pre[i][j] = 0, f[i][j] = f[i - 1][j];
            continue;
          }
          int tmp = a[i].b * (j - k);
          if (f[i - 1][j] > f[i - 1][j - 1] + tmp + a[i].a)
            f[i][j] = f[i - 1][j], pre[i][j] = 0;
          else
            f[i][j] = f[i - 1][j - 1] + tmp + a[i].a, pre[i][j] = 1;
        }
      }
      i = n, j = k - 1;
      while (i && j) {
        if (!pre[i][j])
          --i;
        else
          qaq[j] = i, visin[i] = 1, --i, --j;
      }
      int cnt(0);
      for (i = 1; i <= n; ++i)
        if (!visin[i] && i != st) qwq[++cnt] = i;
      int ct1(0);
      for (i = 1; i <= cnt; ++i) tmp[++ct1] = a[qwq[i]];
      sort(tmp + 1, tmp + ct1 + 1);
      int res(0);
      for (i = 1; i <= ct1; ++i) res += (k - 1) * tmp[i].b;
      for (i = 1; i <= k - 1; ++i) res += a[qaq[i]].a + (i - 1) * a[qaq[i]].b;
      res += a[st].a + (k - 1) * a[st].b;
      if (res >= ans) {
        ans = res, last = st;
        C = cnt;
        for (i = 1; i <= k - 1; ++i) ans1[i] = qaq[i];
        for (i = 1; i <= cnt; ++i) ans2[i] = qwq[i];
      }
    }
    printf("%d\n", C * 2 + k);
    for (i = 1; i <= k - 1; ++i) printf("%d ", a[ans1[i]].id);
    for (i = 1; i <= C; ++i) printf("%d %d ", a[ans2[i]].id, -a[ans2[i]].id);
    printf("%d\n", a[last].id);
  }
  return 0;
}
