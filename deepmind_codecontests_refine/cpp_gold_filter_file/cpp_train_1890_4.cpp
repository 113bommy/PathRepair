#include <bits/stdc++.h>
using namespace std;
char str[100005], str1[100005], str2[100005];
int main() {
  scanf("%s", str + 1);
  int len = strlen(str + 1), k = 0;
  for (int i = 1; i <= len; i++) {
    if (str[i] != 'a') str1[++k] = str[i];
  }
  if (k % 2)
    printf(":(\n");
  else {
    if (k == 0) {
      printf("%s\n", str + 1);
      return 0;
    }
    for (int i = len - k / 2 + 1; i <= len; i++)
      if (str[i] == 'a') {
        printf(":(\n");
        return 0;
      }
    for (int i = 1; i <= k / 2; i++) str2[i] = str1[i];
    if (!strcmp(str2 + 1, str1 + 1 + k / 2)) {
      for (int i = 1; i <= len - k / 2; i++) printf("%c", str[i]);
      printf("\n");
    } else {
      printf(":(\n");
    }
  }
  return 0;
}
