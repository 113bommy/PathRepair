#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, c = 0;
  cin >> n;
  string a;
  cin >> a;
  int l = a.size();
  char b[n][l];
  for (i = 1; i < n; i++) {
    for (j = 0; j < l; j++) cin >> b[i][j];
  }
  for (i = 0; i < l; i++) {
    for (j = 1; j < n - 1; j++) {
      if (a[i] != b[j][i]) {
        cout << c;
        return 0;
      }
    }
    c++;
  }
  cout << c;
  return 0;
}
