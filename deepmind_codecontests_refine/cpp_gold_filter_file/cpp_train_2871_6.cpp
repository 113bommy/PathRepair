#include <bits/stdc++.h>
using namespace std;
int a[2000600];
int ans[2000600];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    int m = (n + 1) / 2;
    for (int i = 1; i <= m; i++) {
      if (i % 2 == 1) swap(a[i], a[n - i + 1]);
    }
    for (int i = 1; i <= n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
}
