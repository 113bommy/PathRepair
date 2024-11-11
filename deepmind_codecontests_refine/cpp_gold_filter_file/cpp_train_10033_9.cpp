#include <bits/stdc++.h>
int main() {
  int arr[3001];
  for (int i = 0; i <= 3000; i++) arr[i] = 0;
  for (int i = 2; i <= 3000; i++) {
    if (arr[i] != 0) continue;
    for (int j = i; j <= 3000; j += i) {
      arr[j]++;
    }
  }
  int n;
  scanf("%d", &n);
  int result = 0;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 2) result++;
  printf("%d", result);
  return 0;
}
