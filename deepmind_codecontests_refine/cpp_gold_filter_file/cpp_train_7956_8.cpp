#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
  int ls, rs, val, rnd, siz, f;
} tre[1000005];
int cnt;
int xx[1000005], yy[1000005], root;
int newnode(int w) {
  cnt++;
  tre[cnt].siz = 1;
  tre[cnt].val = w;
  tre[cnt].rnd = rand();
  tre[cnt].ls = tre[cnt].rs = 0;
  return cnt;
}
void renew(int x) {
  tre[tre[x].ls].f = tre[tre[x].rs].f = x;
  tre[x].siz = tre[tre[x].ls].siz + tre[tre[x].rs].siz + 1;
}
int merge(int x, int y) {
  if (x == 0 || y == 0) return x + y;
  int res = 0;
  if (tre[x].rnd < tre[y].rnd) {
    res = x;
    tre[x].rs = merge(tre[x].rs, y);
  } else {
    res = y;
    tre[y].ls = merge(x, tre[y].ls);
  }
  renew(res);
  return res;
}
void splitrk(int rt, int &rrt, int &lrt, int k) {
  if (rt == 0) {
    rrt = lrt = 0;
    return;
  }
  int qwq = tre[tre[rt].ls].siz + 1;
  if (qwq <= k) {
    rrt = rt;
    splitrk(tre[rt].rs, tre[rt].rs, lrt, k - qwq);
  } else {
    lrt = rt;
    splitrk(tre[rt].ls, rrt, tre[rt].ls, k);
  }
  renew(rt);
}
void ins(int w) { root = merge(root, newnode(w)); }
bool vis[1000005];
int nw = 1;
void out(int x) {
  if (x == 0) return;
  out(tre[x].ls);
  if (tre[x].val != 0) {
    printf("%d ", tre[x].val);
  } else {
    while (vis[nw]) {
      nw++;
    }
    tre[x].val = nw;
    vis[nw] = true;
    printf("%d ", tre[x].val);
  }
  out(tre[x].rs);
}
int main() {
  srand(time(0));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &xx[i], &yy[i]);
  }
  for (int i = 1; i <= n; i++) {
    ins(0);
  }
  for (int i = m; i >= 1; i--) {
    int x, mid, y;
    splitrk(root, x, mid, 1);
    splitrk(mid, mid, y, yy[i] - 1);
    if (tre[x].val != 0 && tre[x].val != xx[i]) {
      printf("-1");
      return 0;
    }
    if (vis[xx[i]] && tre[x].val != xx[i]) {
      printf("-1");
      return 0;
    }
    tre[x].val = xx[i];
    vis[xx[i]] = true;
    root = merge(merge(mid, x), y);
  }
  out(root);
  return 0;
}
