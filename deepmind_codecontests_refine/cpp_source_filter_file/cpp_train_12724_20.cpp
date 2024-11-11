#include <bits/stdc++.h>
using namespace std;
int m[100100];
int main() {
  int i, j, k, n;
  for (scanf("%d", &n), i = 0; i < n; scanf("%d", &m[i]), i++)
    ;
  if (n % 2)
    printf("NO\n");
  else {
    sort(m, m + n);
    for (j = 0; j < n && m[j] == m[0]; j++)
      ;
    if (j == n)
      printf("NO\n");
    else {
      for (i = 1; i < n; i++)
        if (m[i] - m[i - 1] > 1) {
          printf("NO\n");
          return 0;
        }
      for (i = j, k = j; i < n; i += j) {
        for (j = 0; i + j < n && m[i] == m[i + j]; j++)
          ;
        if (i + j == n) {
          if (j != k)
            printf("NO\n");
          else
            printf("YES\n");
        } else if (j < k) {
          printf("NO\n");
          return 0;
        } else
          k = j - k;
      }
    }
  }
  return 0;
}
