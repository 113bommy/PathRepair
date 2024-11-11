#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
template <class T>
inline bool read(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
inline long long modPow(long long a, long long b) {
  register long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return ans;
}
int x[MAXN], y[MAXN], xx[MAXN], yy[MAXN], fa[MAXN], child[MAXN], tag[MAXN],
    visx[MAXN], visy[MAXN], cntx[MAXN], cnty[MAXN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
  int n;
  read(n);
  memset(tag, 0, sizeof(tag));
  memset(visx, -1, sizeof(visx));
  memset(visy, -1, sizeof(visy));
  memset(cntx, 0, sizeof(cntx));
  memset(cnty, 0, sizeof(cnty));
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    read(x[i]), read(y[i]);
    xx[i] = x[i], yy[i] = y[i];
  }
  sort(xx + 1, xx + n + 1);
  sort(yy + 1, yy + n + 1);
  int sx, sy;
  sx = unique(xx + 1, xx + n + 1) - xx - 1;
  sy = unique(yy + 1, yy + n + 1) - yy - 1;
  for (int i = 1; i <= n; ++i) {
    x[i] = lower_bound(xx + 1, xx + sx + 1, x[i]) - xx;
    y[i] = lower_bound(yy + 1, yy + sy + 1, y[i]) - yy;
  }
  for (int i = 1; i <= n; ++i) {
    int dx = x[i], dy = y[i];
    if (visx[dx] == -1 && visy[dy] == -1)
      visx[dx] = visy[dy] = i;
    else if (visx[dx] == -1) {
      int fy = find(visy[dy]);
      fa[i] = fy;
      visx[dx] = visy[dy] = fy;
    } else if (visy[dy] == -1) {
      int fx = find(visx[dx]);
      fa[i] = fx;
      visx[dx] = visy[dy] = fx;
    } else {
      int fx = find(visx[dx]), fy = find(visy[dy]);
      if (fx == fy) {
        fa[i] = fx;
        tag[fx] = 1;
      } else {
        fa[i] = fy;
        fa[fx] = fy;
        tag[fy] |= tag[fx];
      }
      visx[dx] = visy[dy] = fy;
    }
  }
  for (int i = 1; i <= sx; ++i) {
    cntx[find(visx[i])]++;
  }
  for (int i = 1; i <= sy; ++i) cnty[find(visy[i])]++;
  long long ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (i == fa[i]) {
      long long tmp = modPow(2, cntx[i] + cnty[i]);
      if (!tag[i]) tmp--;
      ans = ans * tmp % mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
