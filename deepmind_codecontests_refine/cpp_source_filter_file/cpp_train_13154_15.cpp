#include <bits/stdc++.h>
int main() {
  char s[100];
  int i, j, a = 0, n;
  scanf("%s", &s);
  n = strlen(s);
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (s[i] == s[j]) s[j] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    if (s[i] == 0) {
      a++;
    }
  }
  n = n - a;
  if (n % 2 == 0) {
    printf("CHAT WITH HER!");
  } else {
    printf("\tIGNORE HIM!");
  }
  return 0;
}
