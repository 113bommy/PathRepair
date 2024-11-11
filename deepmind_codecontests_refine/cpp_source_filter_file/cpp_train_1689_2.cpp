#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    char p[101], h[101];
    scanf("%s %s", p, h);
    int counterP[26] = {0}, counterH[26] = {0}, lastChar = strlen(p), flag;
    for (int j = 0; p[j] != '\0'; j++) counterP[p[j] - 'a']++;
    for (int j = 0, k = lastChar - 1; h[k] != '\0'; j++, k++) {
      flag = 1;
      for (int a = j; a <= k; a++) {
        counterH[h[a] - 'a']++;
      }
      for (int a = 0; a < 26; a++) {
        if (counterP[a] != counterH[a]) {
          flag = 0;
          break;
        }
      }
      if (flag)
        break;
      else {
        for (int a = 0; a < 26; a++) counterH[a] = 0;
      }
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
