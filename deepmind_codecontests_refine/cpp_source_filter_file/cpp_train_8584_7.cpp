#include <bits/stdc++.h>
using namespace std;
const int MAXV = 30;
const int N = 100005;
int tree[N * 4][MAXV + 5], leaf[N];
int a[N];
void combine(int nd) {
  int cc = nd << 1;
  for (int i = 0; i < MAXV; i++)
    tree[nd][i] = tree[cc][i] + tree[cc ^ 1][(tree[cc][i] + i) % MAXV];
}
void build(int nd, int le, int ri) {
  if (le == ri) {
    for (int i = 0; i < MAXV; i++)
      if (i % a[le] == 0)
        tree[nd][i] = 2;
      else
        tree[nd][i] = 1;
    leaf[le] = nd;
    return;
  }
  int mi = (le + ri) >> 1;
  int cc = nd << 1;
  build(cc, le, mi);
  build(cc ^ 1, mi + 1, ri);
  combine(nd);
}
void update(int id, int val) {
  if (a[id] == val) return;
  a[id] = val;
  int nd = leaf[id];
  for (int i = 0; i < MAXV; i++)
    if (i % val == 0)
      tree[nd][i] = 2;
    else
      tree[nd][i] = 1;
  nd >>= 1;
  while (nd > 0) {
    combine(nd);
    nd >>= 1;
  }
}
pair<int, int> query(int nd, int le, int ri, int tr, int ph, int val) {
  if (le > ph || ri < tr) return {0, 0};
  if (tr <= le && ri <= ph) {
    return {tree[nd][val], (val + tree[nd][val]) % MAXV};
  }
  int mi = (le + ri) >> 1;
  int cc = nd << 1;
  auto p = query(cc, le, mi, tr, ph, val);
  auto p2 = query(cc ^ 1, mi + 1, ri, tr, ph, p.second);
  return {p.first + p2.first, p2.second};
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    char code[10];
    scanf("%s", code);
    scanf("%d%d", &x, &y);
    if (code[0] == 'A') {
      printf("%d\n", query(1, 1, n, x, y - 1, 0));
    } else {
      update(x, y);
    }
  }
  return 0;
}
