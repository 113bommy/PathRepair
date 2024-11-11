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
  char c = gc();
  for (; !isalpha(c); c = gc())
    ;
  return c;
}
inline char readchar() {
  char c = gc();
  for (; c == ' '; c = gc())
    ;
  return c;
}
template <class T>
inline bool read(T& x) {
  bool flg = false;
  char c = gc();
  x = 0;
  for (; !isdigit(c); c = gc()) {
    if (c == '-') {
      flg = true;
    } else if (c == EOF) {
      return false;
    }
  }
  for (; isdigit(c); c = gc()) {
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
template <class T>
inline void writesp(T x) {
  write(x);
  putchar(' ');
}
template <class T>
inline void writeln(T x) {
  write(x);
  puts("");
}
const int maxn = 105;
const int inf = 0x3f3f3f3f;
int n, m, F, T, K;
int mp[maxn][maxn];
int f[maxn][maxn];
int g[maxn][maxn];
int t[maxn][maxn];
int cnt[maxn][maxn];
bitset<maxn> cut[maxn][maxn];
struct Bus {
  int f, t;
} bus[maxn];
inline bool instp(int u, int v, int x) { return f[u][x] + f[x][v] == f[u][v]; }
inline bool instp(int u, int v, int x, int y) {
  return f[u][x] + 1 + f[y][v] == f[u][v];
}
struct ZT {
  int zh, to, bu;
  ZT(int z, int t, int b) { zh = z, to = t, bu = b; }
};
int main() {
  memset(f, 0x3f, sizeof(f));
  memset(g, 0x3f, sizeof(g));
  read(n), read(m), read(F), read(T);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u), read(v);
    f[u][v] = mp[u][v] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    f[i][i] = 0;
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      if (i != k) {
        for (int j = 1; j <= n; ++j) {
          if (j != k) {
            if (f[i][j] > f[i][k] + f[k][j]) {
              f[i][j] = f[i][k] + f[k][j];
              cut[i][j] = cut[i][k] | cut[k][j];
              cut[i][j][k] = 1;
            } else if (f[i][j] == f[i][k] + f[k][j]) {
              cut[i][j] &= cut[i][k] | cut[k][j];
            }
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cut[i][j][i] = cut[i][j][j] = 1;
    }
  }
  read(K);
  deque<ZT> q;
  q.clear();
  for (int i = 1; i <= K; ++i) {
    read(bus[i].f), read(bus[i].t);
    if (instp(bus[i].f, bus[i].t, T)) {
      g[T][i] = 1;
      q.emplace_back(1, T, i);
    }
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        if (mp[j][k] && instp(bus[i].f, bus[i].t, j, k)) {
          cnt[j][i]++;
        }
      }
    }
  }
  while (!q.empty()) {
    ZT nowzt = q.front();
    q.pop_front();
    if (nowzt.zh > g[nowzt.to][nowzt.bu]) {
      continue;
    }
    int now = nowzt.to;
    int bs = nowzt.bu;
    if (cut[bus[bs].f][bus[bs].t][now]) {
      for (int i = 1; i <= K; ++i) {
        if (i != bs && instp(bus[i].f, bus[i].t, now) &&
            g[now][i] >= g[now][bs] + 1) {
          g[now][i] = g[now][bs] + 1;
          q.emplace_back(g[now][i], now, i);
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (mp[i][now] && instp(bus[bs].f, bus[bs].t, i, now)) {
        t[i][bs] = max(g[now][bs], t[i][bs]);
        cnt[i][bs]--;
        if (!cnt[i][bs] && t[i][bs] < g[i][bs]) {
          g[i][bs] = t[i][bs];
          q.emplace_front(g[i][bs], i, bs);
        }
      }
    }
  }
  int ans = inf;
  for (int i = 1; i <= K; ++i) {
    if (cut[bus[i].f][bus[i].t][F]) {
      ans = min(ans, g[F][i]);
    }
  }
  if (ans < inf) {
    writeln(ans);
  } else {
    puts("-1");
  }
  return 0;
}
