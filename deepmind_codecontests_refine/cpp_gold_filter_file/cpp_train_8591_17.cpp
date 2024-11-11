#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int T, p[5], ans, vis[5], cnt;
namespace FastIO {
constexpr int SIZE = (1 << 21) + 1;
int num = 0, f;
char ibuf[SIZE], obuf[SIZE], que[65], *iS, *iT, *oS = obuf,
                                                *oT = obuf + SIZE - 1, c;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char c) {
  *oS++ = c;
  if (oS == oT) flush();
}
inline void getc(char &c) {
  for (c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       (c != '0' && c != '1') && c != EOF;
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
}
inline void reads(char *st) {
  char c;
  int n = 0;
  getc(st[++n]);
  for (c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c == '0' || c == '1';
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    st[++n] = c;
}
template <class I>
inline void read(I &x) {
  for (f = 1, c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9';
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = (x << 3) + (x << 1) + (c & 15);
  x *= f;
}
template <class I>
inline void print(I x) {
  if (x < 0) putc('-'), x = -x;
  if (!x) putc('0');
  while (x) que[++num] = x % 10 + 48, x /= 10;
  while (num) putc(que[num--]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_Flusher_;
}  // namespace FastIO
using FastIO ::print;
using FastIO ::putc;
using FastIO ::read;
using FastIO ::reads;
struct dot {
  int x, y;
} a[5], b[5], anss[5], d[30];
void get(int x, int y) {
  if (a[x].x != a[y].x && a[x].y != a[y].y) {
    d[++cnt] = (dot){a[x].x, a[y].y};
    d[++cnt] = (dot){a[y].x, a[x].y};
  }
}
void heng() {
  for (int i = 1; i <= 4; i++) p[i] = a[i].y;
  sort(p + 1, p + 5);
  if (p[1] != p[2] || p[3] != p[4]) return;
  int D = p[3] - p[2], x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  for (int i = 1; i <= 4; i++) {
    if (a[i].y == p[1]) {
      if (x1)
        x2 = a[i].x;
      else
        x1 = a[i].x;
    } else {
      if (y1)
        y2 = a[i].x;
      else
        y1 = a[i].x;
    }
  }
  int X1 = min(min(x1, x2), max(x1, x2) - D),
      X2 = max(min(x1, x2), max(x1, x2) - D);
  int Y1 = min(min(y1, y2), max(y1, y2) - D),
      Y2 = max(min(y1, y2), max(y1, y2) - D);
  int X = min(X1, Y1), Y = max(X2, Y2);
  d[++cnt] = (dot){(X + Y) / 2, p[1]};
}
void shu() {
  for (int i = 1; i <= 4; i++) p[i] = a[i].x;
  sort(p + 1, p + 5);
  if (p[1] != p[2] || p[3] != p[4]) return;
  int D = p[3] - p[2], x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  for (int i = 1; i <= 4; i++) {
    if (a[i].x == p[1]) {
      if (x1)
        x2 = a[i].y;
      else
        x1 = a[i].y;
    } else {
      if (y1)
        y2 = a[i].y;
      else
        y1 = a[i].y;
    }
  }
  int X1 = min(min(x1, x2), max(x1, x2) - D),
      X2 = max(min(x1, x2), max(x1, x2) - D);
  int Y1 = min(min(y1, y2), max(y1, y2) - D),
      Y2 = max(min(y1, y2), max(y1, y2) - D);
  int X = min(X1, Y1), Y = max(X2, Y2);
  d[++cnt] = (dot){p[1], (X + Y) / 2};
}
void dfs(int x, int maxx) {
  if (maxx > ans) return;
  if (x == 5) {
    for (int i = 1; i <= 4; i++) anss[i] = b[p[i]];
    ans = maxx;
    return;
  }
  for (int i = 1; i <= 4; i++)
    if (a[i].x == b[x].x || a[i].y == b[x].y) {
      if (vis[i]) continue;
      p[i] = x;
      vis[i] = 1;
      dfs(x + 1, max(maxx, max(abs(a[i].x - b[x].x), abs(a[i].y - b[x].y))));
      vis[i] = 0;
    }
}
void doit(int x) {
  for (int i = 1; i <= cnt; i++) {
    b[1] = (dot){d[i].x, d[i].y};
    b[2] = (dot){d[i].x + x, d[i].y};
    b[3] = (dot){d[i].x, d[i].y + x};
    b[4] = (dot){d[i].x + x, d[i].y + x};
    dfs(1, 0);
    b[1] = (dot){d[i].x, d[i].y};
    b[2] = (dot){d[i].x - x, d[i].y};
    b[3] = (dot){d[i].x, d[i].y + x};
    b[4] = (dot){d[i].x - x, d[i].y + x};
    dfs(1, 0);
    b[1] = (dot){d[i].x, d[i].y};
    b[2] = (dot){d[i].x + x, d[i].y};
    b[3] = (dot){d[i].x, d[i].y - x};
    b[4] = (dot){d[i].x + x, d[i].y - x};
    dfs(1, 0);
    b[1] = (dot){d[i].x, d[i].y};
    b[2] = (dot){d[i].x - x, d[i].y};
    b[3] = (dot){d[i].x, d[i].y - x};
    b[4] = (dot){d[i].x - x, d[i].y - x};
    dfs(1, 0);
  }
}
int main() {
  int T;
  read(T);
  while (T--) {
    ans = inf;
    cnt = 0;
    for (int i = 1; i <= 4; i++) read(a[i].x), read(a[i].y), d[++cnt] = a[i];
    heng();
    shu();
    for (int i = 1; i <= 4; i++)
      for (int j = i + 1; j <= 4; j++) get(i, j);
    for (int i = 1; i <= 4; i++)
      for (int j = i + 1; j <= 4; j++)
        doit(abs(a[i].x - a[j].x)), doit(a[i].y - a[j].y);
    if (ans == inf)
      printf("-1\n");
    else {
      printf("%d\n", ans);
      for (int i = 1; i <= 4; i++) printf("%d %d\n", anss[i].x, anss[i].y);
    }
  }
}
