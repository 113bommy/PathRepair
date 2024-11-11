#include <bits/stdc++.h>
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a <= 2 || a + 1 >= n || b <= 2 || b + 1 >= m) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}
