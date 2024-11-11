#include <bits/stdc++.h>
using namespace std;
struct node {
  int ch[2], siz, fa;
  int val, max;
} tree[100005];
int tot, root;
void Newnode(int &id, int fa, int val, int siz = 1) {
  node E = {0, 0, siz, fa, val, val};
  id = tot++;
  tree[id] = E;
}
void push_down(int id) {}
void push_up(int id) {
  tree[id].siz = tree[tree[id].ch[0]].siz + tree[tree[id].ch[1]].siz + 1;
  tree[id].max = max(max(tree[tree[id].ch[0]].max, tree[tree[id].ch[1]].max),
                     tree[id].val);
}
void Rotate(int id, int kind) {
  int y = tree[id].fa;
  push_down(y);
  push_down(id);
  tree[y].ch[kind ^ 1] = tree[id].ch[kind];
  tree[tree[id].ch[kind]].fa = y;
  if (tree[y].fa) tree[tree[y].fa].ch[tree[tree[y].fa].ch[1] == y] = id;
  tree[id].fa = tree[y].fa;
  tree[y].fa = id;
  tree[id].ch[kind] = y;
  push_up(y);
}
void Splay(int id, int goal) {
  push_down(id);
  while (tree[id].fa != goal) {
    int y = tree[id].fa;
    if (tree[y].fa == goal)
      Rotate(id, tree[y].ch[0] == id);
    else {
      int kind = tree[tree[y].fa].ch[0] == y;
      if (tree[y].ch[kind] == id) {
        Rotate(id, kind ^ 1);
        Rotate(id, kind);
      } else {
        Rotate(y, kind);
        Rotate(id, kind);
      }
    }
  }
  push_up(id);
  if (goal == 0) root = id;
}
void Insert(int &id, int val, int siz, int father) {
  if (id == 0) {
    Newnode(id, father, val);
    return;
  }
  if (val < tree[tree[id].ch[1]].max || val < tree[id].val ||
      siz < tree[tree[id].ch[1]].siz)
    Insert(tree[id].ch[1], val, siz, id);
  else
    Insert(tree[id].ch[0], val, siz - tree[tree[id].ch[1]].siz - 1, id);
  push_up(id);
}
void init() {
  tree[0].fa = tree[0].ch[0] = tree[0].ch[1] = tree[0].siz = 0;
  tree[0].val = 0;
  tot = 0;
  Newnode(root, 0, 1000000);
  Newnode(tree[root].ch[1], root, -1);
  push_up(root);
}
map<int, int> mp;
void put(int id) {
  if (tree[id].ch[0]) put(tree[id].ch[0]);
  if (id > 2) printf("%d ", mp[tree[id].val]);
  if (tree[id].ch[1]) put(tree[id].ch[1]);
}
int main() {
  int i, u, v, n, id;
  while (cin >> n) {
    mp.clear();
    init();
    for (i = 1; i <= n; i++) {
      scanf("%d %d", &u, &v);
      Insert(root, u, v, 0);
      Splay(tot - 1, 0);
      mp[u] = i;
    }
    put(root);
    puts("");
  }
  return 0;
}
