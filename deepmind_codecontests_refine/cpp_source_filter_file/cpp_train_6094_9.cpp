#include <bits/stdc++.h>
template <typename T>
T max(T x, T y) {
  return (x > y) ? x : y;
}
template <typename T>
T min(T x, T y) {
  return (x < y) ? x : y;
}
template <typename T>
bool chkmax(T &x, T y) {
  return (x >= y) ? 0 : (x = y, 1);
}
template <typename T>
bool chkmin(T &x, T y) {
  return (x <= y) ? 0 : (x = y, 1);
}
template <typename T>
T read(T &in) {
  in = 0;
  char ch;
  T f = 1;
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) in = in * 10 + ch - '0', ch = getchar();
  return in *= f;
}
static const int MAX1 = 500000 + 11;
static const int MAX2 = 50000 + 11;
static const int LOG_N = 20;
struct pii {
  int x, y;
  pii(int _x = 0, int _y = 0) { x = _x, y = _y; }
};
struct tree {
  pii *v;
  int *q, *len, *left, *right, *fa[LOG_N];
  void newlife(int n) {
    v = new pii[n];
    q = new int[n], len = new int[n], left = new int[n], right = new int[n];
    for (int i = (0), ir = (LOG_N - 1); i <= (ir); ++i)
      fa[i] = new int[n], memset(fa[i], 0, sizeof(int) * (n));
    memset(q, 0, sizeof(int) * (n)), memset(len, 0, sizeof(int) * (n)),
        memset(left, 0, sizeof(int) * (n)), memset(right, 0, sizeof(int) * (n));
  }
  void clear() {
    delete[] q, delete[] len;
    for (int i = (0), ir = (LOG_N - 1); i <= (ir); ++i) delete[] fa[i];
  }
  int hop(int x, int L) {
    x = q[x];
    for (int i = (LOG_N - 1), ir = (0); i >= (ir); --i)
      if (len[fa[i][x]] >= L) x = fa[i][x];
    return x;
  }
};
bool operator>(pii a, pii b) { return a.x > b.x || a.x == b.x && a.y < b.y; }
namespace SAM {
static const int SN = MAX2 << 1;
int nd, last;
int f[SN], g[SN], q[SN], r[SN], len[SN], fail[SN], ch[SN][26];
int Ct, Ht[SN], Nt[SN], to[SN];
void ins(int x, int y) { Nt[++Ct] = Ht[x], Ht[x] = Ct, to[Ct] = y; }
void init() {
  ++nd;
  memset(f, 0, sizeof(int) * (nd)), memset(g, 0, sizeof(int) * (nd)),
      memset(r, 0, sizeof(int) * (nd)), memset(q, 0, sizeof(int) * (q[0] + 1));
  memset(len, 0, sizeof(int) * (nd)), memset(fail, 0, sizeof(int) * (nd)),
      memset(ch, 0, sizeof(int) * (nd * 26));
  q[0] = 0, nd = last = 1;
}
void Extend(char c) {
  int p = last, np = ++nd;
  len[np] = len[p] + 1;
  q[f[np] = ++q[0]] = np;
  while (p && !ch[p][c]) ch[p][c] = np, p = fail[p];
  if (!p)
    fail[np] = 1;
  else {
    int q = ch[p][c];
    if (len[q] == len[p] + 1)
      fail[np] = q;
    else {
      int nq = ++nd;
      f[nq] = f[q], len[nq] = len[p] + 1;
      memcpy(ch[nq], ch[q], sizeof ch[0]);
      fail[nq] = fail[q], fail[q] = fail[np] = nq;
      while (ch[p][c] == q) ch[p][c] = nq, p = fail[p];
    }
  }
  last = np, r[np] = 1;
}
void Extend(char *s) {
  while (*s) Extend(*(s++) - 'a');
}
void UPD() {
  static int q[SN], front, back;
  memset(Ht, 0, sizeof(int) * (nd + 1)), Ct = 0;
  for (int i = (1), ir = (nd); i <= (ir); ++i)
    if (fail[i]) ins(fail[i], i);
  front = back = 0;
  q[++back] = 1;
  while (front < back) {
    int x = q[++front];
    for (int i = (Ht[x]); i; i = (Nt[i])) q[++back] = to[i];
  }
  memcpy(g, f, sizeof(int) * (nd + 1));
  for (int i = (nd), ir = (1); i >= (ir); --i)
    r[fail[q[i]]] += r[q[i]], chkmax(g[fail[q[i]]], g[q[i]]);
}
}  // namespace SAM
using SAM ::nd;
int n;
char s[MAX1], input[MAX2], *t[MAX2];
int len[MAX2], q_pos[MAX1], q_len[MAX1];
tree T[MAX2 * 4];
void make(int *q, int *fa[LOG_N], int *len) {
  memcpy(len, SAM ::len, sizeof(int) * (nd + 1));
  memcpy(fa[0], SAM ::fail, sizeof(int) * (nd + 1));
  memcpy(q, SAM ::q, sizeof(int) * (SAM ::q[0] + 1));
  for (int i = (1), ir = (LOG_N - 1); i <= (ir); ++i)
    for (int j = (1), jr = (nd); j <= (jr); ++j)
      fa[i][j] = fa[i - 1][fa[i - 1][j]];
}
void Build(int o = 1, int l = 1, int r = n) {
  if (l == r) {
    SAM ::init();
    SAM ::Extend(t[l]);
    SAM ::UPD();
    T[o].newlife(nd + 1);
    make(T[o].q, T[o].fa, T[o].len);
    for (int i = (1), ir = (nd); i <= (ir); ++i) T[o].v[i] = pii(SAM ::r[i], l);
    return;
  }
  int mid = (l + r) >> 1;
  Build(o << 1, l, mid), Build(o << 1 | 1, mid + 1, r);
  SAM ::init();
  for (int i = (l), ir = (r); i <= (ir); ++i)
    SAM ::Extend(t[i]), SAM ::last = 1;
  SAM ::UPD();
  T[o].newlife(nd + 1);
  make(T[o].q, T[o].fa, T[o].len);
  for (int i = (1), ir = (nd); i <= (ir); ++i) {
    int f = SAM ::f[i], g = SAM ::g[i], L = SAM ::len[i],
        boundary = T[o << 1].q[0];
    if (f <= boundary) T[o].left[i] = T[o << 1].hop(f, L);
    if (g > boundary) T[o].right[i] = T[o << 1 | 1].hop(g - boundary, L);
    T[o].v[i] = max(T[o << 1].v[T[o].left[i]], T[o << 1 | 1].v[T[o].right[i]]);
  }
  T[o << 1].clear(), T[o << 1 | 1].clear();
}
pii Qry(int L, int R, int state, int o = 1, int l = 1, int r = n) {
  if (L <= l && r <= R) return T[o].v[state];
  int mid = (l + r) >> 1;
  if (mid < L) return Qry(L, R, T[o].right[state], o << 1 | 1, mid + 1, r);
  if (mid >= R) return Qry(L, R, T[o].left[state], o << 1, l, mid);
  return max(Qry(L, R, T[o].left[state], o << 1, l, mid),
             Qry(L, R, T[o].right[state], o << 1 | 1, mid + 1, r));
}
int main() {
  scanf("%s", s);
  read(n);
  for (int i = (1), ir = (n); i <= (ir); ++i) {
    scanf("%s", input);
    int &L = len[i];
    L = strlen(input);
    t[i] = new char[L + 1];
    memcpy(t[i], input, sizeof(char) * L), t[i][L] = 0;
  }
  Build();
  int p = 1, L = 0;
  for (int i = (0), ir = (strlen(s) - 1); i <= (ir); ++i) {
    char c = s[i] - 'a';
    while (p && !SAM ::ch[p][c]) p = SAM ::fail[p], L = SAM ::len[p];
    if (!p) p = 1, L = 0;
    if (SAM ::ch[p][c]) p = SAM ::ch[p][c], ++L;
    q_pos[i + 1] = p, q_len[i + 1] = L;
  }
  int q;
  read(q);
  while (q--) {
    int l, r, pl, pr;
    read(l), read(r), read(pl), read(pr);
    if (q_len[pr] < pr - pl + 1) {
      printf("%d %dn", l, 0);
      continue;
    }
    pii ANS = Qry(l, r, T[1].hop(SAM ::f[q_pos[pr]], pr - pl + 1));
    printf("%d %dn", max(l, ANS.y), ANS.x);
  }
  return 0;
}
