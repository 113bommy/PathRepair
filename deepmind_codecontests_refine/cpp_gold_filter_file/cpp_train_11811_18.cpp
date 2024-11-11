#include <bits/stdc++.h>
int arr[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int ep;
    scanf("%d", &ep);
    arr[ep] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 0) {
      printf("%d", i);
      break;
    }
  }
  return 0;
}
