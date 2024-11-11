#include <bits/stdc++.h>
using namespace std;
char mat[2020][2020], jav[2020][2020];
int n, a, b, mx[] = {0, 0, 1, 1, 1, -1, -1, -1},
             my[] = {1, -1, 1, 0, -1, 1, 0, -1};
void dfs(int i, int j) {
  if (i >= n || j >= n || i < 0 || j < 0 || jav[i][j] || !mat[i][j]) return;
  jav[i][j] = 1;
  for (int(k) = (0); (k) < (8); (k)++) dfs(i + mx[k], j + my[k]);
}
int main() {
  scanf("%d", &n);
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (n); (j)++)
      scanf(" %c", &mat[i][j]), mat[i][j] = mat[i][j] - '0';
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (n); (j)++)
      if (mat[i][j] && !jav[i][j]) {
        int k = j;
        while (k + 1 < n && mat[i][k + 1]) k++;
        if (k - j + 1 >= 15)
          a++, dfs(i, j);
        else
          b++, dfs(i, j);
      }
  printf("%d %d\n", b, a);
}
