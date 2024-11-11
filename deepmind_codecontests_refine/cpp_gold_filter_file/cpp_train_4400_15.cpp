#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int Arr[n];
  for (int i = 0; i < n; i++) {
    Arr[arr[i] - 1] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", Arr[i]);
  }
  return 0;
}
