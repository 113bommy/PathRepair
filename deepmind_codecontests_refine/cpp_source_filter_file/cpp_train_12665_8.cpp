#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
char matrix[MAX_N][MAX_N];
int answer[MAX_N][MAX_N] = {0};
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i += 1) scanf("%s", matrix[i]);
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n - k; j += 1) {
      bool possible = true;
      for (int x = j; x < j + k; x += 1) {
        if (matrix[i][x] == '#') possible = false;
      }
      if (possible)
        for (int x = j; x < j + k; x += 1) answer[i][x] += 1;
    }
  }
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n - k; j += 1) {
      bool possible = true;
      for (int x = j; x < j + k; x += 1) {
        if (matrix[x][i] == '#') possible = false;
      }
      if (possible)
        for (int x = j; x < j + k; x += 1) answer[x][i] += 1;
    }
  }
  int maxx = 0, row = 0, coll = 0;
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      if (answer[i][j] > maxx) {
        maxx = answer[i][j];
        row = i + 1;
        coll = j + 1;
      }
    }
  }
  printf("%d %d", row, coll);
  return 0;
}
