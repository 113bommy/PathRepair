#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, ans = 100009, ind;
int c[10][10], a[10];
int main() {
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      char cc;
      cin >> cc;
      c[i][j] = cc - 48;
    }
  }
  for (i = 1; i <= k; i++) a[i] = i;
  do {
    int p[10][10];
    int mini = 100009, maxi = -1;
    for (i = 0; i < n; i++)
      for (j = 0; j < k; j++) p[i][j] = c[i][a[j]];
    for (i = 0; i < n; i++) {
      int v = 0;
      for (j = 0; j < k; j++) {
        v = v * 10 + p[i][j];
      }
      mini = min(mini, v);
      maxi = max(maxi, v);
    }
    ans = min(ans, maxi - mini);
  } while (next_permutation(a, a + k));
  printf("%d", ans);
}
