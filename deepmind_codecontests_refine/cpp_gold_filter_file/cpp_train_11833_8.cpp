#include <bits/stdc++.h>
using namespace std;
int n;
char a[256][256], b[256][256];
char c[256][256];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
    }
  }
  for (int times = 0; times < 4; times++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) c[j][n - i - 1] = a[i][j];
    bool same = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] != b[i][j]) {
          same = false;
          break;
        }
      }
      if (!same) {
        break;
      }
    }
    if (same) {
      cout << "Yes" << endl;
      return 0;
    }
    same = true;
    char aa[256][256], bb[256][256];
    bool same_aa = true, same_bb = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        aa[i][j] = a[i][n - j - 1];
        if (aa[i][j] != b[i][j]) {
          same_aa = false;
        }
        bb[i][j] = a[n - i - 1][j];
        if ((bb[i][j] != b[i][j])) {
          same_bb = false;
        }
      }
    }
    if ((same_aa || same_bb)) {
      cout << "Yes" << endl;
      return 0;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) a[i][j] = c[i][j];
  }
  cout << "No" << endl;
  return 0;
}
