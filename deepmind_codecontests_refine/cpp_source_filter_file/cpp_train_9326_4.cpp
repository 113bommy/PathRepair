#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, ls[N], rs[N], v[N], deg[N], Rt, Ans;
struct LCT {
  int ch[N][2], fa[N], rev[N], stk[N], tp;
  void rever(int x) {
    if (!x) return;
    rev[x] ^= 1;
    swap(ch[x][0], ch[x][1]);
  }
  int n_rt(int x) { return ch[fa[x]][0] == x || ch[fa[x]][1] == x; }
  int get(int x) { return ch[fa[x]][1] == x; }
  void push(int x) {
    if (!rev[x]) return;
    rev[x] = 0;
    rever(ch[x][0]);
    rever(ch[x][1]);
  }
  void rotate(int x) {
    int f = fa[x], g = fa[fa[x]];
    int wx = get(x), wf = get(f), tt = n_rt(f);
    if (ch[x][wx ^ 1]) fa[ch[x][wx ^ 1]] = f;
    ch[f][wx] = ch[x][wx ^ 1];
    fa[f] = x;
    ch[x][wx ^ 1] = f;
    fa[x] = g;
    if (tt) ch[g][wf] = x;
  }
  void splay(int x) {
    stk[tp = 1] = x;
    for (int t = x; n_rt(t); t = fa[t]) stk[++tp] = fa[t];
    while (tp) push(stk[tp--]);
    while (n_rt(x)) {
      int f = fa[x], g = fa[fa[x]];
      if (n_rt(f)) rotate(get(x) == get(f) ? f : x);
      rotate(x);
    }
  }
  void access(int x) {
    for (int y = 0; x; x = fa[y = x]) splay(x), ch[x][1] = y;
  }
  void mk_rt(int x) {
    access(x);
    splay(x);
    rever(x);
  }
  int find_rt(int x) {
    access(x);
    splay(x);
    while (ch[x][0]) push(x), x = ch[x][0];
    splay(x);
    return x;
  }
  void link(int x, int y) {
    if (x == -1 || y == -1) return;
    mk_rt(x);
    if (find_rt(x) != find_rt(y)) fa[x] = y;
  }
  void cut(int x, int y) {
    if (x == -1 || y == -1) return;
    mk_rt(x);
    if (find_rt(y) == x && fa[y] == x && !ch[0][y]) fa[y] = ch[1][x] = 0;
  }
} T;
vector<int> tmp;
pair<int, int> px[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &v[i], &ls[i], &rs[i]);
  for (int i = 1; i <= n; i++) {
    if (ls[i] > 0) deg[ls[i]]++;
    if (rs[i] > 0) deg[rs[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) Rt = i;
    px[i] = make_pair(v[i], i);
  }
  sort(px + 1, px + 1 + n);
  px[n + 1].first = -1;
  for (int i = 1; i <= n; i++) T.link(i, ls[i]);
  for (int i = 1, pos; i <= n; i = pos) {
    pos = i;
    tmp.clear();
    while (px[i].first == px[pos].first) tmp.push_back(px[pos++].second);
    int flg = 0;
    for (int j = 0; j < (int)tmp.size(); j++)
      if (T.find_rt(Rt) == T.find_rt(tmp[j])) flg = 1;
    if (flg) Ans += (int)tmp.size();
    for (int j = 0; j < (int)tmp.size(); j++) T.cut(tmp[j], ls[tmp[j]]);
    for (int j = 0; j < (int)tmp.size(); j++) T.link(tmp[j], rs[tmp[j]]);
  }
  return printf("%d\n", n - Ans), 0;
}
