#include <bits/stdc++.h>
using namespace std;
int B[1000 * 1001];
const int base = 1000 * 1000 + 3;
int main() {
  int n, m;
  int r = 1;
  bool ok = true;
  cin >> n >> m;
  string A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++) {
    bool empty = true;
    for (int j = 0; j < m; j++) empty &= A[i][j] == '.';
    if (empty) {
      r = (r * 2) % base;
      continue;
    }
    B[0] = 0;
    B[m + 1] = 0;
    for (int j = 0; j < m; j++) {
      if (A[i][j] == '.') B[j + 1] = 0;
      if (A[i][j] == '1' || A[i][j] == '2') B[j + 1] = 1;
      if (A[i][j] == '3' || A[i][j] == '4') B[j + 1] = -1;
    }
    for (int j = 1; j < m; j++)
      if (B[j] == -1 && B[j + 1] == 1) B[j] = B[j + 1] = 2;
    for (int j = 1; j <= m; j++)
      if (B[j] == 1 && B[j - 1] == 0) B[j] = B[j - 1] = 2;
    for (int j = 1; j <= m; j++)
      if (B[j] == -1 && B[j + 1] == 0) B[j] = B[j - 1] = 2;
    int c = -1000 * 1000;
    B[m + 1] = 2;
    for (int j = 1; j <= m; j++) {
      if (B[j] != 0 && B[j] != 2) ok = false;
      if (B[j] == 0) c++;
      if (B[j] == 2) {
        if (c > 0 && c % 2) ok = false;
        c = 0;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    bool empty = true;
    for (int j = 0; j < n; j++) empty &= A[j][i] == '.';
    if (empty) {
      r = (r * 2) % base;
      continue;
    }
    B[0] = 0;
    B[n + 1] = 0;
    for (int j = 0; j < n; j++) {
      if (A[j][i] == '.') B[j + 1] = 0;
      if (A[j][i] == '1' || A[j][i] == '4') B[j + 1] = 1;
      if (A[j][i] == '3' || A[j][i] == '2') B[j + 1] = -1;
    }
    for (int j = 1; j < n; j++)
      if (B[j] == -1 && B[j + 1] == 1) B[j] = B[j + 1] = 2;
    for (int j = 1; j <= n; j++)
      if (B[j] == 1 && B[j - 1] == 0) B[j] = B[j - 1] = 2;
    for (int j = 1; j <= n; j++)
      if (B[j] == -1 && B[j + 1] == 0) B[j] = B[j - 1] = 2;
    int c = -1000 * 1000;
    B[n + 1] = 2;
    for (int j = 1; j <= n; j++) {
      if (B[j] != 0 && B[j] != 2) ok = false;
      if (B[j] == 0) c++;
      if (B[j] == 2) {
        if (c > 0 && c % 2) ok = false;
        c = 0;
      }
    }
  }
  cout << (ok ? r : 0) << endl;
}
