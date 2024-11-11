#include <bits/stdc++.h>
using namespace std;
int a[1000][1000], n, k, cur, maxcur;
int main() {
  scanf("%d", &n);
  k = (1 + (int)sqrt(1 + 8 * n)) / 2;
  cur = 1;
  maxcur = k * (k - 1) / 2;
  while (cur <= maxcur) {
    for (int i = 0; i < k - 1; ++i)
      for (int j = 0, h = i; h < k - 1; ++j, ++h) a[j][h] = cur++;
  }
  for (int i = 0; i < k - 1; ++i)
    for (int j = i + 1; j < k; ++j) a[j][i] = a[i][j - 1];
  printf("%d\n", k);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k - 1; ++j) printf("%d ", a[i][j]);
    puts("");
  }
  return 0;
}
