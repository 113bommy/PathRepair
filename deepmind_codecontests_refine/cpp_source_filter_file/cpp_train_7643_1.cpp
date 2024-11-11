#include <bits/stdc++.h>
using namespace std;
int n, m, w;
int A[2005][2005];
int v[2005], group[2005], T[2005];
int gp;
void DFS(int x, int y) {
  v[x] = 1;
  for (int i = (0); i < (n); i++)
    if (A[x][i] > 0 && v[i] == 0) DFS(i, y);
  if (y == 0)
    T[w++] = x;
  else
    group[x] = gp;
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (n); j++) scanf("%d", &A[i][j]);
  memset(v, 0, sizeof(v));
  for (int i = (0); i < (n); i++)
    if (!v[i]) DFS(0, 0);
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (n); j++)
      if (i < j) swap(A[i][j], A[j][i]);
  memset(v, 0, sizeof(v));
  for (int i = (n - 1); i >= (0); i--)
    if (!v[T[i]]) {
      gp++;
      DFS(0, 1);
    }
  int ok = 1;
  for (int i = (0); i < (n); i++)
    if (group[i] != group[0]) ok = 0;
  if (ok)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
