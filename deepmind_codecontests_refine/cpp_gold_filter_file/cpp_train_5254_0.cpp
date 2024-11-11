#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
const int M = 2e6 + 11;
int arr[N], brr[M];
int n;
int main() {
  while (scanf("%d", &n) == 1) {
    memset(brr, 0, sizeof(brr));
    for (int i = 0; i < n; ++i) {
      scanf("%d", &arr[i]);
      brr[arr[i]] = arr[i];
    }
    sort(arr, arr + n);
    int limit = arr[n - 1];
    for (int i = 1; i <= 2 * limit; ++i) {
      if (brr[i] != i) brr[i] = brr[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i != 0 && arr[i] == arr[i - 1]) continue;
      for (int j = arr[i] << 1; j <= 2 * limit + 1; j += arr[i]) {
        ans = max(ans, brr[j - 1] % arr[i]);
      }
    }
    printf("%d\n", ans);
  }
}
