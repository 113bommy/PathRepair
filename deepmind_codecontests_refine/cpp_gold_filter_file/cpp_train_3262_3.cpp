#include <bits/stdc++.h>
int main() {
  int n, b;
  scanf("%d%d", &n, &b);
  int arr[n], flag = 0;
  double result[n];
  int long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }
  double total = b + sum;
  double each = total / n;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > each) {
      flag = 1;
      break;
    }
    result[i] = each - arr[i];
  }
  if (!flag) {
    for (int i = 0; i < n; ++i) {
      printf("%f\n", result[i]);
    }
  } else
    printf("%d", -1);
  return 0;
}
