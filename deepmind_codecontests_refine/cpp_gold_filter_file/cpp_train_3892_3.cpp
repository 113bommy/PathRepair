#include <bits/stdc++.h>
int main() {
  char a[1000];
  scanf("%s", a);
  int arr[26] = {0}, j, n, count = 0;
  for (j = 0; j < strlen(a); j++) {
    arr[a[j] - 'a'] = arr[a[j] - 'a'] + 1;
  }
  for (j = 0; j < 26; j++) {
    if (arr[j] % 2 != 0) {
      count++;
    }
  }
  if (count == 0 || count % 2 != 0) {
    printf("First\n");
  } else {
    printf("Second\n");
  }
  return 0;
}
