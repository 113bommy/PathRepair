#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static const long long L = 233333;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) {
      return EOF;
    }
  }
  return *sss++;
}
inline char readalpha() {
  char c = getchar();
  for (; !isalpha(c); c = getchar())
    ;
  return c;
}
inline char readchar() {
  char c = getchar();
  for (; c == ' '; c = getchar())
    ;
  return c;
}
template <class T>
inline bool read(T& x) {
  bool flg = false;
  char c = getchar();
  x = 0;
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') {
      flg = true;
    } else if (c == EOF) {
      return false;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = (x << 1) + (x << 3) + (c ^ 48);
  }
  if (flg) {
    x = -x;
  }
  return true;
}
template <class T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10) {
    putchar(x | 48);
    return;
  }
  write(x / 10);
  putchar((x % 10) | 48);
}
const int maxn = 105;
const int maxm = maxn * maxn;
int n, m;
int f[maxn][maxn][256][2];
struct Edge {
  int to, nxt, dist;
} e[maxm];
int first[maxn];
inline void add_edge(int from, int to, int dist) {
  static int cnt = 0;
  e[++cnt].nxt = first[from];
  first[from] = cnt;
  e[cnt].to = to;
  e[cnt].dist = dist;
}
inline int Dp(int x, int y, int c, int k) {
  if (~f[x][y][c][k]) {
    return f[x][y][c][k];
  }
  f[x][y][c][k] = 0;
  if (!k) {
    for (int i = first[x]; i; i = e[i].nxt) {
      int to = e[i].to;
      if (e[i].dist >= c) {
        f[x][y][c][k] |= !Dp(to, y, e[i].dist, k ^ 1);
      }
    }
  } else {
    for (int i = first[y]; i; i = e[i].nxt) {
      int to = e[i].to;
      if (e[i].dist >= c) {
        f[x][y][c][k] |= !Dp(x, to, e[i].dist, k ^ 1);
      }
    }
  }
  return f[x][y][c][k];
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int f, t;
    char cc;
    cin >> f >> t >> cc;
    add_edge(f, t, cc + 1);
  }
  memset(f, 0xff, sizeof(f));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      putchar(Dp(i, j, 0, 0) ? 'A' : 'B');
    }
    puts("");
  }
  return 0;
}
