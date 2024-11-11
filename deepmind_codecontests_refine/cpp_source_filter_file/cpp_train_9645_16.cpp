#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int arr[700];
  for (int i = 0; i < 700; i++) arr[i] = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    arr[a] = 1;
  }
  int count = 0;
  for (int i = n - 1; i > 0; i--) {
    count += arr[i];
  }
  printf("%d\n", count);
  return 0;
}
