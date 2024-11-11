#include <bits/stdc++.h>
using namespace std;
const int inf = 16;
const int N = (int)1e5 + 10;
struct Node {
  Node *left, *right;
  int sum;
  Node() : left(NULL), right(NULL), sum(0){};
  Node(int sum) : sum(sum) { right = left = NULL; };
};
typedef Node *tree;
tree val[100007];
int sum(tree T) {
  if (!T) return 0;
  return T->sum;
}
void update(tree &T, int tl, int tr, int l, int r, int add) {
  if (tr < l || r < tl) return;
  if (!T) T = new Node(0);
  if (l <= tl && tr <= r)
    T->sum += add;
  else {
    int tm = (tl + tr) >> 1;
    update(T->left, tl, tm, l, r, add);
    update(T->right, tm + 1, tr, l, r, add);
  }
}
int get(tree &T, int tl, int tr, int pos) {
  if (!T) return 0;
  if (tl == tr) return T->sum;
  int tm = (tl + tr) >> 1;
  if (pos <= tm)
    return get(T->left, tl, tm, pos) + T->sum;
  else
    return get(T->right, tm + 1, tr, pos) + T->sum;
}
struct query {
  int tp, time, x;
};
int n;
query q[N];
vector<int> numx;
int main() {
  for (int i = 0; i <= 100005; ++i) val[i] = NULL;
  cin >> n;
  numx.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> q[i].tp >> q[i].time >> q[i].x;
    numx[i] = q[i].x;
  }
  sort(numx.begin(), numx.end());
  for (int i = 0; i < n; ++i) {
    q[i].x = lower_bound(numx.begin(), numx.end(), q[i].x) - numx.begin();
  }
  for (int i = 0; i < n; ++i) {
    if (q[i].tp == 1) update(val[q[i].x], 1, inf, q[i].time, inf, 1);
    if (q[i].tp == 2) update(val[q[i].x], 1, inf, q[i].time, inf, -1);
    if (q[i].tp == 3) cout << get(val[q[i].x], 1, inf, q[i].time) << endl;
  }
  return 0;
}
