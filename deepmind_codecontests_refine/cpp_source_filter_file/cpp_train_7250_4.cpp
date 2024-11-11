#include <bits/stdc++.h>
using namespace std;
const int muler[4] = {1, 2, 4, 8};
int n;
struct Node {
  int val, a, k, b;
  Node() {}
  Node(int _v, int _a, int _k, int _b) : val(_v), a(_a), k(_k), b(_b) {}
} node[30];
int lit;
void print() {
  printf("%d\n", lit);
  for (int i = 2; i <= lit; i++) {
    printf("lea e%cx, [", char(i - 1 + 'a'));
    if (node[i].a) printf("e%cx + ", node[i].a - 1 + 'a');
    if (node[i].k) printf("%d*", muler[node[i].k]);
    printf("e%cx]\n", node[i].b - 1 + 'a');
  }
  exit(0);
}
void dfs(int k) {
  if (k == lit) {
    if (node[k].val == n) print();
    return;
  }
  for (int i = 0; i <= k; i++)
    for (int j = 1; j <= k; j++)
      for (int t = 0; t < 4; t++) {
        int val = node[i].val + muler[t] * node[j].val;
        if (val <= node[k].val || val > n) continue;
        node[k + 1] = Node(val, i, t, j);
        dfs(k + 1);
      }
  return;
}
int main() {
  node[0] = Node(0, 0, 0, 0);
  node[1] = Node(1, 0, 0, 0);
  scanf("%d", &n);
  for (lit = 1;; lit++) dfs(1);
  return 0;
}
