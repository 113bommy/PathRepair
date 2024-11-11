#include <bits/stdc++.h>
using namespace std;
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;
template <typename T>
inline void read(T &x) {
  char ch, t = 0;
  x = 0;
  while (!isdigit(ch = (iS == iT
                            ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                               (iS == iT ? EOF : *iS++))
                            : *iS++)))
    t |= ch == '-';
  while (isdigit(ch))
    x = x * 10 + (ch ^ 48),
    ch = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
  x = t ? -x : x;
}
inline char read_alpha() {
  char c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                        (iS == iT ? EOF : *iS++))
                     : *iS++);
  while (!isalpha(c) && c != EOF)
    c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                     (iS == iT ? EOF : *iS++))
                  : *iS++);
  return c;
}
inline int read_ll() {
  long long x;
  return read(x), x;
}
inline int read_int() {
  int x;
  return read(x), x;
}
template <typename T>
inline void chkmin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void chkmax(T &a, T b) {
  a = a > b ? a : b;
}
const int inf = 114514 * 10000;
struct Node {
  int x, y;
  Node() {}
  Node(int x, int y) : x(x), y(y) {}
  inline void rd() { x = read_int(), y = read_int(); }
} a[4], b[4], r[4];
int res;
inline int dis(Node a, Node b) {
  return a.x != b.x && a.y != b.y ? inf : abs(a.x - b.x) + abs(a.y - b.y);
}
inline int GetDis() {
  int ans = inf;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      for (int k = 0; k < 4; k++) {
        if (i == k || j == k) continue;
        for (int l = 0; l < 4; l++) {
          if (i == l || j == l || k == l) continue;
          int tmp = 0;
          chkmax(tmp, dis(a[0], b[i]));
          chkmax(tmp, dis(a[1], b[j]));
          chkmax(tmp, dis(a[2], b[k]));
          chkmax(tmp, dis(a[3], b[l]));
          chkmin(ans, tmp);
          if (tmp < res) {
            res = tmp;
            r[0] = b[i];
            r[1] = b[j];
            r[2] = b[k];
            r[3] = b[l];
          }
        }
      }
    }
  }
  return ans;
}
inline int calc(int lx, int rx, int ly, int ry) {
  if (rx - lx != ry - ly) return inf;
  b[0] = Node(lx, ly), b[1] = Node(lx, ry);
  b[2] = Node(rx, ly), b[3] = Node(rx, ry);
  return GetDis();
}
int h[4], l[4], t[4];
int th[4];
int tl[4];
inline void solve(int p, int ph, int pl) {
  if (p == 4) {
    if (!ph) {
      t[0] = l[0], t[1] = l[1], t[2] = l[2], t[3] = l[3];
      sort(t, t + 4);
      if (t[0] == t[1] && t[1] != t[2] && t[2] == t[3]) {
        int d = t[2] - t[1];
        int lp = -200000000, rp = 200000000;
        while (lp + 10 < rp) {
          int midl = lp + (rp - lp) / 3;
          int midr = rp - (rp - lp) / 3;
          int dl = calc(midl, midl + d, t[1], t[2]);
          int dr = calc(midr, midr + d, t[1], t[2]);
          if (dl > dr)
            lp = midl;
          else
            rp = midr;
        }
        while (lp <= rp) calc(lp, lp + d, t[1], t[2]), ++lp;
        return;
      } else
        return;
    }
    if (!pl) {
      t[0] = h[0], t[1] = h[1], t[2] = h[2], t[3] = h[3];
      sort(t, t + 4);
      if (t[0] == t[1] && t[1] != t[2] && t[2] == t[3]) {
        int d = t[2] - t[1];
        int lp = -200000000, rp = 200000000;
        while (lp + 10 < rp) {
          int midl = lp + (rp - lp) / 3;
          int midr = rp - (rp - lp) / 3;
          int dl = calc(t[1], t[2], midl, midl + d);
          int dr = calc(t[1], t[2], midr, midr + d);
          if (dl > dr)
            lp = midl;
          else
            rp = midr;
        }
        while (lp <= rp) calc(t[1], t[2], lp, lp + d), ++lp;
        return;
      } else
        return;
    }
    th[0] = h[0], th[1] = h[1], th[2] = h[2], th[3] = h[3];
    tl[0] = l[0], tl[1] = l[1], tl[2] = l[2], tl[3] = l[3];
    sort(th, th + ph), sort(tl, tl + pl);
    int tph = unique(th, th + ph) - th;
    int tpl = unique(tl, tl + pl) - tl;
    if (tph == 2 && tpl == 2) calc(th[0], th[1], tl[0], tl[1]);
    if (tph == 2 && tpl == 1) {
      int d = th[1] - th[0];
      calc(th[0], th[1], tl[0], tl[0] + d);
      calc(th[0], th[1], tl[0] - 1, tl[0]);
    }
    if (tph == 1 && tpl == 2) {
      int d = tl[1] - tl[0];
      calc(th[0], th[0] + d, tl[0], tl[1]);
      calc(th[0] - d, th[0], tl[0], tl[1]);
    }
    return;
  }
  h[ph] = a[p].x, solve(p + 1, ph + 1, pl);
  l[pl] = a[p].y, solve(p + 1, ph, pl + 1);
}
int main() {
  int Case = read_int();
  while (Case--) {
    res = inf;
    for (int i = 0; i < 4; i++) a[i].rd();
    solve(0, 0, 0);
    if (res < inf) {
      cout << res << endl;
      for (int i = 0; i < 4; i++) cout << r[i].x << ' ' << r[i].y << endl;
    } else
      cout << "-1" << endl;
  }
  return 0;
}
