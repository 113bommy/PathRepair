#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
const int INF = 1e9;
const int maxN = 100010;
struct point {
  int x, y, I;
};
point pt[maxN];
struct KDT {
  int root, cnt_node, lm[maxN * 2][4], ch[maxN * 2][2], Min[maxN * 2];
  void push_up(int nod) {
    Min[nod] = min(ch[nod][0] ? Min[ch[nod][0]] : INF,
                   ch[nod][1] ? Min[ch[nod][1]] : INF);
  }
  void build(int &nod, int L, int R, int type) {
    if (!nod) nod = ++cnt_node;
    if (L == R) {
      lm[nod][0] = lm[nod][1] = pt[L].x;
      lm[nod][2] = lm[nod][3] = pt[L].y;
      Min[nod] = pt[L].I;
      return;
    }
    int Mid = (L + R) / 2;
    nth_element(
        pt + L, pt + Mid, pt + R + 1,
        type ? [](point x, point y) { return x.x < y.x; }
             : [](point x, point y) { return x.y < y.y; });
    build(ch[nod][0], L, Mid, !type);
    build(ch[nod][1], Mid + 1, R, !type);
    push_up(nod);
    for (int i : {0, 1, 2, 3})
      lm[nod][i] = (i & 1 ? max(lm[ch[nod][0]][i], lm[ch[nod][1]][i])
                          : min(ch[nod][0] ? lm[ch[nod][0]][i] : INF,
                                ch[nod][1] ? lm[ch[nod][1]][i] : INF));
  }
  void modify(int nod, int L, int R, int D, int x) {
    if (L == R) {
      Min[nod] = x;
      return;
    }
    int Mid = (L + R) / 2;
    if (D <= Mid) modify(ch[nod][0], L, Mid, D, x);
    if (D > Mid) modify(ch[nod][1], Mid + 1, R, D, x);
    push_up(nod);
  }
  int query(int nod, int D, int U, int L, int R) {
    if (!nod || U < lm[nod][0] || D > lm[nod][1] || R < lm[nod][2] ||
        L > lm[nod][3])
      return INF;
    if (D <= lm[nod][0] && U >= lm[nod][1] && L <= lm[nod][2] &&
        R >= lm[nod][3])
      return Min[nod];
    return min(query(ch[nod][0], D, U, L, R), query(ch[nod][1], D, U, L, R));
  }
};
KDT kdt;
int n;
struct R_ {
  int D, U, L, R, h, I;
} rg[maxN];
bool cmp(R_ x, R_ y) { return x.h < y.h; }
int m;
point p[maxN];
int Id[maxN];
int Ans[maxN];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    rg[i].D = read();
    rg[i].U = read();
    rg[i].L = read();
    rg[i].R = read();
    rg[i].h = read();
    rg[i].I = i;
  }
  m = read();
  for (int i = 1; i <= m; i++) {
    p[i].x = read();
    p[i].y = read();
    p[i].I = i;
  }
  for (int i = 1; i <= m; i++) pt[i] = p[i];
  kdt.build(kdt.root, 1, m, 0);
  for (int i = 1; i <= m; i++) Id[pt[i].I] = i;
  sort(rg + 1, rg + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    int tmp = kdt.query(kdt.root, rg[i].D, rg[i].U, rg[i].L, rg[i].R);
    if (tmp == INF) continue;
    Ans[tmp] = rg[i].I;
    kdt.modify(kdt.root, 1, m, Id[tmp], INF);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", Ans[i]);
  return 0;
}
