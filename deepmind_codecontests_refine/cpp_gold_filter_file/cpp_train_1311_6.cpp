#include <bits/stdc++.h>
using namespace std;
namespace thecold {
inline int read() {
  int res = 0;
  bool flag = false;
  char c = getchar();
  while (!isdigit(c)) flag = (c == '-'), c = getchar();
  while (isdigit(c)) res = res * 10 + (c ^ 48), c = getchar();
  return !flag ? res : -res;
}
const int Max_n = 5e6 + 5;
const int de = 6e5;
const int INF = 2e9;
int son[Max_n][2], val[Max_n], fa[Max_n], n, siz[Max_n];
int l[Max_n], r[Max_n], root, tag[Max_n], tot, cnt[Max_n];
inline void MIN(int& x, const int y) {
  if (x > y) x = y;
}
inline void push_up(const int now) {
  if (now == 0) puts("qwq");
  siz[now] = siz[son[now][0]] + siz[son[now][1]] + cnt[now];
}
inline void push_down(const int now) {
  if (!tag[now]) return;
  if (son[now][0]) val[son[now][0]] += tag[now], tag[son[now][0]] += tag[now];
  if (son[now][1]) val[son[now][1]] += tag[now], tag[son[now][1]] += tag[now];
  tag[now] = 0;
}
inline void rotate(const int x) {
  int fx = fa[x], ffx = fa[fx];
  if (ffx) son[ffx][son[ffx][1] == fx] = x;
  bool type = son[fx][1] == x;
  fa[fx] = x, fa[x] = ffx, fa[son[x][!type]] = fx;
  son[fx][type] = son[x][!type], son[x][!type] = fx;
  push_up(fx), push_up(x);
  if (!fx || !x) printf("%d %d\n", x, fx);
}
int st[Max_n], tp;
inline void push_dn() {
  while (tp) push_down(st[tp]), --tp;
}
inline void splay(const int x, const int goal) {
  if (x == 0 && l[1] == 726056455) {
    puts("splay");
    exit(0);
  }
  int now = x;
  while (now != goal) {
    st[++tp] = now, now = fa[now];
    if (tp > 1e6) {
      puts("73");
      printf("%d %d %d %d\n", x, now, fa[now], goal);
      exit(0);
    }
  }
  st[++tp] = goal;
  push_dn();
  int cnt = 0;
  while (fa[x] != goal) {
    ++cnt;
    int fx = fa[x], ffx = fa[fx];
    if (ffx != goal) rotate((son[fx][1] == x) ^ (son[ffx][1] == fx) ? x : fx);
    rotate(x);
  }
  if (goal == 0) root = x;
}
int insert(int& now, const int va, const int from, const int dep) {
  if (!now) now = ++tot, fa[now] = from, val[now] = va;
  if (val[now] == va) return ++cnt[now], push_up(now), now;
  push_down(now);
  int ret;
  if (val[now] > va)
    ret = insert(son[now][0], va, now, dep + 1);
  else
    ret = insert(son[now][1], va, now, dep + 1);
  return push_up(now), ret;
}
inline int get_down(const int x) {
  splay(x, 0);
  int ret = x;
  int cnt = 0;
  while (son[ret][1]) push_down(ret), ret = son[ret][1];
  return ret;
}
void del(const int now) {
  if (now == de && l[1] == 726056455) {
    puts("del");
    exit(0);
  }
  splay(now, 0);
  push_down(root);
  fa[son[root][0]] = fa[son[root][1]] = 0;
  int ls = son[root][0], rs = son[root][1];
  cnt[root] = 0, son[root][0] = son[root][1] = 0;
  int pos = get_down(ls);
  splay(pos, 0);
  son[root][1] = rs;
  fa[rs] = root;
  push_up(root);
}
inline int get_nex(const int va) {
  int ret = 0, now = root, cnt = 0;
  while (now) {
    push_down(now);
    if (val[now] >= va) {
      if (!ret || val[ret] > val[now]) ret = now;
      now = son[now][0];
    } else
      now = son[now][1];
  }
  return ret;
}
inline int get_pre(const int va) {
  int ret = 0, now = root, cnt = 0;
  while (now) {
    push_down(now);
    if (val[now] <= va) {
      if (!ret || val[ret] < val[now]) ret = now;
      now = son[now][1];
    } else
      now = son[now][0];
  }
  return ret;
}
int all;
inline void add(const int l, const int r) {
  int lp = get_nex(l), rp = get_pre(r - 1);
  if (rp == 0) {
    puts("177");
    printf("%d %d\n", l, r);
    exit(0);
  }
  if (lp == 0) {
    puts("182");
    printf("%d\n", all);
    printf("%d %d\n", l, r);
    exit(0);
  }
  if (lp == rp) return ++val[lp], void();
  if (val[rp] < val[lp]) return;
  splay(lp, 0), splay(rp, lp);
  ++val[lp], ++val[rp];
  if (son[rp][0]) ++val[son[rp][0]], ++tag[son[rp][0]];
}
inline void main() {
  n = read();
  for (int i = 1; i <= n; ++i) l[i] = read(), r[i] = read();
  splay(insert(root, 0, 0, 1), 0);
  for (int i = 1; i <= n + 5; ++i) splay(insert(root, 1e9 + i, 0, 1), 0);
  for (int i = 1; i <= n; ++i) {
    ++all;
    int pos = get_nex(r[i]);
    del(pos);
    add(l[i], r[i]);
    pos = insert(root, l[i], 0, 1);
    splay(pos, 0);
    if (tot > 1e6) {
      puts("203"), exit(0);
    }
  }
  int now = get_pre(1e9);
  splay(now, 0);
  printf("%d\n", siz[son[root][0]]);
}
}  // namespace thecold
int main() {
  thecold::main();
  return 0;
}
