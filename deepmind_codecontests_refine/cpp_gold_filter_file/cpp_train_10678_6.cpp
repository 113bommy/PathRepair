#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int tree[4 * MAXN];
int maxTree[4 * MAXN];
int p[MAXN];
int n;
void push(int v) {
  if (tree[v]) {
    tree[2 * v] += tree[v];
    tree[2 * v + 1] += tree[v];
    maxTree[2 * v] += tree[v];
    maxTree[2 * v + 1] += tree[v];
    tree[v] = 0;
  }
}
void update(int v, int tl, int tr, int l, int r, int add) {
  if (l > r) return;
  if (tl == l && tr == r) {
    tree[v] += add;
    maxTree[v] += add;
    return;
  }
  int tm = (tl + tr) >> 1;
  push(v);
  update(2 * v, tl, tm, l, min(r, tm), add);
  update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
  maxTree[v] = max(maxTree[2 * v], maxTree[2 * v + 1]);
}
int findIndex(int v, int tl, int tr) {
  if (tl == tr) return tl;
  push(v);
  int tm = (tl + tr) >> 1;
  if (maxTree[2 * v] > 0) {
    return findIndex(2 * v, tl, tm);
  } else {
    return findIndex(2 * v + 1, tm + 1, tr);
  }
}
int main() {
  for (int i = 0; i < 4 * MAXN; i++) {
    tree[i] = 0;
    maxTree[i] = 0;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int pos, op;
    scanf("%d %d", &pos, &op);
    pos = n - pos + 1;
    if (op) {
      int number;
      scanf("%d", &number);
      p[pos] = number;
      update(1, 1, n, pos, n, 1);
    } else {
      p[pos] = -1;
      update(1, 1, n, pos, n, -1);
    }
    if (maxTree[1] > 0) {
      int index = findIndex(1, 1, n);
      printf("%d\n", p[index]);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
