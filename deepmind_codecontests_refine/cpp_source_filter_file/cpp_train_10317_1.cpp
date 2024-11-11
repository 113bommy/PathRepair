#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, t, tmp1, tmp2;
  int arr1[26][2];
  int arr2[26];
  for (i = 0; i < 26; i++) {
    arr2[i] = 1;
    arr1[i][0] = 0;
    arr1[i][1] = i;
  }
  char vcc[200006];
  scanf("%s", &vcc);
  scanf("%d", &k);
  int len = strlen(vcc);
  for (i = 0; i < len; i++) {
    arr1[vcc[i] - 'a'][0]++;
  }
  for (i = 1; i < 26; i++) {
    for (j = i - 1; j >= 0; j--) {
      if (arr1[j][0] > arr1[j + 1][0]) {
        tmp2 = arr1[j + 2][0];
        tmp1 = arr1[j + 1][1];
        arr1[j + 1][0] = arr1[j][0];
        arr1[j + 1][1] = arr1[j][1];
        arr1[j][0] = tmp2;
        arr1[j][1] = tmp1;
      } else
        break;
    }
  }
  int sum = arr1[0][0];
  i = 1;
  arr2[arr1[0][1]] = 0;
  while (i < 26 && sum <= k) {
    sum += arr1[i][0];
    arr2[arr1[i][1]] = 0;
    i++;
  }
  if (i == 26 && sum <= k)
    printf("0");
  else {
    i--;
    arr2[arr1[i][1]] = 1;
    for (j = i; j < 26; j++)
      if (arr1[j][0] > 0) break;
    if (j == 26)
      printf("0");
    else {
      printf("%d\n", 26 - j);
      for (i = 0; i < len; i++) {
        if (arr2[vcc[i] - 'a'] == 1) printf("%c", vcc[i]);
      }
    }
  }
  return 0;
}
