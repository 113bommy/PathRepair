#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  int n, rot = 0;
  char a[11][11], b[11][11], z[11][11];
  bool fine = true;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> z[i][j];
  while (rot < 4) {
    fine = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] != z[i][j]) fine = false;
    if (fine == true) {
      cout << "Yes";
      return 0;
    }
    fine = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] != z[i][n - 1 - j]) fine = false;
    if (fine == true) {
      cout << "Yes";
      return 0;
    }
    fine = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] != z[n - 1 - i][j]) fine = false;
    if (fine == true) {
      cout << "Yes";
      return 0;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) b[i][j] = z[j][n - 1 - i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) z[i][j] = b[i][j];
    rot++;
  }
  cout << "No";
  return 0;
}
