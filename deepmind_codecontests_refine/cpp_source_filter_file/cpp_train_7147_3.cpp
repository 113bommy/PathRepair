#include <bits/stdc++.h>
using namespace std;
int arr[100006];
int arr2[100006];
int main() {
  int n, k, sum = 0, mx = 0, ans = 0;
  scanf("%d %d", &n, &k);
  int arr3[100006], j = 0;
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  for (int i = 0; i < k; i++) {
    scanf("%d", &arr2[i]);
    sum += ((!arr2[i]) * arr[i]);
    ans += arr[i] * arr2[i];
  }
  arr3[j++] = sum;
  for (int i = k; i < n; i++) {
    scanf("%d", &arr2[i]);
    ans += arr[i] * arr2[i];
    sum += ((!arr2[i]) * arr[i]) - ((!arr2[i - k]) * arr[i - k]);
    arr3[j++] = sum;
  }
  for (int i = 0; i <= k + 1; i++) {
    mx = (arr3[i] > mx) ? arr3[i] : mx;
  }
  printf("%d", mx + ans);
}
