#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int even_no = 0, odd_no = 0;
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] % 2 == 0)
      even_no++;
    else
      odd_no++;
  }
  if (odd_no == n && n % 2 == 0) {
    printf("0");
    return 0;
  }
  if (odd_no % 2 == 1)
    printf("%d", odd_no);
  else
    printf("%d", even_no);
  return 0;
}
