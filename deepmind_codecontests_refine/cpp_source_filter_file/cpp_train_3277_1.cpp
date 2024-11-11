#include <bits/stdc++.h>
using namespace std;
const int maxn = 20e5 + 10;
int pre[maxn], size[maxn], flip[maxn], tot, root, ch[maxn][2], key[maxn], flag;
int aa[maxn];
void Newnode(int &rt, int fa, int x) {
  rt = ++tot;
  pre[rt] = fa;
  size[rt] = 1;
  flip[rt] = 0;
  key[rt] = x;
  ch[rt][0] = ch[rt][1] = 0;
}
void pushup(int rt) { size[rt] = size[ch[rt][0]] + size[ch[rt][1]] + 1; }
void pushdown(int rt) {
  if (flip[rt]) {
    swap(ch[rt][0], ch[rt][1]);
    flip[ch[rt][0]] ^= 1;
    flip[ch[rt][1]] ^= 1;
    flip[rt] = 0;
  }
}
void build(int &rt, int l, int r, int fa) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  Newnode(rt, fa, aa[mid]);
  if (l < mid) build(ch[rt][0], l, mid - 1, rt);
  if (r > mid) build(ch[rt][1], mid + 1, r, rt);
  pushup(rt);
}
void rotate(int rt, int kind) {
  int y = pre[rt];
  pushdown(y), pushdown(rt);
  ch[y][!kind] = ch[rt][kind];
  pre[ch[rt][kind]] = y;
  if (pre[y]) {
    ch[pre[y]][ch[pre[y]][1] == y] = rt;
  }
  pre[rt] = pre[y];
  ch[rt][kind] = y;
  pre[y] = rt;
  pushup(y);
}
void Splay(int rt, int goal) {
  while (pre[rt] != goal) {
    int y = pre[rt], z = pre[y];
    pushdown(z), pushdown(y), pushdown(rt);
    if (pre[pre[rt]] == goal) {
      rotate(rt, ch[pre[rt]][0] == rt);
    } else {
      int y = pre[rt];
      int kind = ch[pre[y]][0] == y;
      if (ch[y][kind] == rt) {
        rotate(rt, !kind);
        rotate(rt, kind);
      } else {
        rotate(y, kind);
        rotate(rt, kind);
      }
    }
  }
  pushup(rt);
  if (goal == 0) root = rt;
}
int Kth(int rt, int k) {
  pushdown(rt);
  int temp = size[ch[rt][0]] + 1;
  if (k == temp)
    return rt;
  else if (k < temp)
    return Kth(ch[rt][0], k);
  else
    return Kth(ch[rt][1], k - temp);
}
void reverse(int a, int b) {
  int x = Kth(root, a);
  Splay(x, 0);
  int y = Kth(root, b + 2);
  Splay(y, root);
  flip[ch[ch[root][1]][0]] ^= 1;
}
int n, m;
void init() {
  pre[0] = size[0] = key[0] = flip[0] = ch[0][0] = ch[0][1] = root = tot =
      flag = 0;
  Newnode(root, 0, -1);
  Newnode(ch[root][1], root, -1);
  size[root] = 2;
  build(ch[ch[root][1]][0], 1, n, ch[root][1]);
  pushup(ch[root][1]);
  pushup(root);
}
int cnt;
void print(int rt) {
  if (rt == 0) return;
  pushdown(rt);
  if (ch[rt][0]) print(ch[rt][0]);
  if (cnt >= 1 && cnt <= n) {
    printf("%c", key[rt] + 'a');
  }
  cnt++;
  if (ch[rt][1]) print(ch[rt][1]);
}
char ss[100000 + 10];
int main() {
  while (scanf("%s%d", ss, &m) != EOF) {
    n = strlen(ss);
    int i;
    for (int i = (1); i <= (n); i++) {
      aa[i] = ss[i - 1] - 'a';
    }
    init();
    while (m--) {
      int cc;
      scanf("%d", &cc);
      reverse(cc, n - cc + 1);
    }
    cnt = 0;
    print(root);
    printf("\n");
  }
  return 0;
}
