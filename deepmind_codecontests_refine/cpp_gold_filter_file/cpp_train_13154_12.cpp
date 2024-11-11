#include <bits/stdc++.h>
int main() {
  char c[1000];
  scanf("%s", c);
  int a[26] = {0};
  for (int i = 0; i < strlen(c); i++) {
    a[c[i] - 'a'] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    if (a[i]) cnt++;
  }
  if (cnt % 2 == 0) {
    printf("CHAT WITH HER!");
  } else
    printf("IGNORE HIM!");
  return 0;
}
