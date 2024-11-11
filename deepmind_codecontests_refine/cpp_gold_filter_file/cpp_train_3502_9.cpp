#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a[n][2];
  string b[m][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> b[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    cout << b[i][0] << " " << b[i][1] << " #";
    string c = "";
    for (int k = 0; k < b[i][1].size() - 1; k++) {
      c += b[i][1][k];
    }
    for (int j = 0; j < n; j++) {
      if (c == a[j][1]) {
        cout << a[j][0] << endl;
        break;
      }
    }
  }
  return 0;
}
