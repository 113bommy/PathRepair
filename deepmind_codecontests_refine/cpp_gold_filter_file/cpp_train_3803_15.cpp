#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m, q;
struct node {
  int r, c;
};
node arr[N][N], temp[N];
int out[N][N];
void shiftRow(int ind) {
  for (int i = 0; i < m; i++) temp[i] = arr[ind][(i + 1) % m];
  for (int i = 0; i < m; i++) arr[ind][i] = temp[i];
}
void shiftCol(int ind) {
  for (int i = 0; i < n; i++) temp[i] = arr[(i + 1) % n][ind];
  for (int i = 0; i < n; i++) arr[i][ind] = temp[i];
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) arr[i][j].r = i, arr[i][j].c = j;
  }
  int row, col, v, op;
  while (q--) {
    scanf("%d", &op);
    if (op == 1)
      scanf("%d", &row), shiftRow(--row);
    else if (op == 2)
      scanf("%d", &col), shiftCol(--col);
    else {
      scanf("%d%d%d", &row, &col, &v);
      row--, col--;
      out[arr[row][col].r][arr[row][col].c] = v;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d ", out[i][j]);
    puts("");
  }
}
