#include <bits/stdc++.h>
int n, m;
int add(int x, int y) { return (x += y) < 1000000007 ? x : x - 1000000007; }
int mul(int x, int y) { return (int)((long long int)x * y % 1000000007); }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 2) m++;
  }
  int res = 1;
  while (m--) {
    res = mul(res, n);
    n--;
  }
  int A = 1, B = 2;
  for (int i = 2; i <= n; i++) {
    int C = add(B, mul(A, n - 1));
    A = B;
    B = C;
  }
  printf("%d\n", mul(A, res));
  return 0;
}
