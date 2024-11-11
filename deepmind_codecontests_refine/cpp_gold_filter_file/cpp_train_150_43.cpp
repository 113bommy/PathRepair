#include <bits/stdc++.h>
int arr[105];
int main(void) {
  int n, ok = 0;
  char te;
  scanf("%d", &n);
  int c;
  c = n / 4;
  for (int k = 1; k <= n; k++) {
    scanf(" %c", &te);
    if (te == '*') arr[k] = 1;
  }
  for (int i = 1; i <= c; i++) {
    for (int j = 1; j + i * 4 <= n; j++) {
      if (arr[j] && arr[j + i] && arr[j + 2 * i] && arr[j + 3 * i] &&
          arr[j + 4 * i])
        ok = 1;
    }
  }
  if (ok)
    printf("yes");
  else
    printf("no");
}
