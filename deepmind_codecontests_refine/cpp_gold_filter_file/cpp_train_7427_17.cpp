#include <bits/stdc++.h>
#pragma optimize("Ofast")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma comment(linker, "/STACK:16000000")
using namespace std;
namespace Geometry {
struct point {
  double x;
  double y;
  void print() { printf("Point:x:%.8lf,y:%.8lf", x, y); }
};
struct line {
  double x;
  double c;
  void print() { printf("Line:x:%.8lf,c:%.8lf\n", x, c); }
};
line make_line(point a, point b) {
  double x = (a.x - b.x) / (a.y - b.y);
  double c = a.y - (a.x) * (x);
  return (line){x, c};
}
}  // namespace Geometry
using namespace Geometry;
const int inf = 0x3f3f3f3f;
const long long inf2 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
const int mod = 1000000007;
short pre[2048][2048], nxt[2048][2048];
short n, m;
signed k;
signed main() {
  scanf("%hd%hd%d", &n, &m, &k);
  for (short i = 0; i <= 2005; i++)
    for (short j = 0; j <= 2005; j++) nxt[i][j] = pre[i][j] = j;
  while (k--) {
    short x, y;
    scanf("%hd%hd", &x, &y);
    short cur = inf, xx = -1, yy = -1;
    for (register short i = 0; i <= n && i <= cur; i++) {
      if (x - i > 0) {
        short y1 = pre[x - i][y], y2 = nxt[x - i][y];
        if (y2 <= m && y2 - y + i <= cur) {
          cur = y2 - y + i;
          xx = x - i;
          yy = y2;
        }
        if (y1 != 0 && y - y1 + i <= cur) {
          cur = y - y1 + i;
          xx = x - i;
          yy = y1;
        }
      }
      if (x + i <= n) {
        short y1 = pre[x + i][y], y2 = nxt[x + i][y];
        if (y1 != 0 && y - y1 + i < cur) {
          cur = y - y1 + i;
          xx = x + i;
          yy = y1;
        }
        if (y2 <= m && y2 - y + i < cur) {
          cur = y2 - y + i;
          xx = x + i;
          yy = y2;
        }
      }
    }
    printf("%hd %hd\n", xx, yy);
    for (register short i = yy; nxt[xx][i] == yy; i--)
      nxt[xx][i] = nxt[xx][yy + 1];
    for (register short i = yy; pre[xx][i] == yy; i++)
      pre[xx][i] = pre[xx][yy - 1];
  }
  return 0;
}
