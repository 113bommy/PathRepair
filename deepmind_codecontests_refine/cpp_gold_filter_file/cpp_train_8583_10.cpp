#include <bits/stdc++.h>
using namespace std;
typedef struct Treap *ptreap;
const long long inf = 1ll << 60;
const long long N = 1e5 + 1;
long long n, d;
pair<long long, long long> ans[N];
pair<long long, long long> opt;
struct Treap {
  long long key;
  long long pri;
  pair<long long, long long> mxm;
  pair<long long, long long> val;
  ptreap l = NULL;
  ptreap r = NULL;
  Treap(long long key, long long pri, pair<long long, long long> val)
      : key(key), pri(pri), val(val) {}
} *root = NULL;
pair<long long, long long> val(ptreap &t) {
  return t ? t->val : pair<long long, long long>(0, 0);
}
pair<long long, long long> mxm(ptreap &t) {
  return t ? t->mxm : pair<long long, long long>(0, 0);
}
void upd(ptreap &t) {
  if (!t) {
    return;
  }
  t->mxm = max(max(mxm(t->l), mxm(t->r)), t->val);
}
void split(ptreap t, ptreap &l, ptreap &r, long long key) {
  if (!t) {
    l = r = NULL;
  } else if (key <= t->key) {
    split(t->l, l, t->l, key), r = t;
  } else {
    split(t->r, t->r, r, key), l = t;
  }
  upd(t);
}
void merge(ptreap &t, ptreap l, ptreap r) {
  if (!l || !r) {
    t = l ? l : r;
  } else if (l->pri > r->pri) {
    merge(l->r, l->r, r), t = l;
  } else {
    merge(r->l, l, r->l), t = r;
  }
  upd(t);
}
void insert(ptreap &t, ptreap it) {
  if (!t) {
    t = it;
  } else if (it->pri > t->pri) {
    split(t, it->l, it->r, it->key), t = it;
  } else {
    insert(it->key <= t->key ? t->l : t->r, it);
  }
  upd(t);
}
pair<long long, long long> max_query(long long l, long long r) {
  if (l > r) {
    return {0, 0};
  }
  ptreap t1;
  ptreap t2;
  ptreap t3;
  split(root, t1, t2, l);
  split(t2, t2, t3, r + 1);
  pair<long long, long long> res = mxm(t2);
  merge(t1, t1, t2);
  merge(root, t1, t3);
  return res;
}
void prll_path(long long i) {
  if (i == 0) {
    return;
  }
  prll_path(ans[i].second);
  cout << i << " ";
}
void input() { cin >> n >> d; }
void solve() {
  for (long long i = 1; i <= n; ++i) {
    long long key;
    cin >> key;
    long long pri = rand();
    long long ind = i;
    pair<long long, long long> mxm =
        max(max_query(1, key - d), max_query(key + d, inf));
    ans[i] = mxm;
    mxm.first++;
    mxm.second = i;
    opt = max(opt, mxm);
    ptreap it = new Treap(key, pri, mxm);
    insert(root, it);
  }
  cout << opt.first << "\n";
  prll_path(opt.second);
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  input();
  solve();
}
