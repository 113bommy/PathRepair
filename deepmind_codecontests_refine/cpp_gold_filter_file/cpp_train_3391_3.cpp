#include <bits/stdc++.h>
const int MAXN = 2000000;
using namespace std;
struct V {
  int l, r;
  int filled;
  pair<int, int> count;
  V* lson;
  V* rson;
};
struct VV {
  int l, r;
  int filled;
  int count;
  VV* lson;
  VV* rson;
};
int n, q, a, b, c, l, r;
V* head;
VV* root;
set<pair<int, int> > ar;
V* newv(int l, int r) {
  V* temp;
  temp = new V;
  temp->l = l;
  temp->r = r;
  temp->count = make_pair(0, 0);
  temp->lson = 0;
  temp->rson = 0;
  return temp;
}
pair<int, int> set_vv(V* tree) {
  if (tree == 0) {
    return make_pair(0, 0);
  } else {
    return tree->count;
  }
}
void set_up(V* tree, int v, pair<int, int> val) {
  if ((tree->l <= v) && (v <= tree->r)) {
    int l = tree->l;
    int r = tree->r;
    if ((l == r) && (l == v)) {
      tree->count = val;
      return;
    }
    l = tree->l;
    r = tree->r;
    int ce = (l + r) / 2;
    if ((l <= v) && (v <= ce)) {
      if (tree->lson == 0) tree->lson = newv(l, ce);
      set_up(tree->lson, v, val);
    }
    if ((ce + 1 <= v) && (v <= r)) {
      if (tree->rson == 0) tree->rson = newv(ce + 1, r);
      set_up(tree->rson, v, val);
    }
    tree->count = make_pair(0, 0);
    tree->count = max(tree->count, set_vv(tree->lson));
    tree->count = max(tree->count, set_vv(tree->rson));
  }
}
pair<int, int> set_get(V* tree, int lq, int rq) {
  lq = lq * 1 - 1 + 1;
  if (tree == 0) {
    return make_pair(0, 0);
  }
  if (lq > rq) {
    return make_pair(0, 0);
  }
  int l = tree->l;
  int r = tree->r;
  if ((lq <= l) && (r <= rq)) {
    return tree->count;
  }
  if (((l <= lq) && (lq <= r)) || ((l <= rq) && (rq <= r))) {
    int ce = (l + r) / 2;
    return max(set_get(tree->lson, lq + 1 - 1, rq + 1 - 1),
               set_get(tree->rson, lq + 1 - 1, rq + 1 - 1));
  }
  return make_pair(0, 0);
}
VV* newvv(int l, int r) {
  VV* temp;
  temp = new VV;
  temp->l = l;
  temp->r = r;
  temp->count = 0;
  temp->lson = 0;
  temp->rson = 0;
  return temp;
}
int sst_vv(VV* tree) {
  if (tree == 0) {
    return 0;
  } else {
    return tree->count;
  }
}
void sst_up(VV* tree, int v, int val) {
  if ((tree->l <= v) && (v <= tree->r)) {
    int l = tree->l;
    int r = tree->r;
    if ((l == r) && (l == v)) {
      tree->count = val;
      return;
    }
    l = tree->l;
    r = tree->r;
    int ce = (l + r) / 2;
    if ((l <= v) && (v <= ce)) {
      if (tree->lson == 0) tree->lson = newvv(l, ce);
      sst_up(tree->lson, v, val);
    }
    if ((ce + 1 <= v) && (v <= r)) {
      if (tree->rson == 0) tree->rson = newvv(ce + 1, r);
      sst_up(tree->rson, v, val);
    }
    tree->count = sst_vv(tree->lson) + sst_vv(tree->rson);
  }
}
int sst_get(VV* tree, int lq, int rq) {
  if (tree == 0) {
    return 0;
  }
  if (lq > rq) {
    return 0;
  }
  int l = tree->l;
  int r = tree->r;
  if ((lq <= l) && (r <= rq)) {
    return tree->count;
  }
  if (((l <= lq) && (lq <= r)) || ((l <= rq) && (rq <= r))) {
    int ce = (l + r) / 2;
    return sst_get(tree->lson, lq + 1 - 1, rq + 1 - 1) +
           sst_get(tree->rson, lq + 1 - 1, rq + 1 - 1);
  }
  return 0;
}
set<int>::iterator ii, jj;
set<int> used;
map<int, int> g;
pair<int, int> t, tt;
int p1, p2, v1, v2;
int main() {
  cin >> n >> q;
  head = newv(0, n + 1);
  root = newvv(0, n);
  set_up(head, 1, make_pair(n, 1));
  sst_up(root, 0, 1);
  used.insert(0);
  for (q = q; q > 0; --q) {
    cin >> a;
    if (a > 0) {
      if (g.find(a) == g.end()) {
        t = set_get(head, 0, n);
        p1 = t.second;
        p2 = t.first / 2 + p1 + 1;
        v1 = p2 - p1 - 1;
        v2 = t.first - v1 - 1;
        set_up(head, t.second, make_pair(0, 0));
        set_up(head, p1, make_pair(v1, p1));
        set_up(head, p2, make_pair(v2, p2));
        g[a] = p2 - 1;
        used.insert(p2 - 1);
        sst_up(root, p2 - 1, 1);
      } else {
        t = set_get(head, g[a] + 1, g[a] + 1);
        set_up(head, g[a] + 1, make_pair(0, 0));
        used.erase(used.find(g[a]));
        sst_up(root, t.second - 1, 0);
        ii = used.lower_bound(g[a]);
        ii--;
        tt = set_get(head, *ii + 1, *ii + 1);
        set_up(head, *ii + 1, make_pair(tt.first + t.first + 1, *ii + 1));
        g.erase(a);
      }
    } else {
      cin >> a >> b;
      cout << sst_get(root, a, b) << "\n";
    }
  }
}
