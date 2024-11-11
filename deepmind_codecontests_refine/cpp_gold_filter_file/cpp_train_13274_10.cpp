#include <bits/stdc++.h>
using namespace std;
int a[600][600];
void consruct(int k) {
  int i, j;
  for (i = k; i < 2 * k; i++) {
    for (j = 0; j < k; j++) a[i][j] = a[i - k][j];
  }
  for (i = 0; i < k; i++) {
    for (j = k; j < 2 * k; j++) a[i][j] = a[i][j - k];
  }
  for (i = k; i < 2 * k; i++) {
    for (j = k; j < 2 * k; j++) a[i][j] = -a[i - k][j - k];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int k, ans, i, j;
  cin >> k;
  ans = 2;
  a[0][0] = 1;
  a[0][1] = 1;
  a[1][0] = 1;
  a[1][1] = -1;
  if (k == 0)
    cout << "+" << endl;
  else {
    for (i = 1; i < k; i++) {
      consruct(ans);
      ans = ans * 2;
    }
    for (i = 0; i < ans; i++) {
      for (j = 0; j < ans; j++) {
        if (a[i][j] == 1)
          cout << "+";
        else
          cout << "*";
      }
      cout << endl;
    }
  }
}
