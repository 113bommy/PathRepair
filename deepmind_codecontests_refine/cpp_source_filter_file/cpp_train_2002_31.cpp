#include <bits/stdc++.h>
using namespace std;
char board[512][512];
int mat[512][512];
int vet[512];
int n, m, k;
bool ok(int a, int b) {
  if (a < 0) return false;
  if (b < 0) return false;
  if (b >= m) return false;
  if (a >= n) return false;
  return true;
}
bool can(int a, int b) {
  int c = 0;
  if (board[a][b] == '1') c++;
  if (ok(a + 1, b + 1))
    if (board[a + 1][b + 1] == '1') c++;
  if (ok(a + 1, b))
    if (board[a + 1][b] == '1') c++;
  if (ok(a + 1, b - 1))
    if (board[a + 1][b - 1] == '1') c++;
  if (ok(a + 2, b))
    if (board[a + 2][b] == '1') c++;
  return c == 5;
}
int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf(" %s", board[i]);
  for (int i = 0; i < n - 2; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (can(i, j))
        mat[i][j - 1] = 1;
      else
        mat[i][j - 1] = 0;
    }
  }
  long long resp = 0;
  for (int low = 0; low < n - 2; low++) {
    memset(vet, 0, sizeof(vet));
    for (int up = low; up < n - 2; up++) {
      for (int col = 1; col < m - 1; col++) vet[col - 1] += mat[up][col - 1];
      int s = 0;
      int inic = 1;
      for (int col = 1; col < m - 1; col++) {
        s += vet[col - 1];
        if (s >= k) {
          resp += (m - (col + 1));
          s -= vet[inic++];
          s -= vet[col - 1];
          col--;
        }
      }
    }
  }
  cout << resp << endl;
  return 0;
}
