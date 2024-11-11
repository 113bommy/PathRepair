#include <bits/stdc++.h>
const int MAX = 262144;
int arr[262144];
int hold;
typedef struct Tree {
  int maxv;
} Tree;
Tree T[262144];
int max2(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int max3(int a, int b, int c) {
  int temp = max2(a, b);
  int temp1 = max2(temp, c);
  return temp1;
}
int build_tree(int node, int a, int b) {
  if (a == b) {
    T[node].maxv = arr[a];
    return 1;
  }
  int m = (a + b) / 2;
  hold = build_tree(2 * node, a, m);
  hold = build_tree(2 * node + 1, m + 1, b);
  if (hold == 1) {
    T[node].maxv = T[2 * node].maxv | T[2 * node + 1].maxv;
    return 0;
  } else if (hold == 0) {
    T[node].maxv = T[2 * node].maxv ^ T[2 * node + 1].maxv;
    return 0;
  }
}
int update(int node, int a, int b, int x, int y) {
  if (a == b && a == x) {
    T[node].maxv = y;
    return 1;
  }
  int m = (a + b) / 2;
  if (x <= m)
    hold = update(2 * node, a, m, x, y);
  else
    hold = update(2 * node + 1, m + 1, b, x, y);
  if (hold == 1) {
    T[node].maxv = T[2 * node].maxv | T[2 * node + 1].maxv;
    return 0;
  } else if (hold == 0) {
    T[node].maxv = T[2 * node].maxv ^ T[2 * node + 1].maxv;
    return 1;
  }
}
int main() {
  int N, i;
  Tree res;
  int M, n, x, y;
  scanf("%d%d", &N, &M);
  N = 1 << N;
  for (i = 0; i < N; i++) scanf("%d", &arr[i]);
  int jiten = build_tree(1, 0, N - 1);
  for (i = 0; i < M; i++) {
    scanf("%d%d", &x, &y);
    int jiten1 = update(1, 0, N - 1, x - 1, y);
    printf("%d\n", T[1].maxv);
  }
  return 0;
}
