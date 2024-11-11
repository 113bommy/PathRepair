#include <bits/stdc++.h>
using namespace std;
int altnum(vector<vector<bool>> &mat, int x1, int y1, int x2, int y2) {
  int k = 0;
  for (int i = y1; i <= y2; i++) {
    for (int j = x1; j <= x2; j++) {
      if (mat[i][j]) k++;
    }
  }
  return k;
}
int main() {
  int r, c, n, k;
  scanf("%d %d %d %d", &r, &c, &n, &k);
  vector<vector<bool>> mat(r, vector<bool>(c));
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    mat[a][b] = 1;
  }
  int ans = 0;
  for (int x1 = 0; x1 < c; x1++) {
    for (int x2 = x1; x2 < c; x2++) {
      for (int y1 = 0; y1 < r; y1++) {
        for (int y2 = y1; y2 < r; y2++) {
          if (altnum(mat, x1, y1, x2, y2) >= k) ans++;
        }
      }
    }
  }
  printf("%d", ans);
}
