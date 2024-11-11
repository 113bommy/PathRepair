#include <bits/stdc++.h>
using namespace std;
int a[100][200], dem;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        dem++;
        if (a[i][j] == 1 && a[i][j - 1] == 1 && j / 2 == (j - 1) / 2) {
          dem--;
        }
      }
    }
  }
  cout << dem;
  return 0;
}
