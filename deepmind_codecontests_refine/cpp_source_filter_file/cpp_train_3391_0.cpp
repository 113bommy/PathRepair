#include <bits/stdc++.h>
using namespace std;
long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
const long long maxn = 1e5 + 10;
map<long long, long long> where;
long long n, q;
struct node {
  node *l, *r;
  long long cnt;
  long long bestEmpty, prefEmpty, sufEmpty;
  long long L, R;
  node(long long a, long long b) {
    cnt = 0;
    bestEmpty = prefEmpty = sufEmpty = b - a + 1;
    l = r = NULL;
    L = a, R = b;
  }
  inline node *getR() {
    if (r == NULL) r = new node(((L + R) >> 1) + 1, R);
    return r;
  }
  inline node *getL() {
    if (l == NULL) l = new node(L, (L + R) >> 1);
    return l;
  }
} * root;
inline long long get(long long ql, long long qr, node *p = root,
                     long long l = 0, long long r = n - 1) {
  if (l > qr || r < ql) return 0;
  if (l >= ql && r <= qr) return p->cnt;
  long long mid = (l + r) >> 1;
  long long res = 0;
  if (p->l != NULL) res += get(ql, qr, p->l, l, mid);
  if (p->r != NULL) res += get(ql, qr, p->r, mid + 1, r);
  return res;
}
inline void update(long long qx, long long val, node *p = root, long long l = 0,
                   long long r = n - 1) {
  if (l > qx || r < qx) return;
  if (l == r) {
    p->cnt = val;
    p->prefEmpty = p->sufEmpty = p->bestEmpty = 1 - p->cnt;
    return;
  }
  long long mid = (l + r) >> 1;
  update(qx, val, p->getL(), l, mid);
  update(qx, val, p->getR(), mid + 1, r);
  p->cnt = p->r->cnt + p->l->cnt;
  p->prefEmpty =
      p->l->prefEmpty + p->r->prefEmpty * bool(p->l->prefEmpty == mid - l + 1);
  p->sufEmpty =
      p->r->sufEmpty + p->l->sufEmpty * bool(p->r->sufEmpty == r - mid);
  p->bestEmpty = max(max(p->l->bestEmpty, p->r->bestEmpty),
                     p->l->sufEmpty + p->r->prefEmpty);
}
inline long long get_best(node *p = root, long long l = 0, long long r = n - 1,
                          long long need = root->bestEmpty) {
  if (l == r) return l;
  long long mid = (l + r) >> 1;
  p->getL();
  p->getR();
  if (p->r->bestEmpty == need) return get_best(p->r, mid + 1, r, need);
  if (p->r->prefEmpty + p->l->sufEmpty >= need)
    return get_best(p->l, l, mid, need - p->r->prefEmpty);
  return get_best(p->l, l, mid, need);
}
int32_t main() {
  n = in(), q = in();
  root = new node(0, n - 1);
  while (q--) {
    long long tp = in();
    if (tp == 0) {
      long long l = in() - 1, r = in() - 1;
      cout << get(l, r) << "\n";
    } else {
      long long id = tp;
      if (where[id]) {
        update(where[id] - 1, 0);
        where[id] = 0;
      } else {
        where[id] = get_best() + 1 + root->bestEmpty / 2;
        update(where[id] - 1, 1);
      }
    }
  }
}
