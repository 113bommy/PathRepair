#include <bits/stdc++.h>
using namespace std;
struct node {
  int a;
  node *l, *r;
  node(int _a = 0, node* _l = nullptr, node* _r = nullptr) {
    a = _a;
    l = _l;
    r = _r;
  }
};
typedef node* pnode;
map<int, pnode> m;
void update(pnode& v, int pos, int val, int tl, int tr) {
  if (!v) {
    v = new node();
  }
  if (tr == tl) {
    v->a += val;
    return;
  } else {
    int mid = tl + tr >> 1;
    if (mid < pos) {
      update(v->r, pos, val, mid + 1, tr);
    } else {
      update(v->l, pos, val, tl, mid);
    }
    v->a = 0;
    if (v->l) v->a += v->l->a;
    if (v->r) v->a += v->r->a;
  }
}
int get(pnode v, int l, int r, int tl, int tr) {
  if (!v) return 0;
  if (l == tl and r == tr) {
    return v->a;
  } else {
    int mid = tl + tr >> 1;
    if (mid < l) {
      return get(v->r, l, r, mid + 1, tr);
    } else if (mid <= r) {
      return get(v->l, l, r, tl, mid);
    } else {
      int ans = 0;
      ans += get(v->l, l, mid, tl, mid) + get(v->r, mid + 1, r, mid + 1, tr);
      return ans;
    }
  }
}
void print(pnode v) {
  if (!v) {
    cout << 0 << ' ';
    return;
  }
  print(v->l);
  cout << v->a << ' ';
  print(v->r);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, t, x;
    cin >> a >> t >> x;
    if (a == 1)
      update(m[x], t, 1, 0, 1e9 + 1);
    else if (a == 2)
      update(m[x], t, -1, 0, 1e9 + 1);
    else {
      cout << get(m[x], 0, t, 0, 1e9 + 1) << endl;
    }
  }
  return 0;
}
