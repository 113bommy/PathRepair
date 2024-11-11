#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char> > ar(n, vector<char>(m, '.'));
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < m; j++) ar[i][j] = '#';
  }
  for (int i = 1; i < n; i += 3) {
    ar[i][m - 1] = '#';
  }
  for (int i = 3; i < n; i += 3) {
    ar[i][0] = '#';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ar[i][j];
    }
    cout << endl;
  }
}
