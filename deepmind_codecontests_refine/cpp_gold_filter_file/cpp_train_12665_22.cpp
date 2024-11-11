#include <bits/stdc++.h>
using namespace std;
const long long inff = 0x3f3f3f3f3f3f3f3f;
string a[108];
int b[108][108];
int main() {
  cin.tie(0);
  int n, k, s = 0, x = 1, y = 1, z = 1;
  cin >> n >> k;
  for (int i(1); i <= (n); ++i) cin >> a[i];
  for (int i(1); i <= (n); ++i) {
    for (int j(0); j <= (n - 1); ++j) {
      z = 1;
      if (j + k - 1 < n) {
        for (int q(j); q <= (j + k - 1); ++q) {
          if (a[i][q] == '#') {
            z = 0;
            break;
          }
        }
        if (z) {
          for (int q(j); q <= (j + k - 1); ++q) {
            b[i][q + 1]++;
          }
        }
      }
      z = 1;
      if (i + k - 1 <= n) {
        for (int q(i); q <= (i + k - 1); ++q) {
          if (a[q][j] == '#') {
            z = 0;
            break;
          }
        }
        if (z) {
          for (int q(i); q <= (i + k - 1); ++q) {
            b[q][j + 1]++;
          }
        }
      }
    }
  }
  for (int i(1); i <= (n); ++i) {
    for (int j(1); j <= (n); ++j) {
      if (b[i][j] > s) {
        s = b[i][j];
        x = i;
        y = j;
      }
    }
  }
  cout << x << " " << y << endl;
  return 0;
}
