#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
const int maxtreetop = 2100000;
struct Ttree {
  int left, right;
  int mark;
  int covered;
} tree[maxtreetop + 1];
vector<int> g[maxn + 1];
vector<int> lx[maxn + 1];
int n, m;
int result[maxn + 1], resulttop;
bool success = true;
bool dy = false;
void init() {
  int i, x, y;
  char s[100];
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; ++i) {
    scanf("%d%d%s", &x, &y, s);
    g[x].push_back(y);
    if (s[0] == 'L')
      lx[x].push_back(-1);
    else
      lx[x].push_back(1);
    if (x > y) success = false;
  }
}
void init_tree(int p, int start, int stop) {
  tree[p].left = start;
  tree[p].right = stop;
  tree[p].covered = tree[p].mark = 0;
  if (start < stop) {
    int mid = (start + stop) / 2;
    init_tree(p * 2, start, mid);
    init_tree(p * 2 + 1, mid + 1, stop);
  }
}
void update(int p) {
  if (!tree[p].mark) {
    if (tree[p].left < tree[p].right)
      tree[p].covered = tree[p * 2].covered + tree[p * 2 + 1].covered;
    else
      tree[p].covered = 0;
  }
  if (tree[p].mark) tree[p].covered = tree[p].right - tree[p].left + 1;
}
void ins_tree(int p, int start, int stop, int delta) {
  if ((start <= tree[p].left) && (stop >= tree[p].right)) {
    tree[p].mark += delta;
    update(p);
    return;
  }
  int mid = (tree[p].left + tree[p].right) / 2;
  if (start <= mid) ins_tree(p * 2, start, stop, delta);
  if (stop > mid) ins_tree(p * 2 + 1, start, stop, delta);
  update(p);
}
void zhao_tree(int p, int start, int stop, int &you) {
  if (you != -1) return;
  if (tree[p].covered == tree[p].right - tree[p].left + 1) return;
  if ((start <= tree[p].left) && (stop >= tree[p].right)) {
    if (tree[p].left == tree[p].right) {
      you = tree[p].left;
      return;
    }
  }
  int mid = (tree[p].left + tree[p].right) / 2;
  if (start <= mid) zhao_tree(p * 2, start, stop, you);
  if (you != -1) return;
  if (stop > mid) zhao_tree(p * 2 + 1, start, stop, you);
}
void gao(int root, int stop) {
  if (stop < root) return;
  if (stop == root) {
    result[++resulttop] = root;
    return;
  }
  int left = root, right = stop;
  if (!success) return;
  for (int i = 0; i < g[root].size(); ++i) {
    if (lx[root][i] == -1) {
      if (g[root][i] > left) left = g[root][i];
    } else {
      if (g[root][i] - 1 < right) right = g[root][i] - 1;
    }
    ins_tree(1, root, g[root][i] - 1, -1);
  }
  if (left > right) {
    success = false;
    return;
  }
  int you = -1;
  zhao_tree(1, left, right, you);
  if (you == -1) {
    success = false;
    return;
  }
  gao(root + 1, you);
  result[++resulttop] = root;
  gao(you + 1, stop);
}
void work() {
  int i, j;
  if (!success) return;
  init_tree(1, 1, n);
  for (i = 1; i <= n; ++i)
    for (j = 0; j < g[i].size(); ++j) ins_tree(1, i, g[i][j] - 1, 1);
  resulttop = 0;
  gao(1, n);
}
void output() {
  if (!success) {
    printf("IMPOSSIBLE\n");
  } else {
    for (int i = 1; i <= n; ++i) {
      printf("%d", result[i]);
      if (i == n)
        printf("\n");
      else
        printf(" ");
    }
  }
}
int main() {
  init();
  work();
  output();
  return 0;
}
