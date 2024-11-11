#include <bits/stdc++.h>
using namespace std;
int v[1010];
int main() {
  int n, A, B, C, T;
  scanf("%d%d%d%d%d", &n, &A, &B, &C, &T);
  for (int i = 1; i <= n; i++) scanf("%d", v + i);
  if (C - B > 0) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += C * (T - v[i]) + (A - B * (T - v[i]));
    printf("%d\n", sum);
  } else {
    printf("%d\n", n * A);
  }
  return 0;
}
