#include <bits/stdc++.h>
using namespace std;
int k;
int mat[1024][1024];
void preenche(int x) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      mat[i][j + x] = mat[i][j];
      mat[i + x][j] = mat[i][j];
      mat[i + x][j + x] = -mat[i][j];
    }
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> k;
  mat[0][0] = 1;
  for (int i = 0; i < k; i++) {
    preenche(1 << i);
  }
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j < (1 << k); j++) {
      if (mat[i][j] == 1)
        cout << "+";
      else
        cout << "-";
    }
    cout << endl;
  }
  return 0;
}
