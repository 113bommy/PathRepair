#include <bits/stdc++.h>
using namespace std;
FILE *in;
FILE *out;
struct Edge {
  int lo, hi, prc;
};
int n, all, flow, cur;
int cap[16];
Edge edges[16][16];
void recurse(int node, int next, int price) {
  if (node == n - 1) {
    if (cap[node] == flow) cur = max(cur, price);
    return;
  }
  if (next >= n) {
    if (cap[node] == 0) recurse(node + 1, node + 2, price);
  } else {
    for (int i = edges[node][next].lo; i <= edges[node][next].hi; i++) {
      if (cap[node] < i) break;
      cap[node] -= i;
      cap[next] += i;
      int nprice = price + i * i;
      if (i > 0) nprice += edges[node][next].prc;
      recurse(node, next + 1, nprice);
      cap[node] += i;
      cap[next] -= i;
    }
  }
}
int eval() {
  for (int i = 0; i < n; i++) cap[i] = 0;
  cap[0] = flow;
  cur = -1;
  recurse(0, 1, 0);
  return cur;
}
int main(void) {
  in = stdin;
  out = stdout;
  fscanf(in, "%d", &n);
  all = (n * (n - 1)) / 2;
  for (int i = 0; i < all; i++) {
    int n1, n2;
    fscanf(in, "%d %d", &n1, &n2);
    n1--;
    n2--;
    fscanf(in, "%d", &edges[n1][n2].lo);
    fscanf(in, "%d", &edges[n1][n2].hi);
    fscanf(in, "%d", &edges[n1][n2].prc);
  }
  int ans = -1, best = -1;
  for (flow = 1; flow <= 25; flow++) {
    best = eval();
    if (best != -1) {
      ans = flow;
      break;
    }
  }
  fprintf(out, "%d %d\n", ans, best);
  return 0;
}
