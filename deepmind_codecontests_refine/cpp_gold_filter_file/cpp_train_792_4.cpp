#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char arr1[n][m];
  char arr2[m][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char a;
      cin >> a;
      arr1[i][j] = a;
      arr2[j][i] = a;
    }
  }
  string ans = "";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (count(arr1[i], arr1[i] + m, arr1[i][j]) == 1 &&
          count(arr2[j], arr2[j] + n, arr1[i][j]) == 1) {
        ans += string(1, arr1[i][j]);
      }
    }
  }
  cout << ans;
}
