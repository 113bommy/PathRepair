#include <bits/stdc++.h>
char s[300010];
int main() {
  int n, l = 0, r = 0;
  scanf("%d", &n);
  scanf("%s", &s);
  char max = s[0];
  for (int i = 0; i < n; i++) {
    if (s[i] < max) {
      r = i + 1;
      printf("YES\n");
      printf("%d %d\n", l, r);
      return 0;
    }
    if (s[i] > max) {
      max = s[i];
      l = i + 1;
    }
  }
  printf("NO\n");
  return 0;
}
