#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
struct XT {
  int G[2][(1 << 24)], S[(1 << 24)], P;
  int al() { return G[0][P] = G[1][P] = -1, P++; }
  void ad(int u, int a, int p) {
    ++S[u];
    if (!p) {
      return;
    }
    if (!~G[a & 1][u]) G[a & 1][u] = al();
    ad(G[a & 1][u], a >> 1, p - 1);
  }
  bool del(int u, int a, int p) {
    --S[u];
    if (!p) return !S[u];
    if (del(G[a & 1][u], a >> 1, p - 1))
      return G[a & 1][u] = -1, !~G[!(a & 1)][u];
    return 0;
  }
  void CLR() { al(); }
  int SM(int u, bool x) { return ~G[x][u] ? S[G[x][u]] : 0; }
  int xt(int u, int a, int l, int p, bool x) {
    return ~G[x][u] ? led(G[x][u], a >> 1, l >> 1, p - 1) : 0;
  }
  int led(int u, int a, int l, int p) {
    if (!p) return 0;
    if (a & 1) {
      if (l & 1) return xt(u, a, l, p, 0) + SM(u, 1);
      return xt(u, a, l, p, 1);
    }
    if (l & 1) return xt(u, a, l, p, 1) + SM(u, 0);
    return xt(u, a, l, p, 0);
  }
} T;
int rv(int a) {
  int b = 0;
  for (int i(0); i < (27); i++) b <<= 1, b |= a & 1, a >>= 1;
  return b;
}
int a, p, l;
int main(void) {
  T.CLR();
  int _;
  scanf("%d", &_);
  for (int i(0); i < _; i++) {
    scanf("%d%d", &a, &p);
    if (a == 1) T.ad(0, rv(p), (27));
    if (a == 2) T.del(0, rv(p), (27));
    if (a == 3) scanf("%d", &l), printf("%d\n", T.led(0, rv(p), rv(l), (27)));
  }
  return 0;
}
