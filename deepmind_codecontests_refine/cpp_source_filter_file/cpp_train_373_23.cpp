#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const long long LINF = 2e16;
const int magic = 348;
const int MOD = 998244353;
const double eps = 1e-10;
const double pi = acos(-1);
inline int getint() {
  bool f;
  char ch;
  int res;
  while (!isdigit(ch = getchar()) && ch != '-') {
  }
  if (ch == '-')
    f = false, res = 0;
  else
    f = true, res = ch - '0';
  while (isdigit(ch = getchar())) res = res * 10 + ch - '0';
  return f ? res : -res;
}
const int MAXN = 1e5;
int root[10];
pair<int, int> tmp[10];
namespace Treap {
struct node {
  int left, right, val, priority;
  long long sum;
  int sz;
} tree[MAXN * 2];
int tot = 0;
inline void pushup(int cur) {
  tree[cur].sum =
      tree[tree[cur].left].sum + tree[tree[cur].right].sum + tree[cur].val;
  tree[cur].sz = tree[tree[cur].left].sz + tree[tree[cur].right].sz + 1;
}
inline int Create(int left, int right, int val, int priority) {
  ++tot;
  tree[tot].left = left;
  tree[tot].right = right;
  tree[tot].val = val;
  tree[tot].priority = priority;
  pushup(tot);
  return tot;
}
inline pair<int, int> split(int root, int val) {
  if (!root) return make_pair(0, 0);
  if (tree[root].val <= val) {
    pair<int, int> splitted = split(tree[root].right, val);
    tree[root].right = splitted.first;
    pushup(root);
    return make_pair(root, splitted.second);
  } else {
    pair<int, int> splitted = split(tree[root].left, val);
    tree[root].left = splitted.second;
    pushup(root);
    return make_pair(splitted.first, root);
  }
}
inline pair<int, int> split2(int root, int k) {
  if (!root) return make_pair(0, 0);
  int leftsz = tree[tree[root].left].sz + 1;
  if (k >= leftsz) {
    pair<int, int> splitted = split2(tree[root].right, k - leftsz);
    tree[root].right = splitted.first;
    pushup(root);
    return make_pair(root, splitted.second);
  } else {
    pair<int, int> splitted = split2(tree[root].left, k);
    tree[root].right = splitted.second;
    pushup(root);
    return make_pair(splitted.first, root);
  }
}
inline int merge(int root1, int root2) {
  if (!root1 || !root2) return root1 + root2;
  if (tree[root1].priority <= tree[root2].priority) {
    tree[root1].right = merge(tree[root1].right, root2);
    pushup(root1);
    return root1;
  } else {
    tree[root2].left = merge(root1, tree[root2].left);
    pushup(root2);
    return root2;
  }
}
inline bool find(int root, int first) {
  if (!root) return false;
  if (tree[root].val == first) return true;
  if (first < tree[root].val)
    return find(tree[root].left, first);
  else
    return find(tree[root].right, first);
}
}  // namespace Treap
int main() {
  int first, i, pos, q = getint();
  char op[5];
  while (q--) {
    scanf("%s", op + 1);
    if (op[1] == 'a') {
      first = getint();
      for (i = 0; i <= 4; i++) tmp[i] = Treap::split(root[i], first);
      pos = 1;
      for (i = 0; i <= 4; i++) pos += Treap::tree[tmp[i].first].sz;
      pos %= 5;
      tmp[pos].first =
          Treap::merge(tmp[pos].first, Treap::Create(0, 0, first, rand()));
      for (i = 0; i <= 4; i++)
        root[(i + 1) % 5] = Treap::merge(tmp[(i + 1) % 5].first, tmp[i].second);
    }
    if (op[1] == 'd') {
      first = getint();
      for (i = 0; i <= 4; i++)
        if (Treap::find(root[i], first)) {
          pos = i;
          break;
        }
      for (i = 0; i <= 4; i++) tmp[i] = Treap::split(root[i], first);
      tmp[pos].second = Treap::split2(tmp[pos].second, 1).second;
      for (i = 0; i <= 4; i++)
        root[i] = Treap::merge(tmp[i].first, tmp[(i + 1) % 5].second);
    }
    if (op[1] == 's') printf("%lld\n", Treap::tree[root[3]].sum);
  }
  return 0;
}
