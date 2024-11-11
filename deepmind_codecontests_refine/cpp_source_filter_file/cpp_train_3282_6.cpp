#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000 + 9;
int n;
int inp[MAXN][3];
map<int, int> elem;
struct treap {
  int key, prior;
  int type;
  int count;
  treap *l, *r;
};
typedef treap* titem;
titem num[MAXN];
treap node[MAXN];
int count(titem t) { return t ? t->count : 0; }
void upd_cnt(titem t) {
  if (t) {
    t->count = t->type + count(t->l) + count(t->r);
  }
}
void split(titem t, int key, titem& l, titem& r) {
  if (!t)
    l = r = NULL;
  else if (key < t->key) {
    split(t->l, key, l, t->l);
    r = t;
  } else {
    split(t->r, key, t->r, r);
    l = t;
  }
  upd_cnt(t);
  upd_cnt(l);
  upd_cnt(r);
}
void merge(titem& t, titem l, titem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior) {
    merge(l->r, l->r, r);
    t = l;
  } else {
    merge(r->l, l, r->l);
    t = r;
  }
  upd_cnt(t);
  upd_cnt(l);
  upd_cnt(r);
}
void insert(titem& t, titem it) {
  if (!t)
    t = it;
  else if (it->prior > t->prior) {
    split(t, it->key, it->l, it->r);
    t = it;
  } else {
    insert(it->key < t->key ? t->l : t->r, it);
  }
  upd_cnt(t);
  upd_cnt(it);
}
int sum(titem t, int key) {
  if (!t) return 0;
  if (t->key <= key) {
    return count(t->l) + t->type + sum(t->r, key);
  } else {
    return sum(t->l, key);
  }
}
int main() {
  srand(time(NULL));
  scanf("%d", &n);
  int id = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &inp[i][0], &inp[i][1], &inp[i][2]);
    if (elem.find(inp[i][2]) != elem.end()) elem[inp[i][2]] = ++id;
  }
  for (int i = 0; i <= n; i++) {
    num[i] = NULL;
  }
  int val, key;
  for (int i = 0; i < n; i++) {
    if (inp[i][0] == 3) {
      val = elem[inp[i][2]];
      key = inp[i][1];
      printf("%d\n", sum(num[val], key));
    } else {
      node[i].type = (inp[i][0] == 1) ? 1 : -1;
      node[i].key = inp[i][1];
      val = elem[inp[i][2]];
      node[i].prior = rand();
      node[i].l = node[i].r = NULL;
      node[i].count = node[i].type;
      insert(num[val], &node[i]);
    }
  }
  return 0;
}
