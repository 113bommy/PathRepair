#include <bits/stdc++.h>
inline int A(int x, int y) { return x && y; }
inline int O(int x, int y) { return x ^ y; }
inline int X(int x, int y) { return x || y; }
int main() {
  int t1, t2, t3, t4;
  scanf("%d%d%d%d", &t1, &t2, &t3, &t4);
  int a1 = O(t1, t2);
  int a2 = X(t3, t4);
  int a3 = A(t2, t3);
  int a4 = O(t1, t4);
  int b1 = A(a1, a2);
  int b2 = X(a3, a4);
  int c1 = O(b1, b2);
  printf("%d", c1);
}
