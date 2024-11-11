#include <bits/stdc++.h>
using namespace std;
int tab[100][200];
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  for (int k = 0; k < n; k++)
    for (int l = 0; l < 2 * m; l++) {
      cin >> tab[k][l];
    }
  int s = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m - 1; j += 2) {
      if ((tab[i][j] == 1) || (tab[i][j + 1] == 1)) s += 1;
    }
  }
  cout << s;
  return 0;
}
