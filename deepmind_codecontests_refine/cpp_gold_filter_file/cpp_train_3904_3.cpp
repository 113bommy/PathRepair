#include <bits/stdc++.h>
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a <= 5 || a + 4 >= n || b <= 5 || b + 4 >= m) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}
