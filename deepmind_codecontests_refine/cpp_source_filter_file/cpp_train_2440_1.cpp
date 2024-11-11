#include <bits/stdc++.h>
using namespace std;
inline const int Get_Int() {
  int num = 0, bj = 1;
  char x = getchar();
  while (x < '0' || x > '9') {
    if (x == '-') bj = -1;
    x = getchar();
  }
  while (x >= '0' && x <= '9') {
    num = num * 10 + x - '0';
    x = getchar();
  }
  return num * bj;
}
const int maxn = 100005;
int n, q, First[maxn], Last[maxn], step = 2;
vector<int> edges[maxn];
struct Tree {
  int child[2], father;
  int key, small, big, depth, lazy, id;
  Tree() {}
  Tree(int l, int r, int fa, int k, int d, int _id)
      : father(fa), key(k), small(d), big(d), depth(d), lazy(0), id(_id) {
    child[0] = l;
    child[1] = r;
  }
};
struct Splay {
  int size, root;
  Tree tree[maxn];
  Splay() {
    tree[++size] = Tree(0, 2, 0, -INT_MAX, 0, 0);
    tree[size].small = INT_MAX, tree[size].big = -INT_MAX;
    tree[++size] = Tree(0, 0, 1, INT_MAX, 0, 0);
    tree[size].small = INT_MAX, tree[size].big = -INT_MAX;
    root = size;
  }
  void clear(int index) { tree[index] = Tree(0, 0, 0, 0, 0, 0); }
  bool checkson(int index) {
    return tree[tree[index].father].child[1] == index;
  }
  void modify(int index, int v) {
    tree[index].lazy += v;
    if (index <= 2) return;
    tree[index].depth += v;
    tree[index].small += v;
    tree[index].big += v;
  }
  void push_down(int index) {
    if (!tree[index].lazy) return;
    if (tree[index].child[0]) modify(tree[index].child[0], tree[index].lazy);
    if (tree[index].child[1]) modify(tree[index].child[1], tree[index].lazy);
    tree[index].lazy = 0;
  }
  void push_up(int index) {
    if (!index) return;
    if (index <= 2)
      tree[size].small = INT_MAX, tree[size].big = -INT_MAX;
    else
      tree[index].small = tree[index].big = tree[index].depth;
    if (tree[index].child[0]) {
      tree[index].small =
          min(tree[index].small, tree[tree[index].child[0]].small);
      tree[index].big = max(tree[index].big, tree[tree[index].child[0]].big);
    }
    if (tree[index].child[1]) {
      tree[index].small =
          min(tree[index].small, tree[tree[index].child[1]].small);
      tree[index].big = max(tree[index].big, tree[tree[index].child[1]].big);
    }
  }
  void rotate(int index) {
    int father = tree[index].father, grand = tree[father].father,
        side = checkson(index);
    if (grand) tree[grand].child[checkson(father)] = index;
    tree[father].child[side] = tree[index].child[side ^ 1];
    tree[tree[father].child[side]].father = father;
    tree[father].father = index;
    tree[index].child[side ^ 1] = father;
    tree[index].father = grand;
    push_up(father);
    push_up(index);
  }
  void splay(int index, int target = 0) {
    push_down(index);
    for (int father; (father = tree[index].father) != target; rotate(index)) {
      int grand = tree[father].father;
      if (grand) push_down(grand);
      push_down(father);
      push_down(index);
      if (tree[father].father != target)
        rotate(checkson(index) == checkson(father) ? father : index);
    }
    if (target == 0) root = index;
  }
  int insert(int v, int d, int id) {
    int now = root, father = 0;
    while (now && tree[now].key != v) {
      father = now;
      now = tree[now].child[tree[now].key < v];
    }
    tree[now = ++size] = Tree(0, 0, father, v, d, id);
    if (father) tree[father].child[tree[father].key < v] = now;
    splay(now);
    return now;
  }
  int pre_suc(int bj) {
    push_down(root);
    int now = tree[root].child[bj];
    while (tree[now].child[bj ^ 1])
      push_down(now), now = tree[now].child[bj ^ 1];
    push_down(now);
    return now;
  }
  int Find(int index, int d) {
    while (true) {
      push_down(index);
      if (tree[index].child[1] && tree[tree[index].child[1]].small <= d &&
          tree[tree[index].child[1]].big >= d)
        index = tree[index].child[1];
      else if (tree[index].depth == d)
        return index;
      else
        index = tree[index].child[0];
    }
  }
  int dist(int x, int y) {
    if (x == y) return 0;
    splay(First[x]);
    splay(First[y], root);
    int pos = tree[First[y]].child[checkson(First[y]) ^ 1];
    int ans = pos ? tree[pos].small : INT_MAX;
    ans = min(ans, min(tree[First[x]].depth, tree[First[y]].depth));
    return tree[First[x]].depth + tree[First[y]].depth - 2 * ans;
  }
  void change(int x, int y) {
    splay(First[x]);
    int p = tree[Find(tree[First[x]].child[0], tree[First[x]].depth - y)].id;
    int pre = pre_suc(0);
    splay(Last[x]);
    int suc = pre_suc(1);
    splay(pre);
    splay(suc, pre);
    int pos = tree[suc].child[0];
    push_down(pre), push_down(suc);
    int num = -tree[pre].depth - (pre == First[tree[pre].id]);
    tree[pos].father = tree[suc].child[0] = 0;
    push_up(suc), push_up(pre);
    splay(Last[p]);
    pre = pre_suc(0);
    splay(pre);
    splay(suc = Last[p], pre);
    push_down(pre), push_down(suc);
    num += tree[pre].depth + (pre == First[tree[pre].id]);
    tree[suc].child[0] = pos;
    tree[pos].father = suc;
    modify(pos, num);
    push_up(suc);
    push_up(pre);
  }
} bbt;
void AddEdge(int x, int y) { edges[x].push_back(y); }
void Dfs(int Now, int depth) {
  First[Now] = ++step;
  bbt.insert(step, depth, Now);
  for (int Next : edges[Now]) Dfs(Next, depth + 1);
  Last[Now] = ++step;
  bbt.insert(step, depth, Now);
}
int main() {
  n = Get_Int();
  q = Get_Int();
  for (int i = 1; i <= n; i++) {
    int x = Get_Int();
    while (x--) AddEdge(i, Get_Int());
  }
  Dfs(1, 1);
  while (q--) {
    int opt = Get_Int(), x = Get_Int();
    if (opt == 1)
      printf("%d\n", bbt.dist(x, Get_Int()));
    else if (opt == 2)
      bbt.change(x, Get_Int());
    else
      printf("%d\n", bbt.tree[bbt.Find(bbt.root, x + 1)].id);
  }
  return 0;
}
