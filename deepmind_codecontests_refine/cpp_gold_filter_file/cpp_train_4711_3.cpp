#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, test;
  scanf("%d", &test);
  for (t = 0; t < test; t++) {
    int i, j, n, m, result, arr[50];
    scanf("%d", &n);
    for (m = 0; m < n; m++) {
      scanf("%d", &arr[m]);
    }
    sort(arr, arr + n);
    i = INT_MAX;
    for (m = 0; m < n - 1; m++) {
      result = arr[m + 1] - arr[m];
      i = (min(result, i));
    }
    printf("%d\n", i);
  }
  return 0;
}
