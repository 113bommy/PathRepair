#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, gold = 1000000;
  cin >> n >> m;
  bool a[n][n], x = false;
  ;
  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) a[i][j] = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    a[--u][--v] = 1;
    a[v][u] = 1;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        if (a[i][j] && a[k][j] && a[i][k]) {
          gold = min(gold, A[i] + A[j] + A[k]);
          x = true;
        }
  cout << (x ? gold : -1);
  return 0;
}
