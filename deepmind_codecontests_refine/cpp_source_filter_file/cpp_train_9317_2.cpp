#include <bits/stdc++.h>
int arr[1000001];
void like_seive() {
  int i, j;
  for (i = 0; i <= 1000001; i++) arr[i] = 1;
  for (i = 2; i < 10000; i++) {
    for (j = i + i; j <= 1000001; j += i) arr[j] = i;
  }
  arr[1] = 0;
}
int main() {
  like_seive();
  int n, i;
  scanf("%d", &n);
  printf("%d", n);
  i = n;
  while (i != 1) {
    printf(" %d", arr[i]);
    i = arr[i];
  }
  return 0;
}
