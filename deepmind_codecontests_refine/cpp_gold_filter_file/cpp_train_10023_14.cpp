#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, c, d;
    char s[4] = {"NO"}, s1[] = "YES";
    while (n--) {
      scanf("%d %d", &a, &b);
      scanf("%d %d", &c, &d);
      if (m % 2 == 0 && b == c) {
        strcpy(s, s1);
      }
    }
    printf("%s\n", s);
  }
  return 0;
}
