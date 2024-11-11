#include <bits/stdc++.h>
using namespace std;
int c[100];
int main() {
  int m, n, a[100][100];
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int mx = -3, r;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] > mx) {
        mx = a[i][j];
        r = j;
      }
    }
    c[r]++;
    mx = -3;
  }
  for (int j = 0; j < n; j++) {
    if (c[j] > mx) {
      mx = c[j];
      r = j;
    }
  }
  cout << r + 1 << endl;
  return 0;
}
