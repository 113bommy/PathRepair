#include <bits/stdc++.h>
int main() {
  char arr[1001];
  int arr2[26] = {0}, a, count = 0;
  scanf("%[^\n]%*c", arr);
  int k = strlen(arr);
  for (int i = 0; i < k; i++) {
    a = arr[i] - 96;
    if (a > 0 && a <= 26) {
      if (arr2[a] == 0) {
        arr2[a] = 1;
        count++;
      }
    }
  }
  printf("%d\n", count);
}
