#include <bits/stdc++.h>
char arr[100];
int record[100], bullyean, dafuq;
void solu() {
  if (record[0] != 1) {
    arr[0] = arr[0] - ' ';
  } else
    arr[0] = arr[0] + ' ';
  for (int i = 1; i < strlen(arr); i++) {
    if (record[i] == 1) {
      arr[i] = arr[i] + ' ';
    }
  }
  printf("%s\n", arr);
  dafuq = 1;
}
int main() {
  scanf("%[^\n]", arr);
  for (int i = 0; i < strlen(arr); i++) {
    if (int(arr[i]) > 96) bullyean = 1;
  }
  for (int i = 0; i < strlen(arr); i++) {
    if (int(arr[i]) > 96)
      record[i] = 0;
    else
      record[i] = 1;
  }
  if (bullyean == 0)
    solu();
  else if (dafuq == 0 && record[0] == 0 && bullyean == 0) {
    solu();
  } else
    printf("%s\n", arr);
  return 0;
}
