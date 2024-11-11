#include <bits/stdc++.h>
using namespace std;
namespace io {
const int SI = 1 << 21 | 1;
char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
int f, t;
inline void flush() { fwrite(OB, 1, OS - OB, stdout), OS = OB; }
inline void pc(char x) {
  *OS++ = x;
  if (OS == OT) flush();
}
template <class I>
inline void rd(I &x) {
  for (f = 1, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                              IS == IT ? EOF : *IS++)
                            : *IS++);
       c < '0' || c > '9';
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15),
      c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                      IS == IT ? EOF : *IS++)
                    : *IS++))
    ;
  x *= f;
}
template <class I>
inline void print(I x, char k = '\n') {
  if (!x) pc('0');
  if (x < 0) pc('-'), x = -x;
  while (x) ch[++t] = x % 10 + '0', x /= 10;
  while (t) pc(ch[t--]);
  pc(k);
}
struct Flush {
  ~Flush() { flush(); }
} flusher;
}  // namespace io
using io::print;
using io::rd;
template <class I>
inline I Min(I x, I y) {
  return x < y ? x : y;
}
template <class I>
inline I Max(I x, I y) {
  return x > y ? x : y;
}
template <class I>
inline void Swap(I &x, I &y) {
  x ^= y ^= x ^= y;
}
const int N = 31, M = 1e3 + 1;
int n, m, a[N][N], b[N][N], ca[M], cb[M];
vector<pair<int, int> > ans;
inline bool work1(int x, int y) {
  if (x == y) return 0;
  int c[N];
  for (int i = 1; i <= m; i++) c[i] = a[1][i];
  if (x < y)
    for (int i = x; i < y; i++) Swap(c[i], c[i + 1]);
  else
    for (int i = y; i > x; i--) Swap(c[i], c[i - 1]);
  for (int i = 1; i <= m; i++)
    if (c[i] ^ b[1][i]) return 0;
  return 1;
}
inline bool work2(int x, int y) {
  if (x == y) return 0;
  int c[N];
  for (int i = 1; i <= n; i++) c[i] = a[i][1];
  if (x < y)
    for (int i = x; i < y; i++) Swap(c[i], c[i + 1]);
  else
    for (int i = y; i > x; i--) Swap(c[i], c[i - 1]);
  for (int i = 1; i <= n; i++)
    if (c[i] ^ b[i][1]) return 0;
  return 1;
}
inline void smove(int x, int y) {
  if (ans.size()) {
    Swap(a[ans.back().first][ans.back().second], a[x][y]);
    if (ans.size() >= 2u && ans[ans.size() - 2] == make_pair(x, y)) {
      ans.pop_back();
      return;
    }
  }
  ans.push_back(make_pair(x, y));
}
inline void orzl(int cx, int cy) {
  if (cx == 1) {
    for (int i = 1; i <= cy; i++) smove(2, i);
    smove(cx, cy);
    smove(cx, cy - 1);
    for (int i = cy; i >= 1; i--) smove(2, i);
  } else {
    for (int i = 2; i <= cy; i++) smove(1, i);
    for (int i = 2; i < cx; i++) smove(i, cy);
    smove(cx, cy);
    smove(cx, cy - 1);
    for (int i = cx - 1; i >= 2; i--) smove(i, cy);
    for (int i = cy; i >= 2; i--) smove(1, i);
  }
  smove(1, 1);
}
inline void orzr(int cx, int cy) {
  if (cx == 1) {
    for (int i = 1; i <= cy; i++) smove(2, i);
    smove(cx, cy);
    smove(cx, cy + 1);
    for (int i = cy; i >= 1; i--) smove(2, i);
  } else {
    for (int i = 2; i <= cy; i++) smove(1, i);
    for (int i = 2; i < cx; i++) smove(i, cy);
    smove(cx, cy);
    smove(cx, cy + 1);
    for (int i = cx - 1; i >= 2; i--) smove(i, cy);
    for (int i = cy; i >= 2; i--) smove(1, i);
  }
  smove(1, 1);
}
inline void orzu(int cx, int cy) {
  if (cy == 1) {
    for (int i = 1; i <= cx; i++) smove(i, 2);
    smove(cx, cy);
    smove(cx - 1, cy);
    for (int i = cx; i >= 1; i--) smove(i, 2);
  } else {
    for (int i = 2; i <= cx; i++) smove(i, 1);
    for (int i = 2; i < cy; i++) smove(cx, i);
    smove(cx, cy);
    smove(cx - 1, cy);
    for (int i = cy - 1; i >= 2; i--) smove(cx, i);
    for (int i = cx; i >= 2; i--) smove(i, 1);
  }
  smove(1, 1);
}
inline void orzd(int cx, int cy) {
  if (cy == 1) {
    for (int i = 1; i <= cx; i++) smove(i, 2);
    smove(cx, cy);
    smove(cx + 1, cy);
    for (int i = cx; i >= 1; i--) smove(i, 2);
  } else {
    for (int i = 2; i <= cx; i++) smove(i, 1);
    for (int i = 2; i < cy; i++) smove(cx, i);
    smove(cx, cy);
    smove(cx + 1, cy);
    for (int i = cy - 1; i >= 2; i--) smove(cx, i);
    for (int i = cx; i >= 2; i--) smove(i, 1);
  }
  smove(1, 1);
}
inline void orzmove(int sx, int sy, int tx, int ty) {
  if (sx > tx) {
    swap(sx, tx);
    swap(sy, ty);
  }
  for (int i = sx; i < tx; i++) orzd(i, sy);
  if (sy == ty) {
    for (int i = tx - 1; i > sx; i--) orzu(i, sy);
  } else if (sy < ty) {
    for (int i = sy; i < ty; i++) orzr(tx, i);
    for (int i = ty - 1; i > sy; i--) orzl(tx, i);
    for (int i = tx; i > sx; i--) orzu(i, sy);
  } else {
    for (int i = sy; i > ty; i--) orzl(tx, i);
    for (int i = ty + 1; i < sy; i++) orzr(tx, i);
    for (int i = tx; i > sx; i--) orzu(i, sy);
  }
}
int main() {
  rd(n), rd(m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      rd(a[i][j]);
      ++ca[a[i][j]];
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      rd(b[i][j]);
      ++cb[b[i][j]];
    }
  for (int i = 1; i < M; i++)
    if (ca[i] ^ cb[i]) return puts("-1"), 0;
  if (n == 1) {
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++)
        if (work1(i, j)) {
          if (i < j) {
            print(j - i);
            for (int k = i; k <= j; k++) print(1, ' '), print(k);
          } else {
            print(i - j);
            for (int k = i; k >= j; k--) print(1, ' '), print(k);
          }
          return 0;
        }
    return puts("-1"), 0;
  }
  if (m == 1) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (work2(i, j)) {
          if (i < j) {
            print(j - i);
            for (int k = i; k <= j; k++) print(k, ' '), print(1);
          } else {
            print(i - j);
            for (int k = i; k >= j; k--) print(k, ' '), print(1);
          }
          return 0;
        }
    return puts("-1"), 0;
  }
  int cx = -1, cy;
  for (int i = 1; i <= n && !~cx; i++)
    for (int j = 1; j <= m && !~cx; j++)
      if (a[i][j] == b[1][1]) cx = i, cy = j;
  for (int i = cx; i > 1; i--) smove(i, cy);
  for (int i = cy; i; i--) smove(1, i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cx = -1;
      for (int x = i; x <= n && !~cx; x++)
        for (int y = x == i ? j : 1; y <= m && !~cx; y++)
          if (a[x][y] == b[i][j]) cx = x, cy = y;
      if (cx == i && cy == j) continue;
      orzmove(cx, cy, i, j);
    }
  print((int)ans.size() - 1);
  for (unsigned int i = 0; i < ans.size(); i++)
    print(ans[i].first, ' '), print(ans[i].second);
  return 0;
}
