#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
template <class T>
T gcd(T a, T b) {
  return !b ? a : gcd(b, a % b);
}
template <class T>
inline void umin(T &x, T y) {
  x = x < y ? x : y;
}
template <class T>
inline void umax(T &x, T y) {
  x = x > y ? x : y;
}
inline unsigned int R() {
  static unsigned int seed = 416;
  return seed ^= seed >> 5, seed ^= seed << 17, seed ^= seed >> 13;
}
const int N = 666666, msk = (1 << 30) - 1, inf = 0x7f7f7f7f;
const long long base = 1e18;
long long ans0, ans, cur;
int n, nxt[N], s[N], top[N];
int zkw[N << 2], m;
map<int, int> Map;
void modify(int p, int x) {
  zkw[m + p] = x;
  for (int i = m + p >> 1; i; i >>= 1)
    zkw[i] = min(zkw[i << 1], zkw[i << 1 | 1]);
}
int qry(int l, int r) {
  l = l + m - 1;
  r = r + m + 1;
  int res = inf;
  while ((l >> 1) != (r >> 1)) {
    if (!(l & 1)) umin(res, zkw[l + 1]);
    if (r & 1) umin(res, zkw[r - 1]);
    l >>= 1;
    r >>= 1;
  }
  return res;
}
int main() {
  unsigned int ans1 = 0, ans26 = 0;
  int q;
  read(q);
  int pos = 0;
  for (m = 1; m <= q + 1; m <<= 1)
    ;
  memset(zkw, inf, sizeof(zkw));
  for (register int tt = (1); tt <= (q); tt++) {
    char t[3];
    scanf("%s", t);
    int w;
    read(w);
    w ^= ans1 & msk;
    int c = (t[0] - 'a' + ans26) % 26;
    s[++n] = c;
    top[n - 1] = s[n] != s[nxt[n - 1] + 1] ? n - 1 : top[nxt[n - 1]];
    modify(n, w);
    int u = n - 1;
    while (u) {
      if (s[u + 1] != s[n]) {
        int qaq = qry(n - u, n - 1);
        Map[qaq]--;
        cur -= qaq;
        u = nxt[u];
      } else
        u = nxt[top[u]];
    }
    if (s[1] == s[n]) Map[inf]++, cur += inf;
    while (!Map.empty() && (*Map.rbegin()).first > w) {
      cur -= 1ll * ((*Map.rbegin()).first - w) * (*Map.rbegin()).second;
      Map[w] += (*Map.rbegin()).second;
      Map.erase(--Map.end());
    }
    if (tt > 1) {
      while (pos && s[n] != s[pos + 1]) pos = nxt[pos];
      if (s[n] == s[pos + 1]) pos++;
      nxt[n] = pos;
    }
    ans += cur;
    ans1 += cur;
    ans26 = (ans26 + cur) % 26;
    if (ans >= base) ans -= base, ans0++;
    if (!ans0)
      printf("%lld\n", ans);
    else
      printf("%lld%018lld\n", ans0, ans);
  }
  return 0;
}
