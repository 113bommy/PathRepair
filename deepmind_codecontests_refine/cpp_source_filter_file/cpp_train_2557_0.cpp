#include <bits/stdc++.h>
using namespace std;
int parent[1000005];
void init() {
  for (int i = 0; i < 1000005; i++) {
    parent[i] = -1;
  }
}
int find(int n) {
  if (parent[n] < 0) {
    return n;
  } else {
    return parent[n] = find(parent[n]);
  }
}
void connect(int a, int b) {
  int x = find(a);
  int y = find(b);
  parent[x] += parent[y];
  parent[y] = x;
}
bool isConnect(int a, int b) {
  int x = find(a);
  int y = find(b);
  if (x == y) {
    return true;
  } else {
    return false;
  }
}
int node[1000005];
int lft[1000005];
int main() {
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    init();
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (isConnect(a, b) == false) {
        connect(a, b);
      }
    }
    int numN = 0;
    for (int i = 1; i <= n; i++) {
      if (parent[i] < 0) {
        node[numN++] = -parent[i];
      }
    }
    sort(node, node + numN, greater<int>());
    for (int i = 0; i < numN; i++) {
      lft[i] = min(node[i], k);
    }
    if (k == 1) {
      printf("%d\n", numN - 2);
    } else {
      int degree = 0;
      for (int i = 0; i < numN; i++) {
        degree += lft[i];
      }
      int p = degree / 2 + 1;
      if (p >= numN) {
        puts("0");
      } else {
        printf("%d\n", numN - p);
      }
    }
  }
  return 0;
}
