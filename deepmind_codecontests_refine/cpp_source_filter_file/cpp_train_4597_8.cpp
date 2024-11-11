#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, cnt, a[500100], pl = 100000;
struct node {
  int left, right, lazy1, lazy2, d;
  node *ch[2];
} pool[2 * 500100], *root;
char ans[500100];
void buildtree(node *p, int left, int right) {
  p->left = left;
  p->right = right;
  p->d = 1;
  if (left == right) return;
  int mid = (left + right) / 2;
  node *lson = &pool[++cnt], *rson = &pool[++cnt];
  p->ch[0] = lson;
  p->ch[1] = rson;
  buildtree(lson, left, mid);
  buildtree(rson, mid + 1, right);
}
void push(node *p) {
  if (p->lazy1 != 0) {
    if (p->ch[0]) p->ch[0]->lazy1 = p->lazy1, p->ch[0]->lazy2 = 0;
    if (p->ch[1]) p->ch[1]->lazy1 = p->lazy1, p->ch[1]->lazy2 = 0;
    p->d = p->lazy1;
    p->lazy1 = 0;
  }
  if (p->lazy2 != 0) {
    if (p->ch[0]) p->ch[0]->lazy2 ^= 1;
    if (p->ch[1]) p->ch[1]->lazy2 ^= 1;
    p->d *= -1;
    p->lazy2 = 0;
  }
}
void change1(node *p, int left, int right, int s) {
  if (left > right) return;
  if (p->left == left && p->right == right) {
    p->lazy1 = s;
    p->lazy2 = 0;
    return;
  }
  push(p);
  if (p->ch[0]->right >= right)
    change1(p->ch[0], left, right, s);
  else if (p->ch[1]->left <= left)
    change1(p->ch[1], left, right, s);
  else {
    change1(p->ch[0], left, p->ch[0]->right, s);
    change1(p->ch[1], p->ch[1]->left, right, s);
  }
}
void change2(node *p, int left, int right) {
  if (left > right) return;
  if (p->left == left && p->right == right) {
    p->lazy2 ^= 1;
    return;
  }
  push(p);
  if (p->ch[0]->right >= right)
    change2(p->ch[0], left, right);
  else if (p->ch[1]->left <= left)
    change2(p->ch[1], left, right);
  else {
    change2(p->ch[0], left, p->ch[0]->right);
    change2(p->ch[1], p->ch[1]->left, right);
  }
}
int query(node *p, int left, int right) {
  push(p);
  if (p->left == left && p->right == right) return p->d;
  if (p->ch[0]->right >= right)
    return query(p->ch[0], left, right);
  else if (p->ch[1]->left <= left)
    return query(p->ch[1], left, right);
}
int main() {
  scanf("%d%d", &n, &m);
  root = &pool[++cnt];
  buildtree(root, 0, 200000);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  char s[5];
  int u;
  for (int i = 1; i <= m; i++) {
    scanf("%s%d", s + 1, &u);
    if (s[1] == '>') {
      if (u >= 0) {
        change1(root, u + pl + 1, pl * 2, -1);
        change1(root, 0, -u + pl - 1, 1);
      } else {
        change1(root, 0, u + pl - 1, 1);
        change1(root, -u + pl, 2 * pl, -1);
        change2(root, u + pl + 1, -u + pl - 1);
      }
    } else {
      if (u <= 0) {
        change1(root, 0, u + pl - 1, -1);
        change1(root, -u + pl + 1, pl + pl, 1);
      } else {
        change1(root, u + pl + 1, pl + pl, 1);
        change1(root, 0, -u + pl, -1);
        change2(root, -u + pl + 1, u + pl - 1);
      }
    }
  }
  for (int j = 1; j <= n; j++) {
    printf("%d ", a[j] * query(root, a[j] + pl, a[j] + pl));
  }
  cout << endl;
  return 0;
}
