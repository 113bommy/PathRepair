#include <bits/stdc++.h>
using namespace std;
int v[1007][1007];
int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  if (a != 1 && b != 1) {
    printf("NO\n");
    return 0;
  } else if (b == 1) {
    if (a == 1 && (n == 3 || n == 2)) {
      printf("NO\n");
      return 0;
    }
    for (int i = 1; i <= n - a; i++) {
      v[i][i + 1] = v[i + 1][i] = 1;
    }
  } else if (a == 1) {
    for (int i = 1; i < b; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        v[i][j] = v[j][i] = 1;
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d", v[i][j]);
    printf("\n");
  }
  return 0;
}
