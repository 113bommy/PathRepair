#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  m *= 2;
  n *= 2;
  char ar[250][250];
  for (int i = 0; i < m; i += 2) {
    for (int j = 0; j < n; j += 2) {
      cin >> ar[i][j];
      ar[i + 1][j] = ar[i][j];
      ar[i + 1][j + 1] = ar[i][j];
      ar[i][j + 1] = ar[i][j];
    }
  }
  char arr[250][250];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ar[j][i];
    }
    cout << endl;
  }
  return 0;
}
