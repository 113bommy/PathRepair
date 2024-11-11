#include <bits/stdc++.h>
int main(void) {
  int n, i;
  char str[210] = {0};
  scanf("%d", &n);
  char *way = (char *)malloc(sizeof(char) * 11000);
  way[0] = '/';
  way[1] = '\0';
  char *ptr = way;
  char *tmp_ptr;
  getchar();
  for (i = 0; i < n; i++) {
    gets(str);
    if (memcmp(str, "pwd", 3) == 0) {
      if (way[1] == '\0')
        printf("%s", way);
      else
        printf("%s/", way);
      continue;
    } else if ((str[0] == 'c') && (str[1] == 'd') && (str[3] != '/')) {
      *ptr = '/';
      ptr++;
      *ptr = '\0';
    } else if ((str[0] == 'c') && (str[1] == 'd'))
      ptr = way;
    else
      break;
    memcpy(ptr, &str[3], strlen(str) - 3);
    *(ptr + strlen(str) - 3) = '\0';
    while (*ptr != '\0') {
      if ((*ptr == '.') && (*(ptr + 1) == '.')) {
        tmp_ptr = ptr - 2;
        while (*tmp_ptr != '/') tmp_ptr--;
        while ((*ptr != '/') && (*ptr != '\0')) ptr++;
        if (*ptr != '\0') {
          strcpy(tmp_ptr + 1, ptr + 1);
          ptr = tmp_ptr;
        } else {
          ptr = tmp_ptr;
          *ptr = '\0';
          break;
        }
      }
      ptr++;
    }
  }
  free(way);
  return 0;
}
