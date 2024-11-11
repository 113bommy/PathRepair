#include <bits/stdc++.h>
char s[400005];
int v[400005], k, len;
bool possible() {
  int j;
  for (j = 0; j < k - 1; j++) {
    if (v[j + 1] - v[j] < 2 || v[j + 1] - v[j] > 11) return 1;
  }
  if (v[0] > 8) return 1;
  if (len - v[j] > 4) return 1;
  return 0;
}
int main() {
  scanf("%s", s);
  k = 0;
  int dif, j, b, i;
  len = strlen(s);
  for (i = 0; s[i]; i++) {
    if (s[i] == '.') v[k++] = i;
  }
  if (k == 0 || v[0] == 0 || v[k - 1] == len - 1 || possible()) {
    printf("NO\n");
    return 0;
  } else {
    printf("YES\n");
    for (i = 0; i < v[0]; i++) printf("%c", s[i]);
    j = 0;
    while (j < k - 1) {
      dif = v[j + 1] - v[j];
      if (dif < 5) {
        for (b = v[j]; b < v[j + 1] - 1; b++) printf("%c", s[b]);
        printf("\n%c", s[b]);
      } else {
        for (b = 0; b < 4; b++) printf("%c", s[b + v[j]]);
        printf("\n");
        for (b = 4; b < dif; b++) printf("%c", s[b + v[j]]);
      }
      j++;
    }
    for (i = v[k - 1]; s[i]; i++) printf("%c", s[i]);
    printf("\n");
  }
  return 0;
}
