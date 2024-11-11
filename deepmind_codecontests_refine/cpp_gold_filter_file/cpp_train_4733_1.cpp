#include <bits/stdc++.h>
using namespace std;
int n, cx, cy, ans, x[200005], y[200005];
struct node {
  int x, z;
  node(int _x = 0, int _z = 0) { x = _x, z = _z; }
} a[200005], b[200005];
bool operator<(node p, node q) {
  return p.x < q.x || (p.x == q.x && p.z < q.z);
}
set<node> X, Y;
set<node>::iterator be, ed, p, q, t, it;
set<int> U, V;
void solve(set<node> &ax, set<node> &ay, set<int> &au, set<int> &av) {
  int tag = 0, o;
  set<node> bx, by;
  set<int> bu, bv;
  bx.clear(), by.clear(), bu.clear(), bv.clear();
  be = ax.begin(), ed = ax.end(), ed--;
  if (ed->x - be->x + 1 == au.size()) {
    be = ay.begin(), ed = ay.end(), ed--;
    if (ed->x - be->x + 1 == av.size()) {
      ans++;
      return;
    }
    for (p = be, q = ed; p != ed; p++, q--) {
      t = p, t++;
      if (t->x > p->x + 1) {
        p++;
        tag = 1;
        break;
      }
      t = q, t--;
      if (t->x < q->x - 1) {
        q--;
        tag = 2;
        break;
      }
    }
    if (tag == 1) {
      for (t = be; t != p;) {
        it = ax.find(node(x[t->z], t->z));
        bx.insert(node(it->x, it->z));
        bu.insert(it->x), o = it->x;
        ax.erase(it);
        it = ax.lower_bound(node(o, 0));
        if (it == ax.end() || it->x != o) au.erase(o);
        by.insert(node(t->x, t->z));
        bv.insert(t->x), o = t->x;
        it = t, t++, ay.erase(it);
        it = ay.lower_bound(node(o, 0));
        if (it == ay.end() || it->x != o) av.erase(o);
      }
    }
    if (tag == 2) {
      for (t = ed; t != q;) {
        it = ax.find(node(x[t->z], t->z));
        bx.insert(node(it->x, it->z));
        bu.insert(it->x), o = it->x;
        ax.erase(it);
        it = ax.lower_bound(node(o, 0));
        if (it == ax.end() || it->x != o) au.erase(o);
        by.insert(node(t->x, t->z));
        bv.insert(t->x), o = t->x;
        it = t, t--, ay.erase(it);
        it = ay.lower_bound(node(o, 0));
        if (it == ay.end() || it->x != o) av.erase(o);
      }
    }
    solve(ax, ay, au, av);
    solve(bx, by, bu, bv);
    return;
  }
  be = ax.begin(), ed = ax.end(), ed--;
  for (p = be, q = ed; p != ed; p++, q--) {
    t = p, t++;
    if (t->x > p->x + 1) {
      p++;
      tag = 1;
      break;
    }
    t = q, t--;
    if (t->x < q->x - 1) {
      q--;
      tag = 2;
      break;
    }
  }
  if (tag == 1) {
    for (t = be; t != p;) {
      it = ay.find(node(y[t->z], t->z));
      by.insert(node(it->x, it->z));
      bv.insert(it->x), o = it->x;
      ay.erase(it);
      it = ay.lower_bound(node(o, 0));
      if (it == ay.end() || it->x != o) av.erase(o);
      bx.insert(node(t->x, t->z));
      bu.insert(t->x), o = t->x;
      it = t, t++, ax.erase(it);
      it = ax.lower_bound(node(o, 0));
      if (it == ax.end() || it->x != o) au.erase(o);
    }
  }
  if (tag == 2) {
    for (t = ed; t != q;) {
      it = ay.find(node(y[t->z], t->z));
      by.insert(node(it->x, it->z));
      bv.insert(it->x), o = it->x;
      ay.erase(it);
      it = ay.lower_bound(node(o, 0));
      if (it == ay.end() || it->x != o) av.erase(o);
      bx.insert(node(t->x, t->z));
      bu.insert(t->x), o = t->x;
      it = t, t--, ax.erase(it);
      it = ax.lower_bound(node(o, 0));
      if (it == ax.end() || it->x != o) au.erase(o);
    }
  }
  solve(ax, ay, au, av);
  solve(bx, by, bu, bv);
  return;
}
int main() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    a[i] = node(x[i], i);
    b[i] = node(y[i], i);
    X.insert(a[i]);
    Y.insert(b[i]);
    U.insert(x[i]);
    V.insert(y[i]);
  }
  solve(X, Y, U, V);
  cout << ans;
  return 0;
}
