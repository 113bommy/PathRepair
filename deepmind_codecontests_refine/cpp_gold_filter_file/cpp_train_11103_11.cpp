#include <bits/stdc++.h>
char s[2231231];
int main() {
  int ans = 0;
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; s[i]; i++) {
    if (s[i] == 'U' && s[i + 1] == 'R' || s[i] == 'R' && s[i + 1] == 'U')
      ans++, i++;
    else
      ans++;
  }
  printf("%d\n", ans);
}
