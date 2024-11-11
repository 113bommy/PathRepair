#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxm = 55;
const int maxv = maxn * maxm / 2;
const int INF = 1e9 + 7;
const int sigma = 10;
class ACAutomata {
 public:
  int tot, hd, tl;
  int ch[maxv][sigma], tag[maxv], que[maxv], fail[maxv];
  ACAutomata() {
    tot = 1;
    return;
  }
  inline void insert(char *s, int len) {
    int u = 0;
    for (int i = (int)(0); i < (int)(len); ++i) {
      int &v = ch[u][s[i] - '0'];
      if (!v) v = tot++;
      u = v;
    }
    tag[u] = true;
    return;
  }
  inline void build() {
    hd = tl = 0;
    for (int i = (int)(0); i < (int)(sigma); ++i)
      if (ch[0][i]) que[tl++] = ch[0][i];
    for (; hd < tl; ++hd) {
      int u = que[hd];
      for (int i = (int)(0); i < (int)(sigma); ++i) {
        int &v = ch[u][i];
        if (v)
          fail[v] = ch[fail[u]][i], que[tl++] = v;
        else
          v = ch[fail[u]][i];
      }
    }
    return;
  }
} ac;
inline int cmp(char d, char x, char y, int s) {
  x -= '0', y -= '0';
  if (make_pair(s, d) < make_pair(0, x)) return -1;
  if (make_pair(s, d) == make_pair(0, x)) return 0;
  if (make_pair(s, d) == make_pair(2, y)) return 2;
  if (make_pair(s, d) > make_pair(2, y)) return 3;
  return 1;
}
int n, m;
int f[maxm][maxv][3];
char s[maxn], l[maxm], r[maxm];
inline int sub() {
  int ret = 0, pw = 1;
  for (int i = (int)(0); i < (int)(m); ++i) {
    if (r[i] < l[i]) r[i] += 10, r[i + 1] -= 1;
    (ret += 1ll * (r[i] - l[i]) * pw % INF) %= INF;
    pw = 1ll * pw * 10 % INF;
  }
  (++ret) %= INF;
  return ret;
}
int main() {
  scanf("%s%s%s", s, l, r);
  n = strlen(s);
  m = strlen(l);
  reverse(l, l + m);
  reverse(r, r + m);
  for (int i = (int)(0); i < (int)(n); ++i)
    if (i + (m >> 1) <= n) ac.insert(s + i, m >> 1);
  ac.build();
  int rt = 0;
  bool ok = true;
  for (; m > 0 && l[m - 1] == r[m - 1]; --m)
    rt = ac.ch[rt][l[m - 1] - '0'], ok &= !ac.tag[rt];
  if (m == 0) {
    printf("%d\n", !ok);
    return 0;
  }
  for (int d = (int)(0); d < (int)(sigma); ++d)
    if (!ac.tag[ac.ch[rt][d]]) {
      if (d == l[m - 1] - '0')
        f[m - 1][ac.ch[rt][d]][0] += ok;
      else if (d > l[m - 1] - '0' && d < r[m - 1] - '0')
        f[m - 1][ac.ch[rt][d]][1] += ok;
      else if (d == r[m - 1] - '0')
        f[m - 1][ac.ch[rt][d]][2] += ok;
    }
  for (int i = m - 1; i; --i)
    for (int u = (int)(0); u < (int)(ac.tot); ++u)
      for (int t = (int)(0); t < (int)(3); ++t)
        if (f[i][u][t]) {
          for (int d = (int)(0); d < (int)(sigma); ++d)
            if (!ac.tag[ac.ch[u][d]]) {
              int s = cmp(d, l[i - 1], r[i - 1], t);
              if (s >= 0 && s < 3)
                (f[i - 1][ac.ch[u][d]][s] += f[i][u][t]) %= INF;
            }
        }
  int ans = 0;
  for (int u = (int)(0); u < (int)(ac.tot); ++u)
    for (int t = (int)(0); t < (int)(3); ++t) (ans += f[0][u][t]) %= INF;
  (ans = sub() + INF - ans) %= INF;
  printf("%d\n", ans);
  return 0;
}
