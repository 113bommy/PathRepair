#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
int main() {
  int n;
  cin >> n;
  int a[1005][1005];
  for (lli j = 0; j < (n); j++) {
    for (lli i = 0; i < (6); i++) cin >> a[j][i];
  }
  bool used[10005] = {};
  used[0] = true;
  if (n == 3) {
    int v[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                   {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    for (lli k = 0; k < (6); k++) {
      for (lli j = 0; j < (6); j++) {
        for (lli m = 0; m < (6); m++)
          for (lli l = 0; l < (6); l++) {
            int val = a[v[k][2]][j];
            used[val] = true;
            val = a[v[k][1]][m] * 10 + a[v[k][2]][j];
            used[val] = true;
            val = a[v[k][0]][l] * 100 + a[v[k][1]][m] * 10 + a[v[k][2]][j];
            used[val] = true;
          }
      }
    }
  }
  if (n == 2) {
    int v[2][2] = {{0, 1}, {1, 0}};
    for (lli k = 0; k < (2); k++) {
      for (lli j = 0; j < (2); j++) {
        for (lli m = 0; m < (2); m++) {
          int val = a[v[k][0]][j] * 10 + a[v[k][1]][m];
          used[val] = true;
          val = a[v[k][1]][m];
          used[val] = true;
        }
      }
    }
  }
  if (n == 1) {
    int val = 0;
    for (lli j = 0; j < (6); j++) {
      val = a[0][j];
      used[val] = true;
    }
  }
  int ans = 0;
  for (lli i = 0; i < (10005); i++) {
    if (used[i] == false) {
      ans = i - 1;
      break;
    }
  }
  cout << ans << endl;
}
