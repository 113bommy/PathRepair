#include <bits/stdc++.h>
char dir[51];
int main() {
  scanf("%s", dir);
  char *dr = dir;
  if (*dr == 'h') {
    printf("http://");
    dr += 4;
  } else {
    printf("ftp://");
    dr += 3;
  }
  char *ru = strstr(dr, "ru");
  char *nru = strstr(ru + 1, "ru");
  if (nru) ru = nru;
  char format[10];
  sprintf(format, "%%.%ds.ru", ru - dr);
  printf(format, dr);
  ru += 2;
  if (ru) printf("/%s", ru);
  printf("\n");
  return 0;
}
