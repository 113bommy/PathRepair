#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, count = 1, i;
  scanf("%d%d", &n, &c);
  int arr[n];
  for (i = 0; i < n; i++) scanf("%d", &arr[i]);
  for (i = 0; i < n; i++) {
    if (arr[i] - arr[i - 1] <= c)
      count++;
    else
      count = 1;
  }
  printf("%d\n", count);
  return 0;
}
