#include <bits/stdc++.h>
char arr[5050];
char arr1[5050];
char out[5050];
int main() {
  int a, b, c;
  int k = 0;
  gets(arr);
  gets(arr1);
  int n = strlen(arr);
  for (int w = 0; w < n; w++) {
    if (arr[w] < arr1[w]) {
      printf("-1");
      return 0;
    } else if (arr[w] == arr1[w]) {
      out[k++] = arr[w] + 1;
    } else {
      out[k++] = arr1[w];
    }
  }
  puts(out);
}
