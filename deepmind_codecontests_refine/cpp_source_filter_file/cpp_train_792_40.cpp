#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char** arr = new char*[n];
  for (int i = 0; i < n; i++) arr[i] = new char[m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  string ans = "";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x = arr[i][j];
      bool foundrow = false;
      bool foundcol = false;
      for (int a = 0; a < n && !foundrow; a++) {
        if (a != j && arr[i][a] == x) foundrow = true;
      }
      for (int a = 0; a < n && !foundcol; a++) {
        if (a != i && arr[a][j] == x) foundcol = true;
      }
      if (!foundrow && !foundcol) ans += x;
    }
  }
  cout << ans << endl;
  return 0;
}
