#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxn = 2e5;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const double Pi = acos(-1.0);
inline int read_int() {
  char c;
  int ret = 0, sgn = 1;
  do {
    c = getchar();
  } while ((c < '0' || c > '9') && c != '-');
  if (c == '-')
    sgn = -1;
  else
    ret = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  return sgn * ret;
}
inline long long read_ll() {
  char c;
  long long ret = 0, sgn = 1;
  do {
    c = getchar();
  } while ((c < '0' || c > '9') && c != '-');
  if (c == '-')
    sgn = -1;
  else
    ret = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  return sgn * ret;
}
inline long long quick_pow(long long base, long long index, long long p) {
  long long res = 1;
  while (index) {
    if (index & 1) res = res * base % p;
    base = base * base % p;
    index >>= 1;
  }
  return res;
}
struct point {
  bool operator<(const point& rhs) const {
    return y == rhs.y ? x < rhs.x : y > rhs.y;
  }
  point(int _x = 0, int _y = 0) { x = _x, y = _y; }
  int x, y;
} arr[maxn + 5];
int pos[maxn + 5], posy[maxn + 5], cnt[maxn + 5], c[maxn + 5], n, m,
    vx[maxn + 5];
inline void add(int x, int v) {
  for (int i = x; i <= m; i += ((i) & (-(i)))) c[i] += v;
}
inline int sum(int x) {
  int ans = 0;
  for (int i = x; i > 0; i -= ((i) & (-(i)))) ans += c[i];
  return ans;
}
long long res;
int main() {
  n = read_int();
  for (int i = 1; i <= n; ++i) {
    arr[i].x = pos[i] = read_int();
    arr[i].y = posy[i] = read_int();
  }
  sort(pos + 1, pos + 1 + n);
  sort(posy + 1, posy + 1 + n);
  m = unique(pos + 1, pos + 1 + n) - pos - 1;
  int len = unique(posy + 1, posy + 1 + n) - posy - 1;
  for (int i = 1; i <= n; ++i) {
    arr[i].x = lower_bound(pos + 1, pos + 1 + m, arr[i].x) - pos;
    arr[i].y = lower_bound(posy + 1, posy + 1 + len, arr[i].y) - posy;
  }
  sort(arr + 1, arr + 1 + n);
  int up = m + 1;
  int now = 1, next = 1;
  while (now <= n) {
    int tot = 0;
    while (arr[now].y == arr[next].y) {
      if (!cnt[arr[next].x]) add(arr[next].x, 1);
      cnt[arr[next].x] = 1;
      vx[++tot] = arr[next].x;
      next++;
    }
    vx[++tot] = m + 1;
    for (int i = 1; i <= tot - 1; i++) {
      int t1 = sum(vx[i] - 1);
      int t2 = sum(vx[i + 1] - 1) - sum(vx[i]);
      res += 1ll * (t1 + 1) * (t2 + 1);
    }
    now = next;
  }
  printf("%lld\n", res);
  return 0;
}
