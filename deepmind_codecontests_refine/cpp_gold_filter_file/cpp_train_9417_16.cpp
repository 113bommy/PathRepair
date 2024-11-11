#include <bits/stdc++.h>
using namespace std;
int arr[2000006], n, brr[2000006];
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    arr[j] = j;
  }
  int ans = 0;
  for (i = 1; i < 2000006; i++) brr[i] = max(arr[i], brr[i - 1]);
  for (i = 1; i < 2000006; i++) {
    if (arr[i]) {
      for (j = 2 * i; j < 2000006; j += i) {
        ans = max(ans, brr[j - 1] % arr[i]);
      }
    }
  }
  printf("%d", ans);
  return 0;
}
