#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  int count = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  bool a[100001];
  bool b[100001];
  for (int i = 0; i < 100000; i++) {
    a[i] = 0;
    b[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] > 0 && a[arr[i]] != 1) {
      a[arr[i]] = 1;
      count++;
    } else if (arr[i] < 0 && b[abs(arr[i])] != 1) {
      b[abs(arr[i])] = 1;
      count++;
    }
  }
  printf("%d\n", count);
}
