#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int arr = 2e5 + 10;
const int ar = 2e3 + 10;
const long double pi = acos(-1);
const long double eps = 1e-10;
const long long md = 1e9 + 7;
struct item {
  int val, min_, prior, size;
  item *left, *right;
  item() {}
  item(int val_ = 0) {
    val = val_;
    min_ = val_;
    prior = rand();
    left = 0;
    right = 0;
    size = 1;
  }
};
typedef item* pitem;
int get_size(pitem t) {
  if (!t) return 0;
  return t->size;
}
int get_min_(pitem t) {
  if (!t) return 2e9;
  return t->min_;
}
void recalc(pitem t) {
  if (!t) return;
  t->size = get_size(t->left) + get_size(t->right) + 1;
  t->min_ = min({get_min_(t->left), get_min_(t->right), t->val});
}
void split_size(pitem t, pitem& l, pitem& r, int key) {
  if (!t) {
    return void(l = r = 0);
  }
  int size_l = get_size(t->left) + 1;
  if (size_l <= key) {
    split_size(t->right, t->right, r, key - size_l), l = t;
  } else {
    split_size(t->left, l, t->left, key), r = t;
  }
  recalc(l);
  recalc(r);
}
void merge(pitem& t, pitem l, pitem r) {
  if (!l || !r) {
    return void(t = l ? l : r);
  }
  if (l->prior > r->prior) {
    merge(l->right, l->right, r), t = l;
  } else {
    merge(r->left, l, r->left), t = r;
  }
  recalc(t);
}
pitem Tree = 0;
inline int get_min(int pref) {
  pitem t1, t2;
  split_size(Tree, t1, t2, pref);
  int to_return = get_min_(t1);
  merge(Tree, t1, t2);
  return to_return;
}
int main() {
  "" != "" ? freopen(
                 ""
                 ".in",
                 "r", stdin),
      freopen(
          ""
          ".out",
          "w", stdout)
           : 0;
  "" != "" ? freopen(
                 ""
                 ".dat",
                 "r", stdin),
      freopen(
          ""
          ".sol",
          "w", stdout)
           : 0;
  srand(228 * 228);
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < (int)(a.size()); i++) {
    scanf("%d", &a[i]);
    merge(Tree, Tree, new item(a[i]));
  }
  sort(a.begin(), a.end());
  long long ans = n;
  for (auto i : a) {
    int l = 1, r = get_size(Tree);
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (get_min(mid) == i) {
        r = mid;
      } else {
        l = mid;
      }
    }
    int res = r;
    if (get_min(l) == i) {
      res = l;
    }
    ans += res - 1;
    pitem t1, t2, t3;
    split_size(Tree, t1, t2, res - 1);
    split_size(t2, t2, t3, 1);
    merge(Tree, t3, t1);
  }
  cout << ans << "\n";
}
