#include <bits/stdc++.h>
using namespace std;
int len, i, b[100500], n, mx = -1, j;
char a[100500];
bool was[100500];
int main() {
  scanf("%s", a + 1);
  a[0] = '@';
  len = strlen(a) - 1;
  for (i = 1; i <= len; i++) b[i] = i;
  if (len <= 0) {
    printf("0");
    exit(0);
  }
  for (i = 1; i <= len; i++) {
    if (a[i] == ')' && a[b[i - 1]] == '(') {
      was[b[i - 1]] = true;
      was[i] = was[b[i - 1]] = true;
      b[b[i - 1]] = b[b[i - 1] - 1];
      b[i] = b[b[i - 1]];
    }
    if (a[i] == ']' && a[b[i - 1]] == '[') {
      was[b[i - 1]] = true;
      was[i] = was[b[i - 1]] = true;
      b[b[i - 1]] = b[b[i - 1] - 1];
      b[i] = b[b[i - 1]];
    }
  }
  n = 0;
  for (i = 1; i <= len; i++) {
    while (was[i] == true) {
      if (a[i] == '[') n++;
      i++;
    }
    if (n > mx) mx = n;
    n = 0;
  }
  for (i = 1; i <= len; i++) {
    while (was[i] == true) {
      if (a[i] == '[') n++;
      i++;
    }
    if (n == mx) {
      printf("%d\n", mx);
      i--;
      while (was[i] == true) i--;
      i++;
      while (was[i] == true) {
        printf("%c", a[i]);
        i++;
      }
      exit(0);
    }
    n = 0;
  }
  return 0;
}
