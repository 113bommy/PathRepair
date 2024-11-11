#include <bits/stdc++.h>
using namespace std;
char arr[50][50];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if ((i % 2 == 0 ||
           ((i % 4 == 1 && j == m - 1) || (i % 4 == 3 && j == 0))))
        arr[i][j] = '#';
      else
        arr[i][j] = '.';
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
    cout << "\n";
  }
}
