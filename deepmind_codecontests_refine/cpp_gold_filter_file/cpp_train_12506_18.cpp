#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int m;
    char a[301];
    scanf("%d %s", &m, a);
    if (m == 2 && a[0] - '0' >= a[1] - '0')
      printf("NO\n");
    else {
      printf("YES\n2\n");
      printf("%c %s\n", a[0], a + 1);
    }
  }
  return 0;
}
