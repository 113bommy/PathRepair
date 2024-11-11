#include <bits/stdc++.h>
using namespace std;
int n = 5;
bool a[7][7];
bool solve() {
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = j + 1; k <= n; k++) {
        if (a[i][j] && a[j][k] && a[k][i]) return true;
        if (!a[i][j] && !a[j][k] && !a[k][i]) return true;
      }
  return false;
}
int main() {
  memset(a, false, sizeof(a));
  int m, u, v;
  scanf("%d", &m);
  while (m--) {
    scanf("%d %d", &u, &v);
    a[u][v] = a[v][u] = true;
  }
  if (solve())
    puts("WIN");
  else
    puts("FAIL");
  return 0;
}
