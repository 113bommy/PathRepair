#include <bits/stdc++.h>
void maxf(char *p, int *j);
int main() {
  char a[1000000];
  int i = 0, j = 0;
  gets(a);
  while (j < strlen(a)) maxf(a, &j);
  while (a[i] != '\0') {
    if ((a[i] >= 'A') && (a[i] <= 'Z')) printf("%c", a[i] + 32);
    i++;
  }
  return (0);
}
void maxf(char *p, int *j) {
  int i = *j, l;
  char max = 'A';
  while (*(p + i) != '\0') {
    if (max < *(p + i)) {
      max = *(p + i);
      l = i;
    }
    if (max == *(p + i)) {
      l = i;
    }
    i++;
  }
  i = *j;
  *j = l + 1;
  while (*(p + i) != '\0') {
    if (max == *(p + i)) *(p + i) = *(p + i) - 32;
    i++;
  }
}
