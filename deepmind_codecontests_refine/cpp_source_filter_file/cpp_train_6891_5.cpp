#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node {
  int L, R, sum;
  Node() { sum = 0; }
} Tree[maxn * 20];
int cnt, n, m;
struct value {
  int x, id;
} v[maxn];
bool cmp(value v1, value v2) {
  if (v1.x != v2.x) return v1.x > v2.x;
  return v1.id < v2.id;
}
int root[maxn], rank[maxn];
void init() {
  cnt = 1;
  root[0] = 0;
  Tree[0].L = Tree[0].R = Tree[0].sum = 0;
}
void update(int num, int &rt, int l, int r) {
  Tree[cnt++] = Tree[rt];
  rt = cnt - 1;
  Tree[rt].sum++;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (num <= mid)
    update(num, Tree[rt].L, l, mid);
  else
    update(num, Tree[rt].R, mid + 1, r);
}
int query(int i, int j, int k, int l, int r) {
  int d = Tree[Tree[j].L].sum - Tree[Tree[i].L].sum;
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (k <= d)
    return query(Tree[i].L, Tree[j].L, k, l, mid);
  else
    return query(Tree[i].R, Tree[j].R, k - d, mid + 1, r);
}
int aa[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i].x);
    v[i].id = i;
    aa[i] = v[i].x;
  }
  sort(v + 1, v + 1 + n, cmp);
  init();
  for (int i = 1; i <= n; i++) {
    root[i] = root[i - 1];
    update(v[i].id, root[i], 1, n);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    int d = query(root[0], root[a], b, 1, n);
    printf("%d\n", aa[d]);
  }
  return 0;
}
