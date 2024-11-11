#include <bits/stdc++.h>
int main() {
  int n;
  char line[2001], result[2001] = {'0'};
  scanf(" %d", &n);
  getchar();
  gets(line);
  int len = strlen(line);
  int p = 0;
  if (len % 2 == 0 && len > 2) {
    int i = n, j = n;
    while (p <= len - 2) {
      result[i / 2 - 1] = line[p];
      result[(j + 2) / 2 - 1] = line[p + 1];
      i -= 2;
      j += 2;
      p += 2;
    }
    result[n - 1] = line[n - 1];
    int k = 0;
    for (k = 0; k < n; k++) printf("%c", result[k]);
    printf("\n");
  } else if (len % 2 != 0 && len > 2) {
    int i = n + 1, j = n - 1;
    while (p <= len - 2) {
      result[i / 2 - 1] = line[p];
      result[j / 2 - 1] = line[p + 1];
      i += 2;
      j -= 2;
      p += 2;
    }
    result[n - 1] = line[n - 1];
    int k = 0;
    for (k = 0; k < n; k++) printf("%c", result[k]);
    printf("\n");
  } else {
    int k = 0;
    for (k = 0; k < n; k++) printf("%c", line[k]);
    printf("\n");
  }
  return 0;
}
