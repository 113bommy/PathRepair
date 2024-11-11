#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, e;
  cin >> n;
  int a1[n][n];
  long long int s = 0;
  e = ((n - 1) / 2) + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a1[i][j];
      if (n == 1) {
        cout << a1[i][j] << endl;
        return 0;
      }
      if (i == j) {
        if (i != e && j != e) {
          s += a1[i][j];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != e) {
      s += a1[e][i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != e) {
      s += a1[i][e];
    }
    s += a1[i][n - i + 1];
  }
  cout << s << endl;
  return 0;
}
