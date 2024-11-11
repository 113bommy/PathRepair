#include <bits/stdc++.h>
long int pos_count[100001], neg_count[100001];
int main() {
  long int n, count = 0, i;
  scanf("%ld", &n);
  long int arr[n];
  for (i = 0; i < n; i++) {
    scanf("%ld", &arr[i]);
    if (arr[i] > 0)
      pos_count[arr[i]]++;
    else if (arr[i] < 0)
      neg_count[-arr[i]]++;
  }
  for (i = 0; i < 100001; i++) {
    if (pos_count[i] > 0) count++;
    if (neg_count[i] > 0) count++;
  }
  printf("%ld\n", count);
  return 0;
}
