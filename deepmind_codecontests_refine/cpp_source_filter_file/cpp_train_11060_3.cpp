#include <bits/stdc++.h>
int par(int k, int i) {
  if (i < k / 2) {
    return -1;
  } else {
    return 1;
  }
}
void generate(long l) {
  if (l % 4 != 0) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  long k = l / 2, arr[l];
  for (long i = 0; i < k; i++) arr[i] = 2 * i + 2;
  for (long i = k; i < l; i++) arr[i] = arr[i - k] + par(k, i);
  for (long i = 0; i < l; i++) printf("%d ", arr[i]);
  printf("\n");
}
int main() {
  int queries;
  long len;
  scanf("%d\n", &queries);
  for (int i = 0; i < queries; i++) {
    scanf("%ld\n", &len);
    generate(len);
  }
  return 0;
}
