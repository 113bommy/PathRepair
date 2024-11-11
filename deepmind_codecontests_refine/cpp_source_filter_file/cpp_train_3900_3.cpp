#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n][n], primary[n][n], second[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
      int x = i, y = 0;
      primary[x][y] = 0;
      while (x < n && y < n) {
        primary[i][0] += a[x][y];
        x++, y++;
      }
      x = i + 1, y = 1;
      while (x < n && y < n) {
        primary[x][y] = primary[x - 1][y - 1];
        x++, y++;
      }
    }
    for (int i = 1; i < n; i++) {
      int x = 0, y = i;
      primary[x][y] = 0;
      while (x < n && y < n) {
        primary[0][i] += a[x][y];
        x++, y++;
      }
      x = 1, y = i + 1;
      while (x < n && y < n) {
        primary[x][y] = primary[x - 1][y - 1];
        x++, y++;
      }
    }
    for (int i = 0; i < n; i++) {
      int x = i, y = 0;
      second[x][y] = 0;
      while (x >= 0 && y < n) {
        second[i][0] += a[x][y];
        x--, y++;
      }
      x = i - 1, y = 1;
      while (x >= 0 && y < n) {
        second[x][y] = second[x + 1][y - 1];
        x--, y++;
      }
    }
    for (int i = 1; i < n; i++) {
      int x = n - 1, y = i;
      second[x][y] = 0;
      while (x >= 0 && y < n) {
        second[n - 1][y] += a[x][y];
        x--, y++;
      }
      x = n - 2, y = i + 1;
      while (x >= 0 && y < n) {
        second[x][y] = second[x + 1][y - 1];
        x--, y++;
      }
    }
    long long even = 0, odd = 0, ex = 1, ey = 1, ox = 1, oy = 2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i + j) % 2 == 0) {
          if (primary[i][j] + second[i][j] - a[i][j] > even) {
            even = primary[i][j] + second[i][j] - a[i][j];
            ex = i + 1, ey = j + 1;
          }
        } else {
          if (primary[i][j] + second[i][j] - a[i][j] > odd) {
            odd = primary[i][j] + second[i][j] - a[i][j];
            ox = i + 1, oy = j + 1;
          }
        }
      }
    }
    cout << odd + even << "\n";
    cout << ex << " " << ey << " " << ox << " " << oy << "\n";
  }
  return 0;
}
