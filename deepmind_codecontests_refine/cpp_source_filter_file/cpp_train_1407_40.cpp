#include <bits/stdc++.h>
using namespace std;
const int N = 400000 + 10;
int rd() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
struct edge {
  int x, y, z, i;
  bool operator<(const edge &bb) const { return z < bb.z; }
} e[N];
priority_queue<edge> hp;
int n, m, fa[N], ch[N][2], sz[N], isz[N], va[N], de[N];
bool tg[N], ban[N];
bool nrt(int x) { return ch[fa[x]][0] == x || ch[fa[x]][1] == x; }
void psup(int x) {
  sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + isz[x] + (x <= n);
  de[x] = va[de[ch[x][0]]] > va[de[ch[x][1]]] ? de[ch[x][0]] : de[ch[x][1]];
  if (x > n) de[x] = va[de[x]] > va[x] ? de[x] : x;
}
void rev(int x) {
  if (x) swap(ch[x][0], ch[x][1]), tg[x] ^= 1;
}
void rot(int x) {
  int y = fa[x], z = fa[y], yy = ch[y][1] == x, w = ch[x][!yy];
  if (nrt(y)) ch[z][ch[z][1] == y] = x;
  ch[x][!yy] = y, ch[y][yy] = w;
  if (w) fa[w] = y;
  fa[y] = x, fa[x] = z;
  psup(y);
}
void psdn(int x) {
  if (tg[x]) rev(ch[x][0]), rev(ch[x][1]), tg[x] = 0;
}
void ppush(int x) {
  if (nrt(x)) ppush(fa[x]);
  psdn(x);
}
void spl(int x) {
  ppush(x);
  while (nrt(x)) {
    int y = fa[x], z = fa[y];
    if (nrt(y)) ((ch[y][1] == x) ^ (ch[z][1] == y)) ? rot(x) : rot(y);
    rot(x);
  }
  psup(x);
}
void acs(int x) {
  for (int y = 0; x; y = x, x = fa[x]) {
    spl(x);
    isz[x] += sz[ch[x][1]];
    ch[x][1] = y;
    isz[x] -= sz[ch[x][1]];
    psup(x);
  }
}
void mkrt(int x) { acs(x), spl(x), rev(x); }
int fdrt(int x) {
  acs(x), spl(x), psdn(x);
  while (ch[x][0]) x = ch[x][0], psdn(x);
  spl(x);
  return x;
}
void split(int x, int y) { mkrt(x), acs(y), spl(y); }
void link(int x, int y) { split(x, y), fa[x] = y, isz[y] += sz[x], psup(y); }
void cut(int x, int y) { split(x, y), fa[x] = ch[y][0] = 0, psup(y); }
void cte(int i) {
  int x = e[i - n].x, y = e[i - n].y;
  ban[i - n] = 1;
  cut(x, i), cut(y, i);
}
void ade(int i) {
  int x = e[i - n].x, y = e[i - n].y;
  va[i] = e[i - n].z;
  if (fdrt(x) == fdrt(y)) {
    split(x, y);
    if (va[de[y]] <= va[i]) return;
    cte(de[y]);
  }
  hp.push(e[i - n]);
  link(x, i), link(y, i);
}
int main() {
  n = rd(), m = rd();
  for (int i = 1; i <= n; ++i) sz[i] = 1;
  for (int i = 1, rs = n; i <= m; ++i) {
    e[i].x = rd(), e[i].y = rd(), e[i].z = rd(), e[i].i = i;
    bool fk = fdrt(e[i].x) != fdrt(e[i].y);
    if (fk) {
      acs(e[i].x), spl(e[i].x), fk &= sz[e[i].x] & 1;
      acs(e[i].y), spl(e[i].y), fk &= sz[e[i].y] & 1;
      if (fk) rs -= 2;
    }
    ade(i + n);
    while (1) {
      while (!hp.empty() && ban[hp.top().i]) hp.pop();
      if (hp.empty()) break;
      int x = hp.top().x, y = hp.top().y;
      split(x, y), fk = (sz[x] & 1) | ((sz[y] - sz[x]) & 1);
      if (fk) break;
      cte(hp.top().i + n);
    }
    printf("%d\n", rs > 0 ? -1 : hp.top().z);
  }
  return 0;
}
