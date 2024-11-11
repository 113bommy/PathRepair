#include <bits/stdc++.h>
using namespace std;
char a[100000];
int b[27];
int check() {
  int j, k = 0;
  for (j = 0; j < 26; j++) {
    if (b[j] > 1)
      return 0;
    else if (b[j] == 0)
      k++;
  }
  return 1;
}
int update(int i) {
  int j, k;
  for (j = i; j < i + 26; j++) {
    if (a[j] == '?') {
      for (k = 0; k < 26; k++)
        if (b[k] == 0) {
          a[j] = k + 'A';
          b[k] = 1;
          break;
        }
    }
  }
  for (j = 0; a[j] != '\0'; j++)
    if (a[j] == '?') a[j] = 'A';
}
int main() {
  int i, j, k, l = 1;
  int n, c;
  int found;
  for (i = 0; i < 27; i++) b[i] = 0;
  scanf("%s", a);
  n = strlen(a);
  if (n < 26) {
    printf("-1\n");
    return 0;
  }
  for (j = 0; j < 26; j++)
    if (a[j] == '?')
      b[26]++;
    else
      b[a[j] - 'A']++;
  found = 0;
  for (i = 0; a[i + 25] != '\0'; i++) {
    if (check()) {
      found = 1;
      break;
    }
    if (a[i] == '?')
      b[26]--;
    else
      b[a[i] - 'A']--;
    if (a[i + 26] == '?')
      b[26]++;
    else if (a[i + 26] != '\0')
      b[a[i + 26] - 'A']--;
  }
  if (found) {
    update(i);
    for (i = 0; i < n; i++) printf("%c", a[i]);
    printf("\n");
  } else
    printf("-1\n");
  return 0;
}
