#include <bits/stdc++.h>
int n, m;
int r[100 + 5], c[100 + 5];
void make_table(int table[], int n) {
  if (n == 1)
    table[1] = 1;
  else if (n == 2) {
    table[1] = 3;
    table[2] = 4;
  } else {
    table[1] = n - 2;
    for (int i = 2; i <= n; i++) table[i] = 2;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  make_table(r, n);
  make_table(c, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", r[i] * c[j]);
    }
    printf("\n");
  }
  return 0;
}
