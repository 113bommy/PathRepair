#include <bits/stdc++.h>
int d[109][109];
int a[109];
int n, m;
using namespace std;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int p, q;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &p, &q);
    p--;
    q--;
    d[p][q] = 1;
    d[q][p] = 1;
  }
  int min_val = 2000000000;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int w = j + 1; w < n; w++) {
        if (d[i][j] && d[i][w] && d[j][w]) {
          min_val = min(min_val, a[i] + a[j] + a[w]);
        }
      }
    }
  }
  if (min_val == 2000000000) {
    printf("-1");
    return 0;
  }
  printf("%d", min_val);
}
