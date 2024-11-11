#include <bits/stdc++.h>
using namespace std;
int n, Q;
int a[300000 + 10];
int Jump[300000 + 10][20];
int Next[20][20];
bool Find(int x, int y) {
  for (int i = 0; i < 20; i++)
    if ((a[y] & (1 << i)) && Jump[x][i] <= y) return true;
  return false;
}
int main() {
  scanf("%d%d", &n, &Q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 20; j++) Jump[i][j] = n + 1;
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 20; j++) Next[i][j] = n + 1;
  for (int i = n; i; i--) {
    for (int j = 0; j < 20; j++)
      for (int k = 0; k < 20; k++)
        if ((a[i] & (1 << j)) && (a[i] & (1 << k))) Next[j][k] = i;
    for (int j = 0; j < 20; j++) {
      if (!(a[i] & (1 << j))) continue;
      for (int k = 0; k < 20; k++) Jump[i][j] = min(Jump[i][j], Next[k][j]);
    }
    for (int j = 0; j < 20; j++)
      for (int k = 0; k < 20; k++)
        Jump[i][j] = min(Jump[i][j], Jump[Jump[i][k]][j]);
  }
  int x, y;
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d", &x, &y);
    if (Find(x, y))
      printf("Shi\n");
    else
      printf("Fou\n");
  }
  return 0;
}
