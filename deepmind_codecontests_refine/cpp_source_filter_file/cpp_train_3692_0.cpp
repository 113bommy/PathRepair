#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int n, m;
int fa[N], num[N];
namespace LCT {
struct NODE {
  int fa, ch[2];
  int siz, ssiz;
  long long ssqr;
  long long sum, ans, sans;
  inline int& operator[](const int& i) { return ch[i]; }
} nod[N];
inline int Direc(const int& u) { return nod[nod[u].fa][1] == u; }
inline bool IfRoot(const int& u) {
  return nod[nod[u].fa][0] != u && nod[nod[u].fa][1] != u;
}
void SetChild(const int& fa, const int& d, const int& ch) {
  nod[fa][d] = ch;
  if (ch) nod[ch].fa = fa;
}
void PushUp(const int& u) {
  NODE &L = nod[nod[u][0]], &R = nod[nod[u][1]];
  nod[u].siz = L.siz + R.siz + nod[u].ssiz;
  nod[u].sum = L.sum + R.sum + nod[u].siz * num[u];
  nod[u].ans = L.ans + R.ans + nod[u].sans +
               num[u] * ((1ll * (nod[u].ssiz) * (nod[u].ssiz)) - nod[u].ssqr) +
               num[u] * (2ll * nod[u].ssiz * R.siz) +
               2ll * L.sum * (R.siz + nod[u].ssiz);
}
void Rotate(const int& x) {
  int y = nod[x].fa, d = Direc(x);
  if (IfRoot(y))
    nod[x].fa = nod[y].fa;
  else
    SetChild(nod[y].fa, Direc(y), x);
  SetChild(y, d, nod[x][!d]);
  SetChild(x, !d, y);
  PushUp(y), PushUp(x);
}
void Splay(int x) {
  while (!IfRoot(x)) {
    int y = nod[x].fa;
    if (!IfRoot(y)) {
      if (Direc(x) == Direc(y))
        Rotate(y);
      else
        Rotate(x);
    }
    Rotate(x);
  }
  PushUp(x);
}
void ModifySub(const int& u, const int& v, const int& tim) {
  nod[u].ssiz += tim * nod[v].siz;
  nod[u].sans += tim * nod[v].ans;
  nod[u].ssqr += tim * (1ll * (nod[v].siz) * (nod[v].siz));
}
void Access(int x) {
  for (int y = 0; x; y = x, x = nod[x].fa) {
    Splay(x);
    ModifySub(x, nod[x][1], 1);
    SetChild(x, 1, y);
    ModifySub(x, nod[x][1], -1);
    PushUp(x);
  }
}
void Link(const int& x, const int& rt) {
  Access(x), Splay(x);
  Access(rt), Splay(rt);
  nod[rt].fa = x;
  ModifySub(x, rt, 1);
  PushUp(x);
}
void Cut(const int& fa, const int& x) {
  Access(fa), Splay(fa), Splay(x);
  nod[x].fa = 0;
  ModifySub(fa, x, -1);
  PushUp(fa);
}
bool IfAnc(const int& anc, const int& u) {
  Access(u), Splay(u), Splay(anc);
  return !IfRoot(u);
}
}  // namespace LCT
using LCT::Access;
using LCT::Cut;
using LCT::Link;
using LCT::nod;
using LCT::Splay;
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) scanf("%d", &fa[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    nod[i].siz = nod[i].ssiz = 1, nod[i].ans = nod[i].sum = num[i];
  }
  for (int i = 2; i <= n; i++) Link(fa[i], i);
  Access(1), Splay(1);
  printf("%.10f\n", 1.0 * nod[1].ans / n / n);
  scanf("%d", &m);
  while (m--) {
    char cmd[5] = {};
    scanf("%s", cmd);
    if (cmd[0] == 'P') {
      int u, v;
      scanf("%d%d", &u, &v);
      if (LCT::IfAnc(u, v)) swap(u, v);
      Cut(fa[u], u);
      Link(fa[u] = v, u);
      Access(1), Splay(1);
      printf("%.10f\n", 1.0 * nod[1].ans / n / n);
    } else {
      int u, key;
      scanf("%d%d", &u, &key);
      Access(u), Splay(u);
      num[u] = key;
      LCT::PushUp(u);
      printf("%.10f\n", 1.0 * nod[u].ans / n / n);
    }
  }
  return 0;
}
