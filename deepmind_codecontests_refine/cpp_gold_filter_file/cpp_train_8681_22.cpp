#include <bits/stdc++.h>
using namespace std;
int n;
char sc[102][102];
vector<int> row[102], col[102];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", sc[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (sc[i][j] == '.') {
        row[i].push_back(j);
      }
      if (sc[j][i] == '.') {
        col[i].push_back(j);
      }
    }
  }
  bool ya = 1;
  for (int i = 0; i < n; i++) {
    if (row[i].size() == 0) {
      ya = 0;
    }
  }
  if (ya) {
    for (int i = 0; i < n; i++) {
      printf("%d %d\n", i + 1, row[i][0] + 1);
    }
    return 0;
  }
  ya = 1;
  for (int i = 0; i < n; i++) {
    if (col[i].size() == 0) {
      ya = 0;
    }
  }
  if (ya) {
    for (int i = 0; i < n; i++) {
      printf("%d %d\n", col[i][0] + 1, i + 1);
    }
    return 0;
  }
  printf("-1\n");
  return 0;
}
