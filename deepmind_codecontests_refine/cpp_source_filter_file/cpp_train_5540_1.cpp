#include <bits/stdc++.h>
int main() {
  char s[1000000 + 1];
  scanf("%s", s);
  int n = strlen(s), k = 0, l[1000000] = {0};
  for (int i = 1; i < n; i++) {
    while (k > 0 && s[k] != s[i]) k = l[k - 1];
    if (s[k] == s[i]) k++;
    l[i] = k;
  }
  if (l[n - 1] == 0) {
    puts("Just a legend");
    return 0;
  }
  for (int i = 0; i < n - 1; i++)
    if (l[i] == l[n - 1]) {
      s[l[i]] = '\0';
      puts(s);
      return 0;
    }
  if (l[l[n - 1]] == 0) {
    puts("Just a legend");
    return 0;
  }
  s[l[l[n - 1]]] = '\0';
  puts(s);
  return 0;
}
