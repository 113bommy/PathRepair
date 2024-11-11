#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  bool a[n][n];
  bool b[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == 'X')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == 'X')
        b[i][j] = 1;
      else
        b[i][j] = 0;
    }
  }
  int x = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == b[i][j])
        x++;
      else
        break;
    }
  }
  if (x == n * n) {
    cout << "Yes";
    return 0;
  }
  x = 0;
  for (int i = 0, k = 0; i < n && k < n; i++, k++) {
    for (int j = 0, l = n - 1; j < n && l >= 0; j++, l--) {
      if (a[i][j] == b[l][k])
        x++;
      else
        break;
    }
  }
  if (x == n * n) {
    cout << "Yes";
    return 0;
  }
  x = 0;
  for (int i = 0, k = n - 1; i < n && k >= 0; i++, k--) {
    for (int j = 0, l = n - 1; j < n && l >= 0; j++, l--) {
      if (a[i][j] == b[k][l])
        x++;
      else
        break;
    }
  }
  if (x == n * n) {
    cout << "Yes";
    return 0;
  }
  x = 0;
  for (int i = 0, k = n - 1; i < n && k >= 0; i++, k--) {
    for (int j = 0, l = 0; j < n && l < n; j++, l++) {
      if (a[i][j] == b[l][k])
        x++;
      else
        break;
    }
  }
  if (x == n * n) {
    cout << "Yes";
    return 0;
  }
  x = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == b[j][i])
        x++;
      else
        break;
    }
  }
  if (x == n * n) {
    cout << "Yes";
    return 0;
  }
  x = 0;
  for (int i = 0, k = 0; i < n && k < n; i++, k++) {
    for (int j = 0, l = n - 1; j < n && l >= 0; j++, l--) {
      if (a[i][j] == b[k][l])
        x++;
      else
        break;
    }
  }
  if (x == n * n) {
    cout << "Yes";
    return 0;
  }
  x = 0;
  for (int i = 0, k = n - 1; i < n && k >= 0; i++, k--) {
    for (int j = 0, l = n - 1; j < n && l >= 0; j++, l--) {
      if (a[i][j] == b[l][k])
        x++;
      else
        break;
    }
  }
  if (x == n * n) {
    cout << "Yes";
    return 0;
  }
  x = 0;
  for (int i = 0, k = n - 1; i < n && k >= 0; i++, k--) {
    for (int j = 0, l = 0; j < n && l < n; j++, l++) {
      if (a[i][j] == b[k][l])
        x++;
      else
        break;
    }
  }
  if (x == n * n) {
    cout << "Yes";
    return 0;
  }
  cout << "No";
  return 0;
  return 0;
}
