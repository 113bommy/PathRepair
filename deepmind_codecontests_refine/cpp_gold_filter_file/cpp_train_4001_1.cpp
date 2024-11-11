#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
A cvt(B x) {
  stringstream s;
  s << x;
  A r;
  s >> r;
  return r;
}
typedef vector<int> VI;
typedef vector<pair<int, int> > VII;
typedef vector<string> VS;
struct Treap {
  int val, priority;
  int maxVal, size;
  Treap *left;
  Treap *right;
  Treap() {
    val = priority = maxVal = size = 0;
    left = right = 0;
  }
  Treap(int _val, int _priority, int _maxVal, int _size) {
    val = _val;
    maxVal = _maxVal;
    size = _size;
    priority = _priority;
    left = right = 0;
  }
};
int SZ(Treap *&t) { return t ? t->size : 0; }
int MAX(Treap *&t) { return t ? t->maxVal : 0; }
void Adjust(Treap *&T) {
  T->size = 1 + SZ(T->left) + SZ(T->right);
  T->maxVal = max(T->val, max(MAX(T->left), MAX(T->right)));
}
void rotateLeft(Treap *&T) {
  Treap *t = T->left;
  T->left = t->right;
  Adjust(T);
  t->right = T;
  Adjust(t);
  T = t;
}
void rotateRight(Treap *&T) {
  Treap *t = T->right;
  T->right = t->left;
  Adjust(T);
  t->left = T;
  Adjust(t);
  T = t;
}
void Balance(Treap *&T) {
  if (T->left) {
    if (T->left->priority > T->priority) rotateLeft(T);
  }
  if (T->right) {
    if (T->right->priority > T->priority) rotateRight(T);
  }
}
void insert(Treap *&T, int val, int where, int pri) {
  if (!T)
    T = new Treap(val, pri, val, 1);
  else {
    if (SZ(T->right) >= where) {
      insert(T->right, val, where, pri);
    } else if (max(T->val, MAX(T->right)) > val) {
      insert(T->right, val, where, pri);
    } else
      insert(T->left, val, where - SZ(T->right) - 1, pri);
    Adjust(T);
    Balance(T);
  }
}
int idx[101010];
void print(Treap *&T) {
  if (T) {
    print(T->left);
    printf("%d ", idx[T->val]);
    print(T->right);
  }
}
int main() {
  int n, a, c;
  scanf("%d", &n);
  Treap *T = NULL;
  for (int i = (int)0; i < (int)n; ++i) {
    scanf("%d%d", &a, &c);
    idx[a] = i + 1;
    insert(T, a, c, rand() % 101010);
  }
  print(T);
  puts("");
  return 0;
}
