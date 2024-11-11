#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k, l, a, b;
  while (scanf("%d%d", &n, &m) == 2) {
    vector<int> v[4444];
    int d[4444] = {}, min = 100000;
    for (i = 1; i <= m; i++) {
      scanf("%d%d", &a, &b);
      v[a].push_back(b);
      v[b].push_back(a);
      d[a]++;
      d[b]++;
    }
    for (i = 1; i <= n; i++)
      for (j = 0; j < d[i]; j++)
        for (k = 0; k < d[i]; k++)
          for (l = 0; l < d[v[i][j]]; l++)
            if (v[v[i][j]][l] == v[i][k]) {
              min = min < d[i] + d[v[i][j]] + d[v[i][k]]
                        ? min
                        : d[i] + d[v[i][j]] + d[v[i][k]];
            }
    if (min == 100000)
      printf("-1\n");
    else
      printf("%d\n", min - 6);
  }
  return 0;
}
