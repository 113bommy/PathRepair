#include <bits/stdc++.h>
using namespace std;
int n, m, **a;
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  cin >> n >> m;
  a = new int*[n];
  for (int i = 0; i < n; ++i) {
    a[i] = new int[m];
    for (int j = 0; j < m; ++j) {
      a[i][j] = i * m + j + 1;
    }
  }
  int N = min(n, m), M = max(n, m);
  if (N == 1) {
    if (M == 1) {
      cout << "YES" << endl << a[0][0];
    } else if (M == 2 || M == 3) {
      cout << "NO";
    } else if (M == 4) {
      cout << "YES" << endl;
      if (n < m) {
        cout << a[0][1] << " " << a[0][3] << " " << a[0][0] << " " << a[0][2];
      } else {
        cout << a[1][0] << endl
             << a[3][0] << endl
             << a[0][0] << endl
             << a[2][0];
      }
    } else {
      cout << "YES" << endl;
      if (n < m) {
        for (int i = 1; i < m; i += 2) {
          cout << a[0][i] << " ";
        }
        for (int i = 0; i < m; i += 2) {
          cout << a[0][i] << " ";
        }
      } else {
        for (int i = 1; i < n; i += 2) {
          cout << a[i][0] << " ";
        }
        for (int i = 0; i < n; i += 2) {
          cout << a[i][0] << " ";
        }
      }
    }
  } else if (N == 2 && (M == 2 || M == 3)) {
    cout << "NO";
  } else if (N == 3 && M == 3) {
    cout << "YES" << endl
         << a[1][2] << " " << a[0][0] << " " << a[2][1] << endl
         << a[2][0] << " " << a[1][1] << " " << a[0][2] << endl
         << a[0][1] << " " << a[2][2] << " " << a[1][0] << endl;
  } else {
    if (n < m) {
      for (int i = 1; i < n; i += 2) {
        int t0 = a[i][0], t1 = a[i][1];
        for (int j = 0; j < m - 2; ++j) {
          a[i][j] = a[i][j + 2];
        }
        a[i][m - 2] = t0;
        a[i][m - 1] = t1;
      }
      for (int j = 1; j < m; j += 2) {
        int t0 = a[0][j];
        for (int i = 0; i < n - 1; ++i) {
          a[i][j] = a[i + 1][j];
        }
        a[n - 1][j] = t0;
      }
    } else {
      for (int i = 1; i < n; i += 2) {
        int t0 = a[0][i], t1 = a[1][i];
        for (int j = 0; j < m - 2; ++j) {
          a[j][i] = a[j + 2][i];
        }
        a[m - 2][i] = t0;
        a[m - 1][i] = t1;
      }
      for (int j = 1; j < m; j += 2) {
        int t0 = a[j][0];
        for (int i = 0; i < n - 1; ++i) {
          a[j][i] = a[j][i + 1];
        }
        a[j][n - 1] = t0;
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }
  for (int i = 0; i < n; ++i) delete[] a[i];
  delete[] a;
  getchar();
  getchar();
  return 0;
}
