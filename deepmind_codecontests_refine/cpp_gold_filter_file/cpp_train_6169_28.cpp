#include <bits/stdc++.h>
int main() {
  int t, tc;
  scanf("%d", &t);
  for (tc = 0; tc < t; tc++) {
    int n;
    scanf("%d", &n);
    if (n % 4 == 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
