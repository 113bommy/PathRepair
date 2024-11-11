#include <bits/stdc++.h>
int main() {
  int n, m, i, j, b = 0;
  scanf("%d %d", &n, &m);
  int pass[n];
  int finger[m];
  int print[m];
  for (i = 0; i < n; i++) {
    scanf("%d", &pass[i]);
  }
  for (i = 0; i < m; i++) {
    scanf("%d", &finger[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (pass[i] == finger[j]) {
        print[b] = pass[i];
        b++;
      }
    }
  }
  for (i = 0; i < b; i++) {
    printf("%d", print[i]);
  }
  return 0;
}
