#include <bits/stdc++.h>
using namespace std;
int f = 0;
char a[20][20], b[20][20];
void duizhe(int n) {
  int c[20][20], i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = a[n - i - 1][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = c[i][j];
    }
  }
}
void find(int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] != b[i][j]) {
        i = n;
        break;
      }
      if (i == n - 1 && j == n - 1) {
        cout << "Yes";
        f = 1;
        return;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[n - j - 1][i] != b[i][j]) {
        i = n;
        break;
      }
      if (i == n - 1 && j == n - 1) {
        cout << "Yes";
        f = 1;
        return;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[j][n - i - 1] != b[i][j]) {
        i = n;
        break;
      }
      if (i == n - 1 && j == n - 1) {
        cout << "Yes";
        f = 1;
        return;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[n - 1 - i][n - 1 - j] != b[i][j]) {
        i = n;
        break;
      }
      if (i == n - 1 && j == n - 1) {
        cout << "Yes";
        f = 1;
        return;
      }
    }
  }
}
int main() {
  int i, n, j;
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> b[i][j];
    }
  }
  find(n);
  if (f) return 0;
  duizhe(n);
  find(n);
  if (!f) cout << "No";
  return 0;
}
