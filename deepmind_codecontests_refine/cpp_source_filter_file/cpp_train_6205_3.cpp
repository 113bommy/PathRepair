#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 300007;
const int MAX = 100007;
class lctT {
 public:
  lctT() {
    for (int i = 0; i < MAXN; ++i) data[i] = nd[i] = make_pair(INF, i);
  }
  int link(int u, int v, int e, int x) {
    if (!iscon(u, v))
      return _link(u, v, e, x), -1;
    else {
      bool flag = false;
      int mini = INF;
      if (!(getsize(u, v) >> 1 & 1)) flag = true;
      pair<int, int> ret = query(u, v);
      mini = ret.first;
      if (x > mini) {
        cut(ret.second);
        _link(u, v, e, x);
      } else
        mini = x;
      return flag ? mini : -1;
    }
  }
  void _link(int u, int v, int e, int x) {
    link(u, e);
    link(v, e);
    eu[e] = u, ev[e] = v;
    upd(e, x);
  }
  void link(int u, int v) {
    croot(u);
    access(v);
    fa[u] = v;
    access(u);
  }
  void cut(int e) {
    if (eu[e]) {
      cut(e, eu[e]);
      cut(e, ev[e]);
      eu[e] = ev[e] = 0;
    }
  }
  void cut(int u, int v) {
    croot(u);
    access(v);
    fa[u] = ch[v][0] = 0;
    upd(v);
  }
  void upd(int now, int x) {
    croot(now);
    nd[now] = make_pair(x, now);
    upd(now);
  }
  int getsize(int u, int v) {
    croot(u);
    access(v);
    return size[v];
  }
  pair<int, int> query(int u, int v) {
    croot(u);
    access(v);
    return data[v];
  }

 private:
  void rot(int now) {
    int nf = fa[now], np = fa[nf], d = ch[nf][1] == now;
    fa[now] = np;
    if (!isroot(nf)) ch[np][ch[np][1] == nf] = now;
    fa[ch[now][d ^ 1]] = nf, ch[nf][d] = ch[now][d ^ 1];
    fa[nf] = now, ch[now][d ^ 1] = nf;
    upd(nf), upd(now);
  }
  void splay(int now) {
    rev_push(now);
    int nf, np;
    while (!isroot(now)) {
      nf = fa[now], np = fa[nf];
      if (!isroot(nf))
        rot(((ch[nf][0] == now) == (ch[np][0] == nf)) ? nf : now);
      rot(now);
    }
  }
  void access(int now) {
    int v = 0, tn = now;
    while (now) {
      splay(now);
      ch[now][1] = v;
      upd(now);
      v = now, now = fa[now];
    }
    splay(tn);
  }
  void croot(int now) {
    access(now);
    tag[now] ^= 1;
  }
  int getroot(int now) {
    while (ch[now][0]) now = ch[now][0];
    splay(now);
    return now;
  }
  bool iscon(int u, int v) {
    croot(u);
    access(v);
    return getroot(v) == u;
  }
  bool isroot(int now) {
    return (!(fa[now] && ((ch[fa[now]][0] == now) || (ch[fa[now]][1] == now))));
  }
  void push_down(int now) {
    if (tag[now]) {
      tag[ch[now][0]] ^= 1, tag[ch[now][1]] ^= 1;
      swap(ch[now][0], ch[now][1]);
      tag[now] = 0;
    }
  }
  void rev_push(int now) {
    if (!isroot(now)) rev_push(fa[now]);
    push_down(now);
  }
  void upd(int now) {
    size[now] = size[ch[now][0]] + size[ch[now][1]];
    data[now] =
        min((((data[ch[now][0]]) < (data[ch[now][1]])) ? (data[ch[now][0]])
                                                       : (data[ch[now][1]])),
            nd[now]);
  }
  int ch[MAXN][2], fa[MAXN], size[MAXN], eu[MAXN], ev[MAXN];
  bool tag[MAXN];
  pair<int, int> data[MAXN], nd[MAXN];
} lct;
int n, q;
int tp[MAXN], eu[MAXN], ev[MAXN], en[MAXN];
void init();
void input();
void work();
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= q; ++i) scanf("%d%d", &eu[i], &ev[i]);
}
void work() {
  map<pair<int, int>, int> es;
  map<pair<int, int>, int>::iterator it;
  for (int i = 1; i <= q; ++i) {
    if ((it = es.find(make_pair(eu[i], ev[i]))) == es.end())
      es.insert(make_pair(make_pair(eu[i], ev[i]), i)), en[i] = INF, tp[i] = 1;
    else {
      en[it->second] = i;
      en[i] = it->second;
      es.erase(it);
      tp[i] = 0;
    }
  }
  int nt = -1;
  for (int i = 1; i <= q; ++i) {
    if (tp[i])
      nt = max(nt, lct.link(eu[i], ev[i], i + MAX + 3, en[i]));
    else
      lct.cut(en[i] + MAX + 3);
    printf((nt <= i) ? "YES\n" : "NO\n");
  }
}
