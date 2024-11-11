#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, d;
int main() {
  scanf("%d %d %d %d %d %d", &n, &m, &a, &b, &c, &d);
  if (m <= n || n <= 4) {
    printf("-1");
    return 0;
  }
  for (int i = 0; i < 2; i++) {
    printf("%d %d ", a, c);
    for (int j = 1; j <= n; j++) {
      if (j != a && j != b && j != c && j != d) printf("%d ", j);
    }
    printf("%d %d\n", b, d);
    swap(a, c);
    swap(b, d);
  }
}
