#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
int arr[1001], d[1001];
int n, k, x, ans;
int main() {
  setlocale(0, "");
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i < n - 1; i++) {
    if (arr[i - 1] + arr[i] >= k)
      continue;
    else {
      ans += (k - arr[i - 1] - arr[i]);
      arr[i] += (k - arr[i - 1] - arr[i]);
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
};
