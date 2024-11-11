#include <bits/stdc++.h>
bool flag[50];
char s[10];
int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    flag[i] = strcmp(s, "half");
  }
  double ans = flag[n - 1] ? 0.5 : 1;
  int count = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (flag[i]) {
      ans += count + 0.5;
      count = 2 * count + 1;
    } else {
      ans += count;
      count *= 2;
    }
  }
  printf("%.0lf\n", ans * p);
  return 0;
}
