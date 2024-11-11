#include <bits/stdc++.h>
int main() {
  char c[100005], tmp[100005];
  int j = 0;
  scanf("%[^\n]", c);
  for (int i = 0; i < strlen(c); i++) {
    if (c[i] >= 'a' && c[i] <= 'z') {
      tmp[j] = c[i];
      j++;
    } else if (c[i] == ' ' && c[i + 1] == ' ') {
      continue;
    } else if (c[i] == ' ' && (c[i + 1] >= 'a' && c[i + 1] <= 'z')) {
      tmp[j] = c[i];
      j++;
    } else if (c[i] == ' ' && (c[i + 1] < 'a') && c[i + 1] != ' ') {
      continue;
    } else if (c[i] != ' ' && c[i] < 'a' && c[i + 1] != ' ') {
      tmp[j] = c[i];
      tmp[j + 1] = ' ';
      j += 2;
    } else if (c[i] != ' ' && c[i] < 'a' && c[i + 1] == ' ') {
      tmp[j] = c[i];
      j++;
    }
  }
  printf("%s", tmp);
  return 0;
}
