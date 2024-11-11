#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &n) {
  T w = 1;
  n = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != EOF) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch) && ch != EOF) {
    n = (n << 1) + (n << 3) + (ch ^ 48);
    ch = getchar();
  }
  n *= w;
}
template <typename T>
inline void write(T x) {
  unsigned long long y = 0;
  T l = 0;
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (!x) {
    putchar(48);
    return;
  }
  while (x) {
    y = y * 10 + x % 10;
    x /= 10;
    l++;
  }
  while (l) {
    putchar(y % 10 + 48);
    y /= 10;
    l--;
  }
}
template <typename T>
inline void writeln(T x) {
  write(x);
  puts("");
}
template <typename T>
inline void writes(T x) {
  write(x);
  putchar(' ');
}
template <typename T>
inline void checkmax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T>
inline void checkmin(T &a, T b) {
  a = a < b ? a : b;
}
const int N = 1e5 + 100, M = 43;
int n, m, K[N], a[N][M], ans[N];
struct yjy {
  int val;
  long long MOD, zhi;
};
vector<yjy> now[M], pre[M], cur;
inline int gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
inline void exgcd(long long &x, long long &y, long long a, long long b) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(y, x, b, a % b);
  y -= a / b * x;
}
inline void bing(long long &x, long long &y, long long nx, long long ny) {
  long long gc = gcd(x, nx);
  long long now = (long long)x * nx / gc;
  if ((ny - y) % gc != 0) {
    x = -1;
    return;
  }
  long long c = (ny - y) / gc, k = 0, nk = 0;
  exgcd(k, nk, x, nx);
  y += (__int128)k * c % now * x % now;
  y = (y + now) % now;
  x = now;
}
signed main() {
  read(n);
  read(m);
  for (int i = (1); i <= (n); i++) {
    read(K[i]);
    for (int j = (1); j <= (K[i]); j++) read(a[i][j]);
  }
  for (int i = (1); i <= (m); i++) ans[i] = 0;
  for (int i = (1); i <= (K[1]); i++) {
    now[i].emplace_back(yjy{1, K[1], i % K[1]});
    checkmax(ans[a[1][i]], (int)1);
  }
  for (int i = (2); i <= (n); i++) {
    for (int j = (1); j <= (40); j++) {
      pre[j].clear();
      for (auto it : now[j]) pre[j].emplace_back(it);
    }
    for (int j = (1); j <= (40); j++) now[j].clear();
    for (int j = (1); j <= (K[i]); j++) {
      int ok = 0, pos = -1;
      for (int it = (1); it <= (K[i - 1]); it++)
        if (a[i][j] == a[i - 1][it]) {
          pos = it;
          break;
        }
      now[j].emplace_back(yjy{1, K[i], j % K[i]});
      checkmax(ans[a[i][j]], (int)1);
      if (pos == -1) continue;
      for (auto k : pre[pos]) {
        bing(k.MOD, k.zhi, K[i], j % K[i]);
        if (k.MOD == -1) continue;
        now[j].emplace_back(yjy{k.val + 1, k.MOD, k.zhi});
        checkmax(ans[a[i][j]], k.val + 1);
      }
      cur.clear();
      for (int it = (0); it <= (int(now[j].size()) - 1); it++)
        if (it + 1 == now[j].size() || now[j][it].MOD != now[j][it + 1].MOD)
          cur.emplace_back(now[j][it]);
      now[j].clear();
      for (auto k : cur) now[j].emplace_back(k);
    }
  }
  for (int i = (1); i <= (m); i++) writeln(ans[i]);
  return 0;
}
