#include <bits/stdc++.h>
int main() {
  int i = 1, j, k, minindex;
  char str[100], temp, minvalue;
  scanf("%s", str);
  i = strlen(str);
  for (k = 0; k < i; k += 2) {
    minvalue = str[k];
    minindex = k;
    for (j = k; j < i; j += 2) {
      if (str[j] < minvalue) {
        minvalue = str[j];
        minindex = j;
      }
    }
    temp = str[minindex];
    str[minindex] = str[j];
    str[j] = temp;
  }
  printf("%s", str);
  return 0;
}
