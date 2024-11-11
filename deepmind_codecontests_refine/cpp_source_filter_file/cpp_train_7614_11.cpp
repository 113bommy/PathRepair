#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int MAX = 1001;
int main() {
  int n, m, h;
  cin >> n >> m >> h;
  int r[m];
  for (int i = 0; i < m; i++) {
    cin >> r[i];
  }
  int c[h];
  for (int i = 0; i < h; i++) {
    cin >> c[i];
  }
  int a[h][m];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        a[i][j] = min(r[j], c[i]);
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
