#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int sz = 1 << 15;
char inbuf[sz], outbuf[sz];
char *pinbuf = inbuf + sz;
char *poutbuf = outbuf;
inline char _getchar() {
  if (pinbuf == inbuf + sz) fread(inbuf, 1, sz, stdin), pinbuf = inbuf;
  return *(pinbuf++);
}
inline void _putchar(char x) {
  if (poutbuf == outbuf + sz) fwrite(outbuf, 1, sz, stdout), poutbuf = outbuf;
  *(poutbuf++) = x;
}
inline void flush() {
  if (poutbuf != outbuf)
    fwrite(outbuf, 1, poutbuf - outbuf, stdout), poutbuf = outbuf;
}
}  // namespace IO
inline int read() {
  int v = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = v * 10 + c - '0';
    c = getchar();
  }
  return v * f;
}
const int Maxn = 500005;
int n, q, k;
int tp[Maxn], l[Maxn], r[Maxn], u[Maxn], v[Maxn], kt, kd, ke;
int Qr[Maxn];
int ed[Maxn];
vector<int> V[Maxn];
vector<pair<int, int> > T[Maxn * 4];
int par[Maxn], siz[Maxn];
int findset(int x) { return (par[x] == x) ? x : findset(par[x]); }
int Qu[Maxn * 20], Qv[Maxn * 20], kQ, Qw[Maxn * 20];
void Union(int x, int y) {
  x = findset(x);
  y = findset(y);
  if (x == y) return;
  if (siz[x] > siz[y]) swap(x, y);
  Qu[kQ] = x;
  Qv[kQ] = y;
  Qw[kQ] = par[x];
  kQ++;
  par[x] = y;
  siz[y] += siz[x];
}
void Undo(int id) {
  while (kQ > id) {
    int x = Qu[kQ - 1], y = Qv[kQ - 1], z = Qw[kQ - 1];
    par[x] = z;
    siz[y] -= siz[x];
    kQ--;
  }
}
void modify(int p, int l, int r, int lo, int hi, int x, int y) {
  if (lo <= l && r <= hi) {
    T[p].push_back(make_pair(x, y));
    return;
  }
  int mid = l + r >> 1;
  if (lo <= mid) {
    modify(p * 2, l, mid, lo, min(hi, mid), x, y);
  }
  if (hi > mid) {
    modify(p * 2 + 1, mid + 1, r, max(lo, mid + 1), hi, x, y);
  }
}
void Traverse(int p, int l, int r) {
  int st = kQ;
  for (int i = 0; i < T[p].size(); i++) {
    Union(T[p][i].first, T[p][i].second);
  }
  if (l == r) {
    printf("%d\n", siz[findset(Qr[l])]);
    Undo(st);
    return;
  }
  int mid = l + r >> 1;
  Traverse(p * 2, l, mid);
  Traverse(p * 2 + 1, mid + 1, r);
  Undo(st);
}
int main() {
  n = read();
  q = read();
  k = read();
  kt = kd = 0;
  while (q--) {
    int a = read();
    if (a == 3)
      kd++, ed[kd] = kt - 1;
    else if (a == 2) {
      tp[ke] = 2;
      l[ke] = kt++;
      r[ke] = read();
      V[kd].push_back(ke);
      ed[kd] = kt - 1;
      ke++;
      Qr[kt - 1] = r[ke - 1];
    } else {
      tp[ke] = 1;
      l[ke] = kt;
      u[ke] = read();
      v[ke] = read();
      V[kd].push_back(ke);
      ke++;
    }
  }
  for (int i = 0; i <= kd; i++) {
    for (int j = 0; j < V[i].size(); j++) {
      if (tp[V[i][j]] == 1) {
        r[V[i][j]] = (i + k - 1 >= kd) ? (kt - 1) : (ed[i + k - 1]);
        modify(1, 0, kt - 1, l[V[i][j]], r[V[i][j]], u[V[i][j]], v[V[i][j]]);
      }
    }
  }
  for (int i = 1; i <= n; i++) par[i] = i, siz[i] = 1;
  Traverse(1, 0, kt - 1);
  return 0;
}
