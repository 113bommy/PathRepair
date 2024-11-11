#include <bits/stdc++.h>
inline int read() {
  register int x = 0;
  register int y = 1;
  register char c = std::getchar();
  while (c < '0' || c > '9') {
    if (c == '-') y = 0;
    c = std::getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48);
    c = std::getchar();
  }
  return y ? x : -x;
}
struct tr {
  tr *son[2];
  int cnt;
} dizhi[100006 * 30], *root, *null;
int tot;
inline void New(tr *&tree) {
  tree = &dizhi[++tot];
  tree->son[0] = tree->son[1] = null;
}
inline void init() {
  null = &dizhi[0];
  null->son[0] = null->son[1] = null;
  New(root);
}
void insert(tr *tree, int num, int pos) {
  tree->cnt++;
  if (pos < 0) return;
  int nex = (num >> pos) & 1;
  if (tree->son[nex] == null) New(tree->son[nex]);
  insert(tree->son[nex], num, pos - 1);
}
void del(tr *tree, int num, int pos) {
  tree->cnt--;
  if (pos < 0) return;
  del(tree->son[(num >> pos) & 1], num, pos - 1);
}
int ask(tr *tree, int num, int lim, int pos) {
  if (pos < 0) return tree->cnt;
  int nex = (num >> pos) & 1;
  if ((lim >> pos) & 1)
    return tree->son[nex ^ 1]->cnt + ask(tree->son[nex], num, lim, pos - 1);
  return ask(tree->son[nex], num, lim, pos - 1);
}
int main() {
  int q = read();
  init();
  register int op, x;
  while (q--) {
    op = read();
    if (op == 1)
      insert(root, read(), 28);
    else if (op == 2)
      del(root, read(), 28);
    else {
      x = read();
      printf("%d\n", ask(root, x, read() - 1, 28));
    }
  }
  return 0;
}
