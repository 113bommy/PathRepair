#include <bits/stdc++.h>
using namespace std;
struct Tree {
  int left, right;
  int len, suff, pref, count;
  Tree *l, *r;
  Tree(int left, int right) {
    this->left = left;
    this->right = right;
    count = suff = pref = len = right - left + 1;
    l = r = 0;
  }
  void MakeChildren() {
    if (!l) {
      int c = (left + right) / 2;
      l = new Tree(left, c);
      r = new Tree(c + 1, right);
    }
  }
  Tree *Left() {
    MakeChildren();
    return l;
  }
  Tree *Right() {
    MakeChildren();
    return r;
  }
};
Tree *root;
map<int, int> mp;
bool Outside(int left, int right, Tree *root) {
  return left > root->right || right < root->left;
}
bool Inside(int left, int right, Tree *root) {
  return left <= root->left && root->right <= right;
}
int Count(int left, int right, Tree *root) {
  if (Outside(left, right, root)) return 0;
  if (Inside(left, right, root)) return root->count;
  return Count(left, right, root->Left()) + Count(left, right, root->Right());
}
int Place(Tree *root) {
  if (root->len == root->Right()->len) return Place(root->Right());
  if (root->Left()->suff + root->Right()->pref == root->len)
    return root->Left()->right - root->Left()->suff + (root->len + 1) / 2;
  return Place(root->Left());
}
void Update(int place, int to, Tree *root) {
  if (Outside(place, place, root)) return;
  if (Inside(place, place, root)) {
    root->len = root->pref = root->suff = root->count = to;
    return;
  }
  Update(place, to, root->Left());
  Update(place, to, root->Right());
  root->len =
      max(root->Left()->len,
          max(root->Right()->len, root->Left()->suff + root->Right()->pref));
  root->pref = root->Left()->pref;
  if (root->Left()->count > root->Left()->right - root->Left()->left)
    root->pref += root->Right()->pref;
  root->suff = root->Right()->suff;
  if (root->Right()->count > root->Right()->right - root->Right()->left)
    root->suff += root->Left()->suff;
  root->count = root->Left()->count + root->Right()->count;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  root = new Tree(1, n);
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t) {
      int place = mp[t];
      if (place) {
        mp.erase(t);
        Update(place, 1, root);
      } else {
        mp[t] = place = Place(root);
        Update(place, 0, root);
      }
    } else {
      int left, right;
      scanf("%d%d", &left, &right);
      printf("%d\n", right - left - Count(left, right, root) + 1);
    }
  }
  return 0;
}
