#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
inline char gc() {
  return getchar();
  static const int maxs = 1 << 16;
  static char buf[maxs], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, maxs, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long rd() {
  long long x = 0;
  char c = gc();
  bool neg = 0;
  while (c < '0' || c > '9') {
    if (c == '-') neg = 1;
    c = gc();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = gc();
  return neg ? (~x + 1) : x;
}
struct Node {
  long long x, y, v;
} p[maxn];
int N;
long long f[maxn];
int q[maxn], hd = 1, tl;
inline bool cmp(Node a, Node b) { return a.x < b.x; }
inline double getk(int a, int b) {
  return 1.0 * (f[a] - f[b]) / (p[a].x - p[b].x);
}
int main() {
  int i, j, k;
  N = rd();
  for (i = 1; i <= N; i++) {
    p[i].x = rd(), p[i].y = rd(), p[i].v = rd();
  }
  sort(p + 1, p + N + 1, cmp);
  q[hd = tl = 1] = 0;
  for (i = 1; i <= N; i++) {
    while (hd < tl && getk(q[hd], q[hd + 1]) > p[i].y) hd++;
    f[i] = (p[i].x - p[q[hd]].x) * p[i].y - p[i].v + f[q[hd]];
    while (hd < tl && getk(q[tl], q[tl - 1]) < getk(q[tl], i)) tl--;
    q[++tl] = i;
  }
  long long ans = 0;
  for (i = 1; i <= N; i++) ans = max(ans, f[i]);
  printf("%I64d\n", ans);
  return 0;
}
