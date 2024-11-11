#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  int i;
  for (i = 0; i < t; i++) {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    int j;
    for (j = 0; j < n; j++) scanf("%d", &arr[j]);
    for (j = 0; j < n; j++) {
      int l;
      for (l = j + 1; l < n; l++) {
        if (arr[j] > arr[l]) {
          int a;
          a = arr[j];
          arr[j] = arr[l];
          arr[l] = a;
        }
      }
    }
    long long int answer = 0;
    for (j = 0; j < n - 2 * k; j++) answer = answer + arr[j];
    int count = 1;
    for (j = n - 2 * k + 1; j < n; j++) {
      if (arr[j] == arr[j - 1]) {
        count++;
        if (count > k) {
          for (j = j + 1; j < n; j++) {
            if (arr[j] == arr[j - 1])
              count++;
            else
              break;
          }
          break;
        }
      } else
        count = 1;
    }
    if (count > k && k > 0) answer = answer + count - k;
    printf("%lld\n", answer);
  }
  return 0;
}
