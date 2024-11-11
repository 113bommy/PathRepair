#include <bits/stdc++.h>
using namespace std;
int x[100][100];
int y[100][100];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> x[i][j];
      y[i][j] = x[i][j];
    }
  for (int i = 0; i < m; i++)
    for (int j = i; j < m; j++) {
      for (int k = 0; k < n; k++) swap(x[k][i], x[k][j]);
      int id1 = i, id2 = j;
      bool bol = 1;
      for (int a = 0; a < n; a++) {
        int add = 0;
        for (int b = 0; b < m; b++) {
          if (x[a][b] != b + 1) {
            add++;
          }
        }
        if (add == 0 || add == 2)
          continue;
        else {
          bol = 0;
          break;
        }
      }
      if (bol == 1) {
        cout << "YES" << endl;
        return 0;
      }
      for (int q = 0; q < n; q++)
        for (int w = 0; w < m; w++) x[q][w] = y[q][w];
    }
  cout << "NO" << endl;
  return 0;
}
