#include <bits/stdc++.h>
using namespace std;
int n, ar[305];
bool adjlist[305][305];
char st[305][305];
int main() {
  scanf("%d", &n);
  for (int x = 0; x < n; x++) scanf("%d", &ar[x]);
  for (int x = 0; x < n; x++) scanf("%s", st[x]);
  for (int x = 0; x < n; x++)
    for (int y = 0; y < n; y++)
      if (st[x][y] == '0')
        adjlist[x][y] = 0;
      else
        adjlist[x][y] = 1;
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        adjlist[i][j] = (adjlist[i][j] | (adjlist[i][k] & adjlist[k][j]));
  for (int x = 0; x < n; x++) {
    int tujuan = x;
    for (int y = x; y < n; y++)
      if (adjlist[x][y] && ar[tujuan] > ar[y]) tujuan = y;
    swap(ar[x], ar[tujuan]);
  }
  for (int x = 0; x < n; x++) {
    printf("%d", ar[x]);
    if (x == n - 1)
      printf("\n");
    else
      printf(" ");
  }
  return 0;
}
