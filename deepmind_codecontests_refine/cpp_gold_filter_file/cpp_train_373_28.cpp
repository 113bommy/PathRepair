#include <bits/stdc++.h>
using namespace std;
mt19937 Rand(time(nullptr));
struct tnode {
  int key, siz;
  long long sum[5];
  unsigned int fix;
  tnode *lson, *rson;
  tnode(int x = 0) {
    key = sum[0] = x, siz = 1, fix = Rand();
    sum[1] = sum[2] = sum[3] = sum[4] = 0;
    lson = rson = nullptr;
  }
  int lsiz() { return lson ? lson->siz : 0; }
  int rsiz() { return rson ? rson->siz : 0; }
  void maintain() {
    siz = lsiz() + rsiz() + 1;
    for (int i = 0; i < (int)(5); ++i) sum[i] = 0;
    if (lson)
      for (int i = 0; i < (int)(5); ++i) sum[i] += lson->sum[i];
    if (rson)
      for (int i = 0; i < (int)(5); ++i)
        sum[(lsiz() + 1 + i) % 5] += rson->sum[i];
    sum[lsiz() % 5] += key;
  }
};
tnode* tre;
namespace Treap {
void init() {
  if (tre) delete tre;
  tre = nullptr;
}
void split(tnode* cur, tnode*& x, tnode*& y, int k) {
  if (!cur)
    x = nullptr, y = nullptr;
  else {
    if (k <= cur->key) {
      y = cur;
      split(y->lson, x, y->lson, k);
      y->maintain();
    } else {
      x = cur;
      split(x->rson, x->rson, y, k);
      x->maintain();
    }
  }
}
void merge(tnode*& cur, tnode* x, tnode* y) {
  if (!x || !y)
    cur = x ? x : y;
  else {
    if (x->fix < y->fix) {
      merge(x->rson, x->rson, y);
      x->maintain();
      cur = x;
    } else {
      merge(y->lson, x, y->lson);
      y->maintain();
      cur = y;
    }
  }
}
void insert(tnode*& cur, int val) {
  tnode *p, *q;
  split(tre, p, q, val);
  merge(p, p, new tnode(val));
  merge(tre, p, q);
}
void remove(tnode*& cur, int val) {
  tnode *p, *q, *s;
  split(tre, p, q, val);
  split(q, q, s, val + 1);
  merge(tre, p, s);
}
}  // namespace Treap
int N;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < (int)(N); ++i) {
    string s;
    int x;
    cin >> s;
    if (s[0] == 'a') {
      scanf("%d", &x);
      Treap::insert(tre, x);
    }
    if (s[0] == 'd') {
      scanf("%d", &x);
      Treap::remove(tre, x);
    }
    if (s[0] == 's') printf("%lld\n", tre ? tre->sum[2] : 0);
  }
  return 0;
}
