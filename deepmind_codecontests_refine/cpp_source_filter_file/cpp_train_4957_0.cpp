#include <bits/stdc++.h>
using namespace std;
struct item {
  int key, prior, cnt, val;
  item *l, *r;
  item() {}
  item(int key, int prior) : key(key), prior(prior), l(NULL), r(NULL), val(1) {}
};
typedef item *pitem;
int cnt(pitem t) { return t ? t->cnt : 0; }
void upd_cnt(pitem t) {
  if (t) t->cnt = t->val + cnt(t->l) + cnt(t->r);
}
void split(pitem t, int key, pitem &l, pitem &r) {
  if (!t)
    l = r = NULL;
  else if (key < t->key)
    split(t->l, key, l, t->l), r = t;
  else
    split(t->r, key, t->r, r), l = t;
  upd_cnt(t);
}
void insert(pitem &t, pitem it) {
  if (!t)
    t = it;
  else if (t->key == it->key)
    t->val += it->val;
  else if (it->prior > t->prior)
    split(t, it->key, it->l, it->r), t = it;
  else
    insert(it->key < t->key ? t->l : t->r, it);
  upd_cnt(t);
}
const int nm = 200010;
int n, t, a[nm];
pitem root;
int cnt_lte(pitem &t, int x) {
  if (!t) {
    return 0;
  }
  if (t->key == x) {
    return cnt(t->l) + t->val;
  }
  if (t->key < x) {
    return cnt(t->l) + t->val + cnt_lte(t->r, x);
  }
  return cnt_lte(t->l, x);
}
int main() {
  srand(2512);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int res = 0;
  for (int i = 1; i <= n && i <= t; ++i) {
    insert(root, new item(a[i] - i, rand()));
    res = max(res, cnt_lte(root, t - i - 1));
  }
  cout << res << "\n";
}
