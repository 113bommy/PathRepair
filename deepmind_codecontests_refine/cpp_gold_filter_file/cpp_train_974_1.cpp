#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, j, count = 1;
  int a[100001];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1])
      break;
    else
      count++;
  }
  count = n - count;
  printf("%d\n", count);
  return 0;
}
