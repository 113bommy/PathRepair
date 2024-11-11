#include <bits/stdc++.h>
using namespace std;
struct Node {
  int flip;
  int setnum;
  Node *l, *r;
  Node() : flip(0), setnum(0), l(0), r(0) {}
}* root = new Node();
void push_down(Node* root) {
  if (!root->l) root->l = new Node();
  if (!root->r) root->r = new Node();
  if (root->setnum) {
    root->l->setnum = root->setnum;
    root->r->setnum = root->setnum;
    root->l->flip = 0;
    root->r->flip = 0;
    root->setnum = 0;
  }
  if (root->flip) {
    root->l->flip ^= 1;
    root->r->flip ^= 1;
    root->flip = 0;
  }
}
void setnum(Node* root, int l, int r, int L, int R, int flag) {
  if (r < L || l > R) return;
  if (L <= l && r <= R) {
    root->setnum = flag;
    root->flip = 0;
    return;
  }
  int m = (l + r - 1) / 2;
  push_down(root);
  setnum(root->l, l, m, L, R, flag);
  setnum(root->r, m + 1, r, L, R, flag);
}
void flip(Node* root, int l, int r, int L, int R) {
  if (r < L || l > R) return;
  if (L <= l && r <= R) {
    root->flip ^= 1;
    return;
  }
  int m = (l + r - 1) / 2;
  push_down(root);
  flip(root->l, l, m, L, R);
  flip(root->r, m + 1, r, L, R);
}
int getval(Node* root, int l, int r, int first) {
  if (l == r) {
    return (root->setnum == -1) ^ root->flip;
  }
  int m = (l + r - 1) / 2;
  push_down(root);
  if (first <= m)
    return getval(root->l, l, m, first);
  else
    return getval(root->r, m + 1, r, first);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int first;
    scanf("%d", &first);
    arr.push_back(first);
  }
  setnum(root, -100005, 100005, -100005, 100005, 1);
  for (int i = 0; i < m; i++) {
    string type;
    int val;
    cin >> type >> val;
    if (type == ">") {
      if (val >= 0) {
        setnum(root, -100005, 100005, -100005, -val - 1, 1);
        setnum(root, -100005, 100005, val + 1, 100005, -1);
      } else {
        setnum(root, -100005, 100005, -100005, val, 1);
        setnum(root, -100005, 100005, -val, 100005, -1);
        flip(root, -100005, 100005, val + 1, -val - 1);
      }
    } else {
      if (val >= 0) {
        setnum(root, -100005, 100005, -100005, -val, -1);
        setnum(root, -100005, 100005, val, 100005, 1);
        flip(root, -100005, 100005, -val + 1, val - 1);
      } else {
        setnum(root, -100005, 100005, -100005, val - 1, -1);
        setnum(root, -100005, 100005, -val + 1, 100005, 1);
      }
    }
  }
  for (int first : arr) {
    if (getval(root, -100005, 100005, first)) first *= -1;
    printf("%d ", first);
  }
}
