#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 28;
const long long LINF = 1ll << 61;
inline long long getnum() {
  register long long r = 0;
  register bool ng = 0;
  register char c;
  c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') ng = 1, c = getchar();
  while (c != ' ' && c != '\n') r = r * 10 + c - '0', c = getchar();
  if (ng) r = -r;
  return r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline void putsp() { putchar(' '); }
inline void putendl() { putchar('\n'); }
inline char mygetchar() {
  register char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
struct SGT {
  struct node {
    int tl, tr;
    int l, r;
    int sum;
  } a[10000111];
  int tot;
  void build(int l, int r, int &p) {
    p = ++tot;
    a[p].l = l;
    a[p].r = r;
    a[p].sum = r - l + 1;
    if (l == r) return;
    int m = l + r >> 1;
    build(l, m, a[p].tl);
    build(m + 1, r, a[p].tr);
  }
  void newnode(int &p, int tp) {
    p = ++tot;
    a[p] = a[tp];
  }
  void change(int x, int tp, int &p) {
    newnode(p, tp);
    if (x <= a[p].l && a[p].r <= x) {
      a[p].sum--;
      return;
    }
    int m = a[p].l + a[p].r >> 1;
    if (x <= m)
      change(x, a[tp].tl, a[p].tl);
    else
      change(x, a[tp].tr, a[p].tr);
    a[p].sum = a[a[p].tl].sum + a[a[p].tr].sum;
  }
  int query1(int x, int y, int &k, int pl, int pr) {
    int l = a[pl].l, r = a[pl].r;
    if (r < x || y < l) return -1;
    int nowsum = r - l + 1 - a[pl].sum + a[pr].sum;
    if (x <= l && r <= y && nowsum < k) {
      k -= nowsum;
      return -1;
    }
    if (l == r) {
      k--;
      return l;
    }
    int tmp = query1(x, y, k, a[pl].tl, a[pr].tl);
    if (tmp == -1)
      return query1(x, y, k, a[pl].tr, a[pr].tr);
    else
      return tmp;
  }
  int query2(int x, int y, int &k, int pl, int pr) {
    int l = a[pl].l, r = a[pl].r;
    if (r < x || y < l) return -1;
    int nowsum = r - l + 1 - a[pl].sum + a[pr].sum;
    if (x <= l && r <= y && nowsum < k) {
      k -= nowsum;
      return -1;
    }
    if (l == r) {
      k--;
      return l;
    }
    int tmp = query2(x, y, k, a[pl].tr, a[pr].tr);
    if (tmp == -1)
      return query2(x, y, k, a[pl].tl, a[pr].tl);
    else
      return tmp;
  }
} sgt;
int root[100111];
int n, m;
int p[100111], lv[100111], top[100111], son[100111], sz[100111], tid[100111],
    tidrev[100111], label;
vector<int> con[100111];
void dfs(int x) {
  sz[x] = 1;
  for (int i = 0; i < con[x].size(); i++) {
    if (con[x][i] != p[x]) {
      p[con[x][i]] = x;
      lv[con[x][i]] = lv[x] + 1;
      dfs(con[x][i]);
      sz[x] += sz[con[x][i]];
    }
  }
}
void dfs2(int x) {
  tidrev[label] = x;
  tid[x] = label--;
  int mx = 0;
  for (int i = 0; i < con[x].size(); i++) {
    if (con[x][i] == p[x]) continue;
    if (sz[con[x][i]] > mx) {
      mx = sz[con[x][i]];
      son[x] = con[x][i];
    }
  }
  if (son[x] > 0) {
    top[son[x]] = top[x];
    dfs2(son[x]);
  }
  for (int i = 0; i < con[x].size(); i++) {
    if (con[x][i] == p[x] || con[x][i] == son[x]) continue;
    top[con[x][i]] = con[x][i];
    dfs2(con[x][i]);
  }
}
vector<pair<int, int> > link1, link2;
int main() {
  n = getnum();
  for (int i = 1; i <= n; i++) {
    int x;
    x = getnum();
    if (x > 0) {
      con[i].push_back(x);
      con[x].push_back(i);
    }
  }
  p[1] = -1;
  lv[1] = 1;
  dfs(1);
  top[1] = 1;
  label = n;
  dfs2(1);
  m = getnum();
  sgt.build(1, n, root[0]);
  for (int i = 1; i <= m; i++) {
    int type, s, t, ti, k;
    type = getnum();
    if (type == 1) {
      s = getnum();
      sgt.change(tid[s], root[i - 1], root[i]);
    } else {
      sgt.newnode(root[i], root[i - 1]);
      s = getnum(), t = getnum();
      k = getnum(), ti = getnum();
      link1.clear();
      link2.clear();
      int x = s, y = t;
      while (true) {
        if (top[x] == top[y]) {
          if (lv[x] > lv[y]) {
            link1.push_back(make_pair(tid[x] + (x == s), tid[y] - (y == t)));
          } else {
            link2.push_back(make_pair(tid[y] + (y == t), tid[x] - (x == s)));
          }
          break;
        } else if (lv[top[x]] > lv[top[y]]) {
          if (x == s) {
            x = p[x];
            continue;
          }
          link1.push_back(make_pair(tid[x], tid[top[x]]));
          x = p[top[x]];
        } else {
          if (y == t) {
            y = p[y];
            continue;
          }
          link2.push_back(make_pair(tid[y], tid[top[y]]));
          y = p[top[y]];
        }
      }
      int ans = -1;
      for (int j = 0; j < link1.size() && k > 0; j++) {
        ans = sgt.query1(link1[j].first, link1[j].second, k, root[ti], root[i]);
      }
      for (int j = int(link2.size()) - 1; j >= 0 && k > 0; j--) {
        ans = sgt.query2(link2[j].first, link2[j].second, k, root[ti], root[i]);
      }
      if (ans == -1)
        putnum(ans), putendl();
      else
        putnum(tidrev[ans]), putendl();
    }
  }
  return 0;
}
