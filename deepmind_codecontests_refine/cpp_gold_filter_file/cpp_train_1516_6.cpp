#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200002;
struct node {
  int b, id, p;
  int qs, lazy;
  node *l, *r;
};
typedef node *pnode;
pnode treap = NULL;
pnode newNode(int b, int id) {
  pnode x = new node();
  x->b = b;
  x->id = id;
  x->p = rand();
  return x;
}
int sol[MAXN];
void propagate(pnode &tree) {
  if (!tree) return;
  if (!tree->qs) return;
  sol[tree->id] += tree->qs;
  tree->b -= tree->lazy;
  if (tree->l) {
    tree->l->lazy += tree->lazy;
    tree->l->qs += tree->qs;
  }
  if (tree->r) {
    tree->r->lazy += tree->lazy;
    tree->r->qs += tree->qs;
  }
  tree->lazy = tree->qs = 0;
}
void merge(pnode &tree, pnode l, pnode r) {
  if (!l || !r) {
    tree = l ? l : r;
    return;
  }
  propagate(l);
  propagate(r);
  if (l->p < r->p) {
    merge(l->r, l->r, r);
    tree = l;
  } else {
    merge(r->l, l, r->l);
    tree = r;
  }
}
void split(pnode tree, pnode &l, pnode &r, int v) {
  if (!tree) {
    l = r = NULL;
    return;
  }
  propagate(tree);
  if (tree->b <= v) {
    split(tree->r, tree->r, r, v);
    l = tree;
  } else {
    split(tree->l, l, tree->l, v);
    r = tree;
  }
}
void push_back(pair<int, int> y) {
  pnode x = newNode(y.first, y.second);
  merge(treap, treap, x);
}
void add(pnode &tree) {
  if (!tree) return;
  propagate(tree);
  add(tree->l);
  add(tree->r);
  pnode r;
  split(treap, treap, r, tree->b);
  push_back({tree->b, tree->id});
  merge(treap, treap, r);
  tree = NULL;
}
void reduce(int b) {
  pnode r;
  split(treap, treap, r, b - 1);
  if (r) {
    r->lazy += b;
    r->qs++;
  }
  pnode x, y;
  split(r, x, y, b - 1);
  add(x);
  merge(treap, treap, y);
}
void inorder(pnode &tree) {
  if (!tree) return;
  propagate(tree);
  inorder(tree->l);
  inorder(tree->r);
}
int n;
pair<int, int> arr[MAXN];
pair<int, int> B[MAXN];
bool f(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
  sort(arr + 1, arr + n + 1, f);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> B[i].first;
    B[i].second = i;
  }
  sort(B + 1, B + m + 1);
  for (int i = 1; i <= m; i++) push_back(B[i]);
  for (int i = 1; i <= n; i++) reduce(arr[i].first);
  inorder(treap);
  for (int i = 1; i <= m; i++) cout << sol[i] << " ";
  cout << "\n";
  return 0;
}
