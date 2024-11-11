#include <bits/stdc++.h>
using namespace std;
FILE *in = stdin;
class node {
 public:
  long long sum[5], hnode;
  node() {
    sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = hnode = 0;
    return;
  }
  node(int x) {
    for (int q = 0; q < 5; q++) {
      sum[q] = 0;
    }
    sum[0] = x;
    hnode = 1;
    return;
  }
};
node merge(node a, node b) {
  node c;
  c.hnode = a.hnode + b.hnode;
  int left = a.hnode % 5;
  for (int q = 0; q < 5; q++) {
    c.sum[q] = a.sum[q] + b.sum[(5 - left + q) % 5];
  }
  return c;
}
class segment_tree {
 public:
  node tree[4 * 100000];
  segment_tree() {
    for (int q = 0; q < 4 * 100000; q++) {
      tree[q] = node();
    }
    return;
  }
  void add(int i, int l, int r, int x, int v, int typ) {
    if (l == r) {
      if (typ == 0) {
        tree[i] = node(v);
      } else {
        tree[i] = node();
      }
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
      add(i * 2, l, mid, x, v, typ);
    else
      add(i * 2 + 1, mid + 1, r, x, v, typ);
    tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
    return;
  }
  long long sum() { return tree[1].sum[2]; }
};
int N, a[100000][2];
set<int> heap;
segment_tree seg;
map<int, int> ind;
int main() {
  fscanf(in, "%d", &N);
  for (int q = 0; q < N; q++) {
    char qq[22];
    int x;
    fscanf(in, "%s", qq);
    if (qq[0] == 's') {
      a[q][0] = -1;
    } else {
      fscanf(in, "%d", &x);
      if (qq[0] == 'a')
        a[q][0] = 0;
      else
        a[q][0] = 1;
      a[q][1] = x;
      heap.insert(x);
    }
  }
  int cind = 0;
  for (set<int>::iterator it = heap.begin(); it != heap.end(); it++) {
    ind[*it] = cind;
    cind++;
  }
  for (int q = 0; q < N; q++) {
    if (a[q][0] == -1) {
      printf("%lld\n", seg.sum());
    } else {
      seg.add(1, 0, cind - 1, ind[a[q][1]], a[q][1], a[q][0]);
    }
  }
  return 0;
}
