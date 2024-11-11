#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int A[N];
struct Splay {
  int rt;
  int fa[N], ch[N][2], sz[N];
  long long val[N], addv[N];
  void pushup(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; }
  void update(int x, long long w) {
    if (x) val[x] += w, addv[x] += w;
  }
  void pushdown(int x) {
    if (addv[x]) {
      long long &w = addv[x];
      if (ch[x][0]) update(ch[x][0], w);
      if (ch[x][1]) update(ch[x][1], w);
      w = 0;
    }
  }
  void rotate(int x) {
    int f = fa[x], g = fa[f], c = ch[f][1] == x;
    if (g)
      ch[g][ch[g][1] == f] = x;
    else
      rt = x;
    fa[x] = g;
    fa[ch[x][c ^ 1]] = f, ch[f][c] = ch[x][c ^ 1];
    ch[x][c ^ 1] = f, fa[f] = x;
    pushup(f);
  }
  void push(int x) {
    if (fa[x]) push(fa[x]);
    pushdown(x);
  }
  void splay(int x, int aim = 0) {
    push(x);
    while (fa[x] != aim) {
      int f = fa[x];
      if (fa[f] != aim && ((ch[fa[f]][1] == f) == (ch[f][1] == x))) rotate(f);
      rotate(x);
    }
    pushup(x);
  }
  int node;
  int find(int &x, int f, int cur, int key) {
    if (!x) {
      x = ++node;
      val[x] = 1ll * key * (cur + 1);
      sz[x] = 1, fa[x] = f;
      if (f) ++sz[f];
      splay(x);
      return x;
    }
    int j = cur + sz[ch[x][0]] + 1;
    pushdown(x);
    if (val[x] >= 1ll * j * key)
      return find(ch[x][1], x, j, key);
    else
      return find(ch[x][0], x, cur, key);
  }
  long long getsum(int x) {
    long long ret = max(0ll, val[x]);
    pushdown(x);
    if (ch[x][0]) ret += getsum(ch[x][0]);
    if (ch[x][1]) ret += getsum(ch[x][1]);
    return ret;
  }
} T;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (int i = 1; i <= n; i++) {
    T.find(T.rt, 0, 0, A[i]);
    T.update(T.ch[T.rt][1], A[i]);
  }
  cout << T.getsum(T.rt) << endl;
  return 0;
}
