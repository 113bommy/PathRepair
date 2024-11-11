#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, arr[20010], ans[20010], offset = 0;
  memset(arr, 0, sizeof(arr));
  int temp;
  scanf("%d %d %d", &n, &m, &k);
  arr[1] = k;
  arr[n + 1] = -k;
  ans[offset++] = 1;
  for (int i = 2; i <= k; i++) ans[offset++] = 1;
  arr[0] = 0;
  for (int i = 1; i <= n + m; i++) {
    arr[i] = arr[i - 1] + arr[i];
    temp = arr[i + 1] + arr[i];
    if (temp == 0) {
      ans[offset++] = i;
      arr[i] += 1;
      arr[i + n] += -1;
    }
    if (arr[i] < k) {
      ans[offset++] = i;
      for (int l = arr[i] + 1; l < k; l++) ans[offset++] = i;
      arr[i + n] += -1 * (k - arr[i]);
      arr[i] = k;
    }
  }
  printf("%d\n", offset);
  for (int i = 0; i < offset - 1; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[offset - 1]);
  return 0;
}
