#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
int a[5], b[5], c[5], d[5];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 4; i++) {
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
  }
  for (int i = 0; i < 4; i++) {
    if (min(a[i], b[i]) + min(c[i], d[i]) <= n) {
      printf("%d %d %d\n", i + 1, min(a[i], b[i]), n - min(a[i], b[i]));
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
