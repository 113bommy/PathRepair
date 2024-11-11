#include <bits/stdc++.h>
int main() {
  char s[200009];
  int n;
  scanf("%d", &n);
  scanf("%s", &s);
  int i, cnt = 0, j;
  for (i = 0; i < n - 1; i += 2) {
    if (s[i] == 'a' && s[i + 1] != 'b') {
      cnt++;
      s[i + 1] = 'b';
    } else if (s[i] == 'b' && s[i + 1] != 'a') {
      cnt++;
      s[i + 1] = 'a';
    }
  }
  printf("%d\n%s\n", cnt, s);
  return 0;
}
