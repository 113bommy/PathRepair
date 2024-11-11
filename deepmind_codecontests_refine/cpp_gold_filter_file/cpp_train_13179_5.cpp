#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, arr[100][100], l, m, n, x, coun, sum, ans, T, check;
  char str[100];
  vector<long long> v;
  string s;
  cin >> n;
  long long xx[] = {1, 0, -1, 0};
  long long zz[] = {0, -1, 0, 1};
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) cin >> arr[i][j];
  check = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      x = arr[i][j];
      if (x == 1) continue;
      for (k = 0; k < n; k++) {
        if (k == i) continue;
        for (l = 0; l < n; l++) {
          if (l == j) continue;
          if (x == arr[i][l] + arr[k][j]) {
            check = 1;
            break;
          }
          check = 0;
        }
        if (check == 1) break;
      }
      if (check == 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
