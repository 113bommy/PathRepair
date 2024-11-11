#include <bits/stdc++.h>
char num[(1000002)];
int arr[2][(1000002)];
int main(void) {
  int len;
  scanf("%d", &len);
  scanf(" %s", num + 1);
  for (int i = 1; i <= len; i++) {
    arr[0][i] = arr[0][i - 1];
    arr[1][i] = arr[1][i - 1];
    if (num[i] != '?') {
      if (num[i] == '1')
        arr[0][i] = i;
      else
        arr[1][i] = i;
    }
  }
  for (int i = 1; i <= len; i++) {
    int start = 0;
    int ans = 0;
    while (i + start <= len) {
      if (arr[0][start] == arr[0][i + start] ||
          arr[1][start] == arr[1][i + start]) {
        start += i;
        ans++;
      } else {
        start = arr[0][i + start] > arr[1][i + start] ? arr[0][i + start]
                                                      : arr[1][i + start];
      }
    }
    printf("%d ", ans);
  }
  return 0;
}
