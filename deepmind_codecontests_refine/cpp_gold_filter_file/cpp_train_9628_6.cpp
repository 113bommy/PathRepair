#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  int n, k, c = 0, tr;
  char cell[1005][1005];
  cin >> n >> k;
  tr = k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cell[i][j] = '.';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (cell[i][j] == '.' && k > 0) {
        k--;
        cell[i][j] = 'L';
        c++;
        cell[i - 1][j] = 'S', cell[i + 1][j] = 'S', cell[i][j + 1] = 'S',
                 cell[i][j - 1] = 'S';
      } else {
        cell[i][j] = 'S';
      }
    }
  }
  if (c >= tr) {
    cout << "YES"
         << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << cell[i][j];
      }
      cout << "\n";
    }
  } else {
    cout << "NO"
         << "\n";
  }
}
