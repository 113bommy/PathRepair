#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n, 1), b(m, 1);
  if (n == 1) {
    a[0] = 1;
  }
  if (n == 2) {
    a[0] = 3;
    a[1] = 4;
  } else {
    if (n % 2 == 0) {
      a[n - 1] = (n - 2) / 2;
    }
    if (n % 2 == 1) {
      a[0] = 2;
      a[n - 1] = (n + 1) / 2;
    }
  }
  if (m == 1) {
    b[0] = 1;
  }
  if (m == 2) {
    b[0] = 3;
    b[1] = 4;
  } else {
    if (m % 2 == 0) {
      b[n - 1] = (n - 2) / 2;
    }
    if (n % 2 == 1) {
      b[0] = 2;
      b[n - 1] = (n + 1) / 2;
    }
  }
  vector<vector<int> > c(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i][j] = a[i] * b[j];
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
