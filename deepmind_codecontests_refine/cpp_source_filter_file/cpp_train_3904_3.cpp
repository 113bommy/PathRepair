#include <bits/stdc++.h>
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a <= 4 || a + 3 >= n || b <= 4 || b + 3 >= m) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}
