#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[11][11] = {0};
  for (int i = 0; i < n; i++) {
    a[i][0] = 1;
    a[0][i] = 1;
  }
  int maxx = 0;
  for (int j = 1; j < n; j++)
    for (int i = 1; i < n; i++) {
      a[i][j] = a[i - 1][j] + a[i][j - 1];
      if (a[i][j] > maxx) maxx = a[i][j];
    }
  cout << maxx;
  return 0;
}
