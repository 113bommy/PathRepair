#include <bits/stdc++.h>
using namespace std;
struct Node {
  int k1, k2, i;
} node[105];
bool cmp1(const Node& a, const Node& b) { return a.k1 < b.k1; }
bool cmp2(const Node& a, const Node& b) { return a.i < b.i; }
int main() {
  int n, w;
  scanf("%d%d", &n, &w);
  for (int i = 0; i < n; i++) {
    scanf("%d", &node[i].k1);
    node[i].i = i;
  }
  sort(node, node + n, cmp1);
  for (int i = 0; i < n; i++) {
    int f = node[i].k1 / 2;
    if (node[i].k1 & 1) f++;
    node[i].k2 = f;
    w -= f;
  }
  if (w < 0) {
    puts("-1");
    return 0;
  }
  for (int i = n - 1; i >= 0 && w; i--) {
    if (w >= node[i].k1 - node[i].k2) {
      w -= node[i].k1 - node[i].k2;
      node[i].k2 = node[i].k2;
    } else {
      node[i].k2 += w;
      w = 0;
    }
  }
  sort(node, node + n, cmp2);
  for (int i = 0; i < n; i++) {
    if (i)
      printf(" %d", node[i].k2);
    else
      printf("%d", node[i].k2);
  }
  puts("");
  return 0;
}
