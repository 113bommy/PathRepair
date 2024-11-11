#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  int p[n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j] == i + 1) p[i] = j + 1;
    }
  }
  for (int i = 0; i < n; i++) printf("%d", p[i]);
  return 0;
}
