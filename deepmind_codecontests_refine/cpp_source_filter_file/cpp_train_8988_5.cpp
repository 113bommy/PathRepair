#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int l, r;
  int lou, sou, rou;
} Node;
Node tree[4 * 200000 + 10];
int n;
void push_up(int k) {
  if (tree[2 * k].sou == tree[2 * k].r - tree[2 * k].l + 1)
    tree[k].lou = tree[2 * k].sou + tree[2 * k + 1].lou;
  else
    tree[k].lou = tree[2 * k].lou;
  if (tree[2 * k + 1].sou == tree[2 * k + 1].r - tree[2 * k + 1].l + 1)
    tree[k].rou = tree[2 * k + 1].sou + tree[2 * k].rou;
  else
    tree[k].rou = tree[2 * k + 1].rou;
  tree[k].sou = max(tree[2 * k].sou, tree[2 * k + 1].sou);
  tree[k].sou = max(tree[k].sou, tree[2 * k].rou + tree[2 * k + 1].lou);
}
void build(int l, int r, int k) {
  tree[k].l = l;
  tree[k].r = r;
  if (l == r)
    tree[k].lou = tree[k].rou = tree[k].sou = 1;
  else {
    int mid = (l + r) / 2;
    build(l, mid, 2 * k);
    build(mid + 1, r, 2 * k + 1);
    push_up(k);
  }
}
void update(int pot, int k, int val) {
  if (tree[k].l == tree[k].r) {
    tree[k].lou = tree[k].rou = tree[k].sou = val;
  } else {
    int mid = (tree[k].l + tree[k].r) / 2;
    if (mid >= pot)
      update(pot, 2 * k, val);
    else
      update(pot, 2 * k + 1, val);
    push_up(k);
  }
}
int query(int len, int k) {
  if (tree[k].l == tree[k].r)
    return tree[k].l;
  else {
    int mid = (tree[k].l + tree[k].r) / 2;
    if (tree[2 * k].sou >= len)
      return query(len, 2 * k);
    else if (tree[2 * k].rou + tree[2 * k + 1].lou >= len)
      return mid - tree[2 * k].rou + 1;
    else
      return query(len, 2 * k + 1);
  }
}
int spot[200000 + 10];
int main() {
  int m;
  while (scanf("%d%d", &n, &m) != EOF) {
    build(1, n, 1);
    while (m--) {
      int type, id;
      scanf("%d%d", &type, &id);
      if (type == 1) {
        int len = tree[1].sou;
        if (len % 2 == 0) len--;
        if (tree[1].lou >= tree[1].rou) {
          if (tree[1].lou >= len / 2 + 1)
            spot[id] = 1;
          else
            spot[id] = query(len, 1) + len / 2;
        } else {
          if (tree[1].rou > len / 2 + 1)
            spot[id] = n;
          else
            spot[id] = query(len, 1) + len / 2;
        }
        update(spot[id], 1, 0);
        printf("%d\n", spot[id]);
      } else
        update(spot[id], 1, 1);
    }
  }
  return 0;
}
