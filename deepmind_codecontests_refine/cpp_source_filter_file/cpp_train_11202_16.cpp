#include <bits/stdc++.h>
int main() {
  char first[27], second[27], s[1001], ans[1001];
  int i;
  scanf("%s", &first);
  scanf("%s", &second);
  scanf("%s", &s);
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      ans[i] = s[i];
    } else {
      for (int j = 0; first[j] != '\0'; j++) {
        if (s[i] == first[j]) {
          ans[i] = second[j];
        } else if (s[i] + 32 == first[j]) {
          ans[i] = second[j] - 32;
        }
      }
    }
  }
  ans[i + 1] = '\0';
  printf("%s", ans);
  return 0;
}
