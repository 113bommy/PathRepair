#include <bits/stdc++.h>
using namespace std;
int main() {
  int tu[200], a[200];
  int f[200];
  int n, m, k;
  int min;
  int i, j;
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i < m; i++) {
    scanf("%d", &f[i]);
    a[i] = 0;
  }
  for (i = 0; i < k; i++) scanf("%d", &tu[i]);
  for (i = 0; i < m; i++)
    for (j = 0; j < k; j++)
      if (tu[j] % f[i] == 0) a[i] += 1;
  min = 1000;
  for (i = 0; i < m; i++) {
    if (min > a[i]) min = a[i];
  }
  j = 0;
  for (i = 0; i < m; i++) {
    if (a[i] == min) tu[j++] = i;
  }
  for (i = 0; i < j; i++) {
    for (k = i + 1; k < j; k++) {
      if (tu[i] > tu[k]) {
        min = tu[k];
        tu[k] = tu[i];
        tu[i] = min;
      }
    }
  }
  printf("%d\n", j);
  for (i = 0; i < j; i++) printf("%d ", tu[i] + 1);
  printf("\n");
  return 0;
}
