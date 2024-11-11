#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
int n;
int arr[N][N];
int cl(int x, int y) { return (x / 4) * (n / 4) + (y / 4); }
int a[4][4] = {{8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int id = cl(i, j);
      arr[i][j] = a[i % 4][j % 4] + (16 * id);
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
      if (j == n - 1) cout << endl;
    }
}
