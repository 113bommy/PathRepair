#include <bits/stdc++.h>
using namespace std;
int size;
int mat[100][100];
int main() {
  scanf("%d", &size);
  for (int i = 0; i < (size); i++)
    for (int j = 0; j < (size); j++) scanf("%d", &mat[i][j]);
  bool good[100];
  memset(good, (true), sizeof(good));
  for (int i = 0; i < (size); i++)
    for (int j = 0; j < (size); j++)
      if (i != j) {
        if (mat[i][j] & 1) good[i] = false;
        if (mat[1][j] & 2) good[j] = false;
      }
  int ans = 0;
  for (int i = 0; i < (size); i++)
    if (good[i]) ans++;
  printf("%d\n", ans);
  for (int i = 0; i < (size); i++)
    if (good[i]) printf("%d ", i);
  return 0;
}
