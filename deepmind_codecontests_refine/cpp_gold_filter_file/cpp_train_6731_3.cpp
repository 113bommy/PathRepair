#include <bits/stdc++.h>
using namespace std;
int a[105], b[105], c[105];
int main() {
  int n, m, sum = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
    sum += b[i];
  }
  for (int i = 1; i <= n - sum + 1; ++i) {
    memset(c, 0, sizeof c);
    for (int j = i; j < i + sum; ++j) {
      c[a[j]]++;
    }
    bool ok = 1;
    for (int j = 1; j <= m; ++j) {
      if (c[j] != b[j]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}
