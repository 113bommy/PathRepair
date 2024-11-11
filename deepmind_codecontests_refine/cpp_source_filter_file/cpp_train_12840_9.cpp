#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k, l, arr[100009] = {};
  scanf("%d", &n);
  m = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    m += arr[i];
  }
  if (m % 2 == 1)
    printf("0");
  else {
    k = m / 2;
    j = 0;
    m = 0;
    for (i = 0; i < n; i++) {
      m += arr[i];
      if (m == k && i < n - 1) j++;
    }
    printf("%d", j);
  }
}
