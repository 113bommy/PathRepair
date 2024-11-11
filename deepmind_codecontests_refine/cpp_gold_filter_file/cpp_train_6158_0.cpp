#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int dir[8][2] = {-2, -1, -2, 1, 2, -1, 2, 1, -1, 2, -1, -2, 1, 2, 1, -2};
const int maxn = 2e5 + 5;
int n, m, q;
struct node {
  int a, pos;
  bool operator<(const node &b) const { return a < b.a; }
} lisan[maxn];
int tree[maxn * 4];
int w[maxn];
int pre[maxn][27];
int last[maxn];
void build(int root, int a, int b);
void change(int root, int a, int b, int x, int k);
int ask(int root, int a, int b, int x, int y);
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    lisan[i].a = a;
    lisan[i].pos = i;
  }
  sort(lisan + 1, lisan + 1 + n);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &w[i]);
    w[i] = lisan[w[i]].pos;
  }
  memset(pre, -1, sizeof(pre));
  memset(last, -1, sizeof(last));
  for (int i = 1; i <= m; i++) {
    int a = w[i] - 1;
    if (!a) a = n;
    pre[i][0] = last[a];
    last[w[i]] = i;
  }
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= m; j++) {
      if (pre[j][i - 1] != -1) pre[j][i] = pre[pre[j][i - 1]][i - 1];
    }
  }
  build(1, 1, m);
  for (int i = 1; i <= m; i++) {
    int a = i, b = n - 1;
    for (int j = 20; j >= 0 && a != -1; j--) {
      if ((1 << j) <= b) {
        b -= 1 << j;
        a = pre[a][j];
      }
    }
    if (a != -1) change(1, 1, m, i, a);
  }
  for (int i = 1; i <= q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (ask(1, 1, m, a, b) >= a)
      printf("1");
    else
      printf("0");
  }
  return 0;
}
void build(int root, int a, int b) {
  if (a == b) {
    tree[root] = 0;
    return;
  }
  int mid = (a + b) / 2;
  build(root * 2, a, mid);
  build(root * 2 + 1, mid + 1, b);
  tree[root] = 0;
}
void change(int root, int a, int b, int x, int k) {
  if (a == b) {
    tree[root] += k;
    return;
  }
  int mid = (a + b) / 2;
  if (x <= mid) {
    change(root * 2, a, mid, x, k);
  } else {
    change(root * 2 + 1, mid + 1, b, x, k);
  }
  tree[root] = max(tree[root * 2], tree[root * 2 + 1]);
}
int ask(int root, int a, int b, int x, int y) {
  if (x <= a && b <= y) return tree[root];
  if (b < x || a > y) return 0;
  int mid = (a + b) / 2;
  return max(ask(root * 2, a, mid, x, y), ask(root * 2 + 1, mid + 1, b, x, y));
}
