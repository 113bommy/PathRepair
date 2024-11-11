#include <bits/stdc++.h>
#pragma G++ optimize(2)
#pragma GCC optimize(2)
namespace FastIO {
__inline__ __attribute__((always_inline)) char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
__inline__ __attribute__((always_inline)) int read() {
  char t;
  int u = 0, k = 1;
  t = nc();
  while (t < '0' || t > '9') {
    if (t == '-') k = -1;
    t = nc();
  }
  while (t >= '0' && t <= '9') {
    u = u * 10 + t - '0';
    t = nc();
  }
  return u * k;
}
template <typename T>
__inline__ __attribute__((always_inline)) void read(T &u) {
  char t;
  T k = 1;
  u = 0;
  t = nc();
  while (t < '0' || t > '9') {
    if (t == '-') k = -1;
    t = nc();
  }
  while (t >= '0' && t <= '9') {
    u = u * 10 + t - '0';
    t = nc();
  }
  if (t == '.') {
    T mass = 0.1;
    t = nc();
    while (t >= '0' && t <= '9') {
      u += mass * (t - '0');
      mass /= 10;
      t = nc();
    }
  }
  u *= k;
}
__inline__ __attribute__((always_inline)) int read(char asd[]) {
  char t = nc();
  int u = 0;
  while (t == ' ' || t == '\n' || t == '\r') t = nc();
  if (t == EOF) return -1;
  while (t != ' ' && t != '\n' && t != EOF && t != '\r') asd[u++] = t, t = nc();
  asd[u] = '\0';
  return u;
}
char sr[1 << 23], z[23];
int C = -1, Z;
__inline__ __attribute__((always_inline)) void wer(int x, char T) {
  int y = 0;
  if (x < 0) y = 1, x = -x;
  while (z[++Z] = x % 10 + '0', x /= 10)
    ;
  if (y) z[++Z] = '-';
  while (sr[++C] = z[Z], --Z)
    ;
  sr[++C] = T;
}
__inline__ __attribute__((always_inline)) void wer(char T[], char QWQ) {
  for (int i = 0; T[i] != '\0'; i++) sr[++C] = T[i];
  sr[++C] = QWQ;
}
__inline__ __attribute__((always_inline)) void out() {
  fwrite(sr, 1, C + 1, stdout);
  C = -1;
}
}  // namespace FastIO
using namespace std;
using namespace FastIO;
const int N = 5e5 + 5;
struct oath {
  int a, b, l, r;
};
__inline__ __attribute__((always_inline)) bool operator<(const oath &x,
                                                         const oath &y) {
  return x.l > y.l;
}
priority_queue<oath> Heap;
vector<oath> Map[N][2];
int tim[N][2], n, m;
void Extend(int x, int l, int r, int opt) {
  tim[x][opt] = max(tim[x][opt], r);
  for (auto it : Map[x][opt]) {
    oath tp = it;
    if (l > it.r) continue;
    it.l = l;
    Heap.push(it);
  }
  Map[x][opt].clear();
}
signed main() {
  n = read();
  m = read();
  if (n == 1) return puts("0"), 0;
  while (m--) {
    int a = read(), b = read(), l = read(), r = read() - 1, opt = (r - l) & 1;
    Heap.push((oath){a, b, l, r - opt});
    Heap.push((oath){b, a, l, r - opt});
    Heap.push((oath){a, b, l + 1, r - (opt ^ 1)});
    Heap.push((oath){b, a, l + 1, r - (opt ^ 1)});
  }
  memset(tim, -1, sizeof tim);
  tim[1][0] = 0;
  while (!Heap.empty()) {
    oath tp = Heap.top();
    Heap.pop();
    int a = tp.a, b = tp.b, opt = tp.l & 1;
    if (tp.l > tp.r) continue;
    if (tim[a][opt] >= tp.l) {
      if (b == n) return cout << tp.l + 1, 0;
      Extend(b, tp.l + 1, tp.r + 1, opt ^ 1);
    } else
      Map[a][opt].push_back(tp);
  }
  puts("-1");
  return 0;
}
