#include <bits/stdc++.h>
using namespace std;
int a[10][4];
int id[10];
int power[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int main() {
  int n, k, i, j, x;
  scanf("%d%d", &n, &k);
  for (i = 0; i < k; i++) id[i] = i;
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    for (j = 0; j < k; j++) {
      a[i][k - j - 1] = x % 10;
      x /= 10;
    }
  }
  int maxc, minc;
  int ans = 999999999;
  do {
    minc = 999999999;
    maxc = 0;
    for (i = 0; i < n; i++) {
      int temp = 0;
      for (j = 0; j < k; j++) {
        temp += (power[id[j]] * a[i][j]);
      }
      minc = min(temp, minc);
      maxc = max(temp, maxc);
    }
    ans = min(ans, maxc - minc);
  } while (next_permutation(id, id + k));
  printf("%d\n", ans);
  return 0;
}
