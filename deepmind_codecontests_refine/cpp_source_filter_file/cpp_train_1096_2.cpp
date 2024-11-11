#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int m = -1, ma = -1;
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    if (num == n) ma = i;
    if (num == 1) m = i;
  }
  int bg = ma > m ? ma : m;
  int sm = ma < m ? ma : m;
  int a = (n - (sm + 1));
  int b = (bg - 1);
  int ans = a > b ? a : b;
  printf("%d\n", ans);
  return 0;
}
