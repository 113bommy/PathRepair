#include <bits/stdc++.h>
using namespace std;
int G[15][15] = {0};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &G[i][j]);
    }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        G[i][j] = (G[i][k] + G[k][j] < G[i][j]) ? (G[i][k] + G[k][j]) : G[i][j];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ans = max(G[i][j], ans);
  printf("%d\n", ans);
  return 0;
}
