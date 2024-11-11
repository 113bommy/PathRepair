#include <bits/stdc++.h>
using namespace std;
int A[110];
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    for (int k = a; k <= b; k++) {
      A[k] = 1;
    }
  }
  int b[110];
  int ans = 0;
  int q = 0;
  for (int i = 1; i <= m; i++) {
    if (A[i] == 0) {
      ans++;
      b[q] = i;
      q++;
    }
  }
  printf("%d", ans);
  printf("\n");
  for (int i = 0; i < q; i++) {
    printf("%d ", b[i]);
  }
  return 0;
}
