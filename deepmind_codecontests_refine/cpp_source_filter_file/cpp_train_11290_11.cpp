#include <bits/stdc++.h>
const unsigned long long KEY = 131;
const int MAXN = 3e5 + 5;
template <typename _T>
void read(_T &x) {
  x = 0;
  char c = getchar();
  _T f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c & 15);
    c = getchar();
  }
  x *= f;
}
template <typename _T>
void write(_T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename _T>
_T MIN(const _T x, const _T y) {
  return x > y ? y : x;
}
struct nodeS {
  unsigned long long has;
  int fur;
  nodeS(unsigned long long H = 0, int F = 0) {
    has = H;
    fur = F;
  }
  bool operator!=(const nodeS another) { return has != another.has; }
} nodeL[MAXN * 4], nodeR[MAXN * 4];
int N;
int a[MAXN];
unsigned long long bas[MAXN];
nodeS Merge(const nodeS lch, const nodeS rch) {
  return nodeS(lch.has * bas[rch.fur] + rch.has, lch.fur + rch.fur);
}
void Upt(const int x) {
  nodeL[x] = Merge(nodeL[x << 1], nodeL[x << 1 | 1]);
  nodeR[x] = Merge(nodeR[x << 1 | 1], nodeR[x << 1]);
}
void Build(const int x, const int l, const int r) {
  if (l == r) {
    nodeL[x] = nodeR[x] = nodeS(0, 1);
    return;
  }
  int mid = (l + r) >> 1;
  Build(x << 1, l, mid);
  Build(x << 1 | 1, mid + 1, r);
  Upt(x);
}
void Modify(const int x, const int l, const int r, const int segP,
            const int segW) {
  if (l == r) {
    nodeL[x] = nodeR[x] = nodeS(segW, segW);
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= segP)
    Modify(x << 1, l, mid, segP, segW);
  else
    Modify(x << 1 | 1, mid + 1, r, segP, segW);
  Upt(x);
}
nodeS QueryL(const int x, const int l, const int r, const int segL,
             const int segR) {
  if (l > segR || r < segL) return nodeS(0, 0);
  if (l >= segL && r <= segR) return nodeL[x];
  int mid = (l + r) >> 1;
  return Merge(QueryL(x << 1, l, mid, segL, segR),
               QueryL(x << 1 | 1, mid + 1, r, segL, segR));
}
nodeS QueryR(const int x, const int l, const int r, const int segL,
             const int segR) {
  if (l > segR || r < segL) return nodeS(0, 0);
  if (l >= segL && r <= segR) return nodeR[x];
  int mid = (l + r) >> 1;
  return Merge(QueryR(x << 1 | 1, mid + 1, r, segL, segR),
               QueryR(x << 1, l, mid, segL, segR));
}
int main() {
  bas[0] = 1;
  for (int i = 1; i < MAXN; ++i) bas[i] = bas[i - 1] * KEY;
  read(N);
  for (int i = 1; i <= N; ++i) read(a[i]);
  bool Ans = 0;
  Build(1, 1, N);
  for (int i = 1; i <= N; ++i) {
    Modify(1, 1, N, a[i], 1);
    int aimS = MIN(a[i] - 1, N - a[i]);
    if (aimS <= 0) continue;
    if (QueryL(1, 1, N, a[i] - aimS, a[i] - 1) !=
        QueryR(1, 1, N, a[i] + 1, a[i] + aimS)) {
      Ans = 1;
      puts("Y");
      break;
    }
  }
  if (!Ans) puts("N");
  return 0;
}
